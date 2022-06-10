#include "minishell.h"

int comply_without_pipe(t_shell *mshell)
{
    if (!my_pwd(mshell))
        return (0);
    else if (!my_echo(mshell))
        return (0);
    else if (!my_cd(mshell))
        return (0);
    else if (!my_env(mshell))
        return (0);
    else if (!my_export(mshell))
        return (0);
    else if (!my_unset(mshell))
        return (0);
    else if (!my_exit(mshell))
        return (0);
    else
        if(comply_with_pipe(mshell))
            return (1);
    return (0);
}

int my_com(t_shell *mshell)
{
    if (!my_pwd(mshell))
        return (0);
    else if (!my_echo(mshell))
        return (0);
    else if (!my_cd(mshell))
        return (0);
    else if (!my_env(mshell))
        return (0);
    else if (!my_export(mshell))
        return (0);
    else if (!my_unset(mshell))
        return (0);
    else if (!my_exit(mshell))
        return (0);
    return (1);
}

char	*ft_getenv_value(t_env *lst, char *key)
{
    t_env	*tmp;

    tmp = lst;
    while (tmp)
    {
        if (!ft_strcmp(key, tmp->key))
            return (tmp->value);
        tmp = tmp->next;
    }
    return ("");
}

char	*prog_name(t_shell *mshell)
{
    int		i;
    char	*mass;
    char    *mass1;
    char	*com;
    char	**path;

    com = mshell->lstcom->command[0];
    path = ft_split(ft_getenv_value(mshell->environment, "PATH"), ':');
    i = 0;
    while (path[i])
    {
        mass1 = ft_strjoin("/", mshell->lstcom->command[0]);
        mass = ft_strjoin(path[i], mass1);
        free(mass1);
        free(path[i]);
        if (access(mass, 0) == 0)
            com = mass;
        else
            free(mass);
        i++;
    }
    free(path);
    return (com);
}

int size_env(t_shell *mshell)
{
    t_env   *env;
    int     i;

    env = mshell->environment;
    i = 0;
    while (env)
    {
        ++i;
        env = env->next;
    }
    return (i);
}

char	**new_arr_env(t_shell *mshell)
{
    t_env	*env;
    char	**mass_env;
    char	*mass;
    int		i;

    env = mshell->environment;
    i = size_env(mshell);
    mass_env = (char **)malloc(sizeof(char *) * (i + 1));
    i = 0;
    while (env)
    {
        mass = ft_strjoin(env->key, "=");
        mass_env[i] = ft_strjoin(mass, env->value);
        free(mass);
        env = env->next;
        i++;
    }
    mass_env[i] = NULL;
    return (mass_env);
}
