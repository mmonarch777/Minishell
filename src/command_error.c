# include "minishell.h"

int error_directory(t_shell *mshell, char **old)
{
    write(2, "minishell: cd: ", 15);
    perror(*old);
    if (*old != NULL)
        free(*old);
    mshell->status_last_command = 1;
    return (0);
}

int error_getcwd(t_shell *mshell)
{
    perror("minishell: cd");
    mshell->status_last_command = 1;
    return (0);
}

int error_set_pwd(t_shell *mshell, char *pwd)
{
    write(2, "minishell: cd: ", 15);
    write(2, pwd, ft_strlen(pwd));
    write(2, " not set\n", 9);
    mshell->status_last_command = 1;
    return (0);
}

int error_too_many_arguments(t_shell *mshell)
{
    write(2, "minishell: cd: too many arguments\n", 34);
    mshell->status_last_command = 1;
    return (0);
}