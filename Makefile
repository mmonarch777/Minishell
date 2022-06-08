NAME   =	minishell

SRC    =	src/minishell.c		src/env.c					src/env_list.c		src/mshell_error.c\
			src/clear_mshell.c	src/check_syntax_utils.c	src/commands.c		src/parser_dollar.c\
			src/parser_token.c	src/check_syntax_input.c	src/mshell_utils.c 	src/parser_split.c\
			src/parser_quote.c	src/mshell_signal.c			src/comply_com.c	src/command_pwd.c\
			src/command_echo.c	src/command_error.c			src/command_cd.c	src/command_cd_utils.c\


OBJ    =	$(SRC:.c=.o)
HEADER =	include/minishell.h
CC     =	gcc
#CFLAGS =	-Wall -Wextra -Werror
LIBA   =   libft/libft.a


all:		$(NAME)

$(NAME):	$(OBJ) $(LIBA)
			$(CC) $(CFLAGS) $(OBJ) -Llibft -lft -lreadline -o $(NAME)
			make clean

%.o: %.c $(LIBA) $(HEADER)
			$(CC) $(CFLAGS) -c -Iinclude $< -o $@

$(LIBA):
			make -C libft/

clean:
			rm -rf $(OBJ)
			$(MAKE) clean -C libft

fclean:		clean
			rm -rf $(NAME)
			$(MAKE) fclean -C libft

re:			fclean all

.PHONY:		all clean fclean re bonus readline readline_uninstall