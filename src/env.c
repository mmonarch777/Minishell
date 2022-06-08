#include "minishell.h"

void   get_env(char **env, t_shell *mshell)
{
    char    **mass;
    int     i;

    i = 0;
    while (env[i])
    {
        mass = ft_split(env[i], '=');
        add_env(mshell, mass);
        free(mass);
        i++;
    }
}