# Makefile generate by afaby

# Name of the executable
NAME	=	pipex

# Path of the libft
LIBFT_DIR	=	libft
LIBFT		=	-I $(LIBFT_DIR) -L $(LIBFT_DIR) -lft

# Path of your headers
INC_DIR	=	.
INC		=	-I $(INC_DIR)

# Compiler to use
CC		=	gcc

# Flags to use
CFLAGS	=	-Wall -Wextra -Werror -g

# All the sources
SRCS	=	pipex.c

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) $(INC) $(LIBFT)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) $(INC) $(LIBFT) $(MLX)

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean : clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re : fclean all

.PHONY: re fclean clean all
