# include "minishell.h"

int my_env(t_shell *mshell)
{
    t_env   *env;

    if (!strcmp(mshell->lstcom->command[0], "env"))
    {
        env = mshell->environment;
        while (env)
        {
            write(1, env->key, ft_strlen(env->key));
            write(1, "=", 1);
            if (env->value != NULL)
                write(1, env->value, ft_strlen(env->value));
            write(1, "\n", 1);
            env = env->next;
        }
        mshell->status_last_command = 0;
        return (0);
    }
    return (1);
}