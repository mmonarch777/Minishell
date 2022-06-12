# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmonarch <mmonarch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/19 14:10:01 by mmonarch          #+#    #+#              #
#    Updated: 2022/06/12 10:39:27 by mmonarch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libmini.a

SRC =	ft_memset.c		ft_isalpha.c		ft_bzero.c\
		ft_memcpy.c		ft_memccpy.c		ft_memmove.c\
		ft_memchr.c		ft_memcmp.c			ft_strlen.c\
		ft_isdigit.c	ft_isalnum.c		ft_isascii.c\
		ft_isprint.c	ft_toupper.c		ft_tolower.c\
		ft_strchr.c		ft_strchr.c			ft_strrchr.c\
		ft_strncmp.c	ft_isnotprint.c		ft_strlcpy.c\
		ft_strlcat.c	ft_strnstr.c		ft_atoi.c\
		ft_calloc.c		ft_strdup.c			ft_substr.c\
		ft_strjoin.c	ft_itoa.c			ft_strtrim.c\
		ft_strmapi.c	ft_putchar_fd.c		ft_putendl_fd.c\
		ft_putnbr_fd.c	ft_putstr_fd.c		ft_split.c\
		ft_strcmp.c		ft_is_big_alpha.c	ft_is_low_alpha.c\
		ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c\
		ft_lstlast.c	ft_lstadd_back.c	ft_lstdelone.c\
		ft_lstclear.c	ft_lstiter.c		ft_lstmap.c

OBJ =	$(patsubst %.c,%.o,$(SRC))

HEADER = libft.h

FLAGS =	-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $?
	make clean

%.o: %.c
	gcc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

norm:
	norminette $(SRC) $(HEADER)

re:	fclean all

.PHONY :	all norm clean fclean re





