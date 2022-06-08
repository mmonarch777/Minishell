#ifndef MINISHELL_H
# define MINISHELL_H
# include "../minilib//libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/wait.h>

# define PIPE                   1
# define REDIRECT_OUT           2
# define REDIRECT_OUT_APPEND    3
# define REDIRECT_IN            4
# define HERE_DOCUMENT          5

typedef struct s_env
{
    char            *key;
    char            *value;
    struct s_env    *next;
}   t_env;

typedef struct s_command
{
    char                **command;
    char                *output_file;
    char                *input_file;
    char                *here_document;
    int                 fd_here_document[2];
    int                 fd_in_file;
    int                 fd_out_file;
    int                 fd_pipe[2];
    int                 token;
    int                 amount;
    struct s_command    *head;
    struct s_command    *next;
}   t_command;

typedef struct s_shell
{
    char        *input;
    char        *time_input;
    int         have_pipe;
    int         fd0;
    int         fd1;
    int         fd2;
    t_env       *environment;
    t_command   *lstcom;
    int         status_last_command;
}   t_shell;

void    init_mshell(t_shell *mshell);
void    get_env(char **env, t_shell *mshell);
int     check_mshell_input(char *str);
void    cleaning(char **mass);
void    add_env(t_shell *mshell, char **mass);
void    eof_input(void);
int     check_syntax_input(t_shell *mshell, int n);
void    clear_mshell(t_shell *mshell);
int     syntax_error(t_shell *mshell, char symbol);
int     split_input(t_shell *msell, int *i);
void    add_command(t_shell *mshell);
void    expand_com(t_shell *mshell, int *i);
int     parser(char symbol, int *i, t_shell *mshell);
int     check_dollar(t_shell *mshell, int *i);
int     check_input(t_shell *mshell);
int     chenge_input(t_shell *mshell, int *n);
int     parser_token(char symbol, int *i, t_shell *mshell);
int     split_output_file(t_shell *mshell, int *i);
int     object_error(t_shell *mshell, char *object_error);
int     split_input_file(t_shell *mshell, int *i);
int     split_here_document(t_shell *mshell, int *i);
void    free_here_document(t_shell *mshell);
int     one_quote(t_shell *mshell, int *i);
int     two_quote(t_shell *mshell, int *i);
void    change_signal(void);
void    wait_fork(t_shell *mshell);
int     error_pid(t_shell *mshell);
int     my_pwd(t_shell *mshell);
int     my_echo(t_shell *mshell);
int     my_cd(t_shell *mshell);
int     error_cd_dont_set(t_shell *mshell, char *oldpwd);
int     error_getcwd(t_shell *mshell);
int     error_directory(t_shell *mshell, char **old);
void    change_value_pwd(t_shell *mshell, char **value, char *key);

#endif
