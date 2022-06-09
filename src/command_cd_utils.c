# include "minishell.h"

void    chenge_value_pwd(t_shell *mshell, char **value, char *key)
{
    t_env   *env;

    env = mshell->environment;
    while (env)
    {
        if (!ft_strcmp(key, env->key))
        {
            free(env->value);
            env->value = *value;
            break;
        }
        env = env->next;
    }
}

void    check_oldpwd_env(t_shell *mshell)
{
    t_env   *env;
    char    **mass;

    env = mshell->environment;
    while (env)
    {
        if (!ft_strcmp(env->value, "OLDPWD"))
            return;
        env = env->next;
    }
    mass = ft_split("OLDPWD=", '=');
    add_env(mshell, mass);
    free(mass);
}

char    *home_pwd(t_shell *mshell)
{
    t_env   *env;
    char    *mass;

    env = mshell->environment;
    mass = NULL;
    while (env)
    {
        if (!ft_strcmp(env->key, "HOME"))
        {
            mass = ft_strdup(env->value);
            break ;
        }
        env = env->next;
    }
    return (mass);
}