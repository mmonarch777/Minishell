# include "minishell.h"

void    change_value_pwd(t_shell *mshell, char **value, char *key)
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

void    check_oldpwd(t_shell *mshell)
{
    t_env   *env;

    env = mshell->environment;
    while (env)
    {
        if (!ft_strcmp(env->value, "OLDPWD"))
            return;
        env = env->next;
    }

}