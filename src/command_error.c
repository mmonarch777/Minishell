# include "minishell.h"

int error_directory(t_shell *mshell, char **old)
{
    write(2, "minishell: cd: ", 15);
    perror(*old);
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

int error_oldpwd(t_shell *mshell, char *oldpwd)
{
    write(2, "minishell: cd: ", 15);
    write(2, oldpwd, ft_strlen(oldpwd));
    write(2, "not set\n", 9);
    mshell->status_last_command = 1;
    return (0);
}