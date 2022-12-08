/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:31:56 by afaby             #+#    #+#             */
/*   Updated: 2022/09/26 13:59:26 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

	if (fdin != -1)
	{
		dup2(fdin, 0);
		close(fdin);
	}
	close(pipefd[0]);
	cmd = get_cmd(argv[2], envp);
	#include <stdio.h>
	int	i = -1;
	printf("[");
	while (cmd[++i])
		printf("%s, ", cmd[i]);
	printf("NULL]\n");
	dup2(pipefd[1], 1);
	close(pipefd[0]);
	execve(cmd[0], cmd, envp);
}

void	last_child( int pipefd[2], int fdout, char *argv[], char *envp[] )
{
	char	**cmd;

	dup2(fdout, 1);
	close(fdout);
	close(pipefd[1]);
	dup2(pipefd[0], 0);
	close(pipefd[0]);
	cmd = get_cmd(argv[3], envp);
	execve(cmd[0], cmd, envp);
}

int	forking( int pipefd[2], char *argv[], char *envp[] )
{
	int	ret_fork;
	int	status;
	int	fdin;
	int	fdout;

	fdin = open(argv[1], O_RDONLY);
	fdout = open(
			argv[4],
			O_TRUNC | O_CREAT | O_WRONLY, 00644);
	if (fdout == -1)
		return (3);
	ret_fork = fork();
	if (ret_fork == -1)
		return (4);
	if (ret_fork == 0)
		first_child(pipefd, fdin, argv, envp);
	waitpid(ret_fork, &status, 0);
	ret_fork = fork();
	if (ret_fork == -1)
		return (4);
	if (ret_fork == 0)
		last_child(pipefd, fdout, argv, envp);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(ret_fork, &status, 0);
	close(fdin);
	close(fdout);
	status = WEXITSTATUS(status);
	return (status);
}

int	pipex( char *argv[], char *envp[] )
{
	int	pipefd[2];

	pipe(pipefd);
	forking(pipefd, argv, envp);
	//close(pipefd[0]);
	//close(pipefd[1]);
	
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

	if (argc != 5)
	{
		ft_putstr_fd("Usage: ./pipex infile cmd1 cmd2 outfile\n", 2);
		return (1);
	}
	ret = pipex(argv, envp);
	choose_error(ret);
	ret = WEXITSTATUS(ret);
	return (ret);
}
