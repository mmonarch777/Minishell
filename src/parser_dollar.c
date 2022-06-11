#include "minishell.h"

int exit_status_last_command(t_shell *mshell, int num, int *i)
{
    char *mass1;
    char *mass2;
    char *mass3;
    char *mass;

    mass = ft_substr(mshell->input, 0, num);
    mass1 = ft_itoa(last_exit_status);
    mass2 = ft_strdup(mshell->input + *i + 1);
    mass3 = ft_strjoin(mass, mass1);
    free(mass);
    free(mass1);
    mass = ft_strjoin(mass2, mass3);
    free(mass2);
    free(mass3);
    free(mshell->input);
    mshell->input = mass;
    *i = num - 1;
    return (0);
}

int symbols_after_dollar(t_shell *mshell, int num, int *i)
{
    char *mass;
    char *mass1;
    char *mass2;

    mass1 = ft_substr(mshell->input, 0, num);
    mass2 = ft_strdup(mshell->input + (*i));
    mass = ft_strjoin(mass1, mass2);
    free(mass1);
    free(mass2);
    free(mshell->input);
    mshell->input = mass;
    *i = num - 1;
    return (0);
}

char    *check_key_env(t_env *environment, char *key_env)
{
    t_env   *env;

    env = environment;
    while (env)
    {
        if (!ft_strcmp(env->key, key_env))
            return (env->value);
        env = env->next;
    }
    return ("");
}

int revise_environment(t_shell *mshell, int num, int *i)
{
    char *mass1;
    char *mass2;
    char *mass3;
    char *value_env;
    char *key_env;

    mass1 = ft_substr(mshell->input, 0, num);
    while (ft_isalnum(mshell->input[*i]) || mshell->input[*i] == '_')
        ++(*i);
    key_env = ft_substr(mshell->input, num + 1, *i - num - 1);
    mass2 = ft_strdup(mshell->input + *i);
    value_env = check_key_env(mshell->environment, key_env);
    mass3 = ft_strjoin(mass1, value_env);
    free(key_env);
    free(mass1);
    mass1 = ft_strjoin(mass3, mass2);
    free(mass2);
    free(mass3);
    free(mshell->input);
    mshell->input = mass1;
    *i = num + ft_strlen(value_env) - 1 ;
    return (0);
}

int check_dollar(t_shell *mshell, int *i)
{
    int num;

    num = *i;
    ++(*i);
    if (mshell->input[*i] == '?')
        return (exit_status_last_command(mshell, num, i));
    else if (mshell->input[*i] == '\'' || mshell->input[*i] == '\"'
        || ft_isdigit(mshell->input[*i]))
        return (symbols_after_dollar(mshell, num, i));
    else if (mshell->input[*i] == '_' || ft_isalnum(mshell->input[*i]))
        return (revise_environment(mshell, num, i));
    else
        *i = num;
    return (0);

}