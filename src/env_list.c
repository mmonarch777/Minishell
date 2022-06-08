#include "minishell.h"

t_env   *new_env(void)
{
    t_env   *envt;

    envt = (t_env *)malloc(sizeof (t_env));
    if (!envt)
        return (NULL);
    envt->next = NULL;
    envt->key = NULL;
    envt->next = NULL;
    return (envt);
}

void    add_key(t_env **envt, char **mass)
{
    (*envt)->key = mass[0];
    if (!mass[1])
        (*envt)->value = "";
    else
        (*envt)->value = mass[1];
}

void    chenge_shlvl(char **mass)
{
    int shlvl;

    shlvl = ft_atoi(*mass);
    if (*mass != NULL)
        free(*mass);
    if (shlvl < 0)
        *mass = ft_strdup("0");
    else
        *mass = ft_itoa(shlvl + 1);
}

void    add_env(t_shell *mshell, char **mass)
{
    t_env   *env;
    t_env   *last;

    if (!ft_strcmp(mass[0], "SHLVL"))
        chenge_shlvl(&mass[1]);
    if (mshell->environment == NULL)
    {
        mshell->environment = new_env();
        add_key(&mshell->environment, mass);
        return ;
    }
    last = mshell->environment;
    env = new_env();
    add_key(&env, mass);
    while (last->next)
        last = last->next;
    last->next = env;
}