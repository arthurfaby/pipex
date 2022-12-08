# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/10 19:07:12 by afaby             #+#    #+#              #
#    Updated: 2022/06/09 15:36:10 by afaby            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CHAR  =		ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c

STR   =		ft_strlen.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strjoin.c \
			ft_substr.c \
			ft_strmapi.c \
			ft_strtrim.c \
			ft_striteri.c \
			ft_split.c \
			ft_strdup.c

MEMORY =	ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_calloc.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_free_double_pointer.c

OUTPUT =	ft_putchar.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putstr.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putnbr.c \
			ft_putnbr_base.c \
			ft_putnbr_base_u.c \
			ft_putnbr_base_ull.c \
			ft_putptr.c

OTHER  =	ft_itoa.c \
			ft_atoi.c \
			ft_atoi_base.c

LL     =	ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstadd_back.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstiter.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstmap.c

GNL    =	get_next_line.c

FT_PTF =	ft_printf.c \
			ft_process.c

SRCS   =	$(addprefix char/, $(CHAR)) \
			$(addprefix str/, $(STR)) \
			$(addprefix memory/, $(MEMORY)) \
			$(addprefix output/, $(OUTPUT)) \
			$(addprefix other/, $(OTHER)) \
			$(addprefix ll/, $(LL)) \
			$(addprefix gnl/, $(GNL)) \
			$(addprefix ft_printf/, $(FT_PTF))
	

FLAGS =	-Wall -Wextra -Werror

OBJS =	$(SRCS:.c=.o)

CC =	gcc

all: $(NAME)
	@echo "\n\033[0m"

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.c.o:
	@echo "\033[0;35m"
	@echo -n "Compiling $<..."
	@$(CC) $(FLAGS) -I. -c $< -o $@ 
 
$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

.PHONY: all clean fclean re bonus
