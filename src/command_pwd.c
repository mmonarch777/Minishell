# include "minishell.h"

int my_pwd(t_shell *mshell)
{
    char	*mass;

    if (!ft_strcmp("pwd", mshell->lstcom->command[0]))
    {
        mass = getcwd(NULL, 0);
        write(1, mass, ft_strlen(mass));
        write(1, "\n", 1);
        free(mass);
        last_exit_status = 0;
        return (0);
    }
    return (1);
}