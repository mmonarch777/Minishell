#include "minishell.h"

int parser(char symbol, int *i, t_shell *mshell)
{
    if (symbol == ' ' || symbol == '\t' || mshell->input[*i] == '\0')
        return (split_input(mshell, i));
    if (symbol == '$')
        return (check_dollar(mshell, i));
    if (symbol == '\'')
        return (one_quote(mshell, i));
    if (symbol == '\"')
        return (two_quote(mshell, i));
    if (parser_token(symbol, i, mshell))
        return (1);
    return (0);
}

int parser_input(t_shell *mshell, int i)
{
    char    *buf;

    if (check_syntax_input(mshell, 0))
        return (1);
    while (mshell->input[i] == ' ' || mshell->input[i] == '\t')
        i++;
    buf = ft_substr(mshell->input, i, ft_strlen(mshell->input));
    free(mshell->input);
    mshell->input = buf;
    i = 0;
    add_command(mshell);
    while (mshell->input)
    {
        if (parser(mshell->input[i], &i, mshell))
            return (1);
        i++;
    }
    return (0);
}

void    init_mshell(t_shell *mshell)
{
    mshell->environment = NULL;
    mshell->lstcom = NULL;
    mshell->input = NULL;
    mshell->time_input = NULL;
    mshell->status_last_command = 0;
    mshell->have_pipe = 0;
    chenge_signal();
}

int main(int argc, char **argv, char **env)
{
    t_shell mshell;

    init_mshell(&mshell);
    get_env(env, &mshell);
    rl_outstream = stderr;
    while (1)
    {
        if (mshell.input)
            free(mshell.input);
        signal(SIGINT, ctrl_c2);
        mshell.input = readline("\e[0;32mminishell$\e[0;39m ");
        if (!mshell.input)
            eof_input();
        if (!check_mshell_input(mshell.input))
            continue ;
        add_history(mshell.input);
        if (!parser_input(&mshell, 0))
            comply_com(&mshell);
        clear_mshell(&mshell, 0);
    }
}
