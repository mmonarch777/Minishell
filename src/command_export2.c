#include "minishell.h"

int error_valid(t_shell *mshell, char *mass)
{
    write(2, "minishell: export: `", 21);
    write(2, mass, ft_strlen(mass));
    write(2, "': not a valid identifier\n", 26);
    mshell->status_last_command = 1;
    return (1);
}

int check_dup_and_valid(t_shell *mshell, char *mass)
{
    t_env   *env;

    env = mshell->environment;
    if (!(ft_isalpha(*mass) || *mass == '_'))
        return (error_valid(mshell, mass));
    while (env)
    {
        if (!ft_strcmp(env->key, mass))
            return (1);
        env = env->next;
    }
    return (0);
}

int add_to_env(t_shell *mshell)
{
    int i;
    char **mass;

    i = 1;
    while (mshell->lstcom->command[i] != NULL)
    {
        if (check_dup_and_valid(mshell, mshell->lstcom->command[i]))
        {
            i++;
            continue;
        }
        mass = split_for_env(mshell->lstcom->command[i], '=');
        add_env(mshell, mass, check_equals(mshell->lstcom->command[i], '='));
        free(mass);
        i++;
    }
    return (0);
}