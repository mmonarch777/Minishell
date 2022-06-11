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

int	error_execve(t_shell *mshell, char *com)
{
    struct stat buff;

    if (!stat(com, &buff) && S_ISDIR(buff.st_mode))
    {
        ft_putstr_fd(com, 2);
        ft_putendl_fd(": is a directory", 2);
        exit (126);
    }
    else if (ft_strncmp(com, "./", 2) == 0 || ft_strncmp(com, "../", 3) == 0
        || ft_strncmp(com, "/", 1) == 0)
    {
        perror(com);
        if (errno == 13)
            exit (126);
        exit (127);
    }
    ft_putstr_fd(com, 2);
    ft_putendl_fd(": command not found", 2);
    exit(127);
}