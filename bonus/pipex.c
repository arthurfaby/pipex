/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:31:56 by afaby             #+#    #+#             */
/*   Updated: 2022/11/25 15:37:48 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
		#include <stdio.h>

char	*get_path( char *cmd, char *envp[] )
{
	int		i;
	char	*line;
	char	*tmp;
	char	**path;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	envp[i] += 5;
	path = ft_split(envp[i], ':');
	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		line = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!access(line, F_OK | X_OK))
			return (line);
		free(line);
		i++;
	}
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": command not found\n", 2);
	return (NULL);
}

char	**get_cmd( char *arg, char *envp[] )
{
	char	**res;
	char	*cmd;

	res = ft_split(arg, ' ');
	cmd = get_path(res[0], envp);
	free(res[0]);
	res[0] = ft_strdup(cmd);
	free(cmd);
	return (res);
}

void	first_child( int pipefd[2], int fdin, char *argv[], char *envp[] )
{
	char	**cmd;

	if (fdin == -1)
		exit(1);
	dup2(fdin, 0);
	close(fdin);
	close(pipefd[0]);
	dup2(pipefd[1], 1);
	close(pipefd[1]);
	cmd = get_cmd(argv[2], envp);
	if (execve(cmd[0], cmd, envp) < 0)
	{
		perror(strerror(errno));
		exit(5);
	}
}

void	mid_child( int pipe_before[2], int pipe_after[2], char *arg, char *envp[] )
{
	char	**cmd;

	close(pipe_before[1]);
	dup2(pipe_before[0], 0);
	close(pipe_before[0]);
	close(pipe_after[0]);
	dup2(pipe_after[1], 1);
	close(pipe_after[1]);
	cmd = get_cmd(arg, envp);
	if (execve(cmd[0], cmd, envp) < 0)
	{
		perror(strerror(errno));
		exit(6);
	}
}

void	last_child( int pipefd[2], int fdout, char *arg, char *envp[] )
{
	char	**cmd;

	dup2(fdout, 1);
	close(fdout);
	close(pipefd[1]);
	dup2(pipefd[0], 0);
	cmd = get_cmd(arg, envp);
	if (execve(cmd[0], cmd, envp) < 0)
	{
		perror(strerror(errno));
		exit(5);
	}
}



int	forking( int pipe_before[2], int pipe_after[2], char *argv[], char *envp[], int argc )
{
	int	ret_fork;
	int	status;
	int	fdin;
	int	fdout;
	int	i;
	

	fdin = open(argv[1], O_RDONLY);
	if (fdin == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(argv[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	fdout = open(
			argv[argc - 1],
			O_TRUNC | O_CREAT | O_WRONLY, 00644);
	if (fdout == -1)
		return (3);
	ret_fork = fork();
	if (ret_fork == -1)
		return (4);
	if (ret_fork == 0)
		first_child(pipe_before, fdin, argv, envp);
//	waitpid(ret_fork, &status, 0);

	i = 3;
	while (argv[i + 2])
	{
		pipe(pipe_after);
		ret_fork = fork();
		if (ret_fork == -1)
			return (6);
		if (ret_fork == 0)
			mid_child(pipe_before, pipe_after, argv[i], envp);
		close(pipe_before[0]);
		close(pipe_before[1]);
		pipe_before[0] = dup(pipe_after[0]);
		pipe_before[1] = dup(pipe_after[1]);
		//dup2(pipe_after[0], pipe_before[0]);
		//dup2(pipe_after[1], pipe_before[1]);
		close(pipe_after[0]);
		close(pipe_after[1]);
//		waitpid(ret_fork, &status, 0);
		i++;
	}


	ret_fork = fork();
	if (ret_fork == -1)
		return (4);
	if (ret_fork == 0)
		last_child(pipe_before, fdout, argv[argc - 2], envp);
	close(pipe_before[0]);
	close(pipe_before[1]);
	close(pipe_after[0]);
	close(pipe_after[1]);
	waitpid(ret_fork, &status, 0);
	close(fdin);
	close(fdout);
	status = WEXITSTATUS(status);
	return (status);
}

int	pipex( char *argv[], char *envp[], int argc )
{
	int	pipe_before[2];
	int	pipe_after[2];

	pipe(pipe_before);
	forking(pipe_before, pipe_after, argv, envp, argc);
	close(pipe_before[0]);
	close(pipe_before[1]);
	close(pipe_after[0]);
	close(pipe_after[1]);
	
	return (0);
}

void	print_error( char *err )
{
	ft_putstr_fd("[\e[91mERROR\e[39m] ", 2);
	ft_putstr_fd(err, 2);
	ft_putstr_fd("\n", 2);
}

void	choose_error( int err_code )
{
	if (err_code == 3)
		print_error("can't create or open outfile.");
	else if (err_code == 4)
		print_error("fork error.");
}

int	main( int argc, char *argv[], char *envp[] )
{
	int		ret;

	if (argc < 5)
	{
		ft_putstr_fd("Usage: ./pipex infile cmd1 cmd2 ... cmdn outfile\n", 2);
		return (1);
	}
	ret = pipex(argv, envp, argc);
	choose_error(ret);
	ret = WEXITSTATUS(ret);
	return (ret);
}
