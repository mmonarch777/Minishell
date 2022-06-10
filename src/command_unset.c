#include "minishell.h"

int check_equals_and_valid(t_shell *mshell, char *com)
{
    int i;

    i = 0;
    while (com[i] != '\0')
    {
        if (i == 0 && !(ft_isalpha(com[i]) || com[i] == '_'))
            return (error_valid(mshell, com));
        if (!(ft_isalnum(com[i]) || com[i] == '_') && i != 0)
            return (error_valid(mshell, com));
        ++i;
    }
    if (!check_equals(com, '='))
        return (error_valid(mshell, com));
    return (0);
}

void    free_delite(t_env *delite)
{
    free(delite->key);
    if (delite->value)
        free(delite->value);
    free(delite);
}

void    delite_from_env(t_shell *mshell, t_env *delite, char *key)
{
    t_env   *env;

    env = mshell->environment;
    while (env)
    {
        if (!strcmp(env->key, key))
        {
            delite = env;
            env = env->next;
            mshell->head_env = env;
            break;
        }
        if (!strcmp(env->next->key, key))
        {
            delite = env->next;
            env->next = env->next->next;
            break;
        }
        env = env->next;
        if (env->next == NULL)
            return;
    }
    mshell->environment = mshell->head_env;
    if (delite)
        free_delite(delite);
}

void    delite_env(t_shell *mshell, char **com)
{
    int i;

    i = 1;
    while (com[i])
    {
        if (check_equals_and_valid(mshell, com[i]))
        {
            ++i;
            continue;
        }
        delite_from_env(mshell, NULL,  com[i]);
        ++i;
    }
}

int my_unset(t_shell *mshell)
{
    if (!strcmp(mshell->lstcom->command[0], "unset"))
    {
        mshell->status_last_command = 0;
        if (mshell->lstcom->command[1] != NULL)
            delite_env(mshell, mshell->lstcom->command);
        return (0);
    }
    return (1);
}