# include "minishell.h"

char    *get_value_env(t_shell *mshell, char *key)
{
    t_env   *env;
    char    *mass;

    env = mshell->environment;
    while (env)
    {
        if (!strcmp(env->key, key))
        {
            mass = ft_strdup(env->value);
            return (mass);
        }
        env = env->next;
    }
    return (NULL);
}

int swap_pwd(t_shell *mshell)
{
    char    *old;
    char    *new;

    old = get_value_env(mshell, "OLDPWD");
    if (!old)
        return (error_cd_dont_set(mshell, "OLDPWD"));
    new = getcwd(NULL, 0);
    if (!new)
        return (error_getcwd(mshell));
    if (chdir(old))
    {
        free(new);
        return (error_directory(mshell, &old));
    }
    change_value_pwd(mshell, &new, "OLDPWD");
    change_value_pwd(mshell, &old, "PWD");
    ft_putendl_fd(old, 1);
    mshell->status_last_command = 0;
    return (0);
}

int get_home_pwd(t_shell *mshell)
{
    char    *old;
    char    *new;

    check_oldpwd(mshell);
}

int my_cd(t_shell *mshell)
{
    if (!strcmp("cd", mshell->lstcom->command[0]))
    {
        if (!strcmp("-", mshell->lstcom->command[1]))
            return (swap_pwd(mshell));
        if (ft_strcmp("~", mshell->lstcom->command[1]) ||
            mshell->lstcom->command[1] == NULL)
            return (get_home_pwd(mshell));
    }
}