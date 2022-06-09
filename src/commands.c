#include "minishell.h"

t_command   *new_command(void)
{
    t_command *new;

    new = malloc(sizeof (t_command));
    new->amount = 0;
    new->token = 0;
    new->output_file = NULL;
    new->input_file = NULL;
    new->here_document = NULL;
    new->head = new;
    new->next = NULL;
    new->command = NULL;
    return (new);
}

void    add_command(t_shell *mshell)
{
    t_command *head;

    if (!mshell->lstcom)
        mshell->lstcom = new_command();
    else
    {
        head = mshell->lstcom->head;
        mshell->lstcom->next = new_command();
        mshell->lstcom = mshell->lstcom->next;
        mshell->lstcom->head = head;
    }
}

void    expand_com(t_shell *mshell, int *i)
{
    char **com;
    int nb;

    if (mshell->lstcom->token == REDIRECT_OUT
        || mshell->lstcom->token == REDIRECT_OUT_APPEND)
        split_output_file(mshell, i);
    else if (mshell->lstcom->token == REDIRECT_IN)
        split_input_file(mshell, i);
    else if (mshell->lstcom->token == HERE_DOCUMENT)
        split_here_document(mshell, i);
    else
    {
        com = (char **) malloc(sizeof (char *) * ((++mshell->lstcom->amount) + 1));
        nb = -1;
        while (++nb < mshell->lstcom->amount - 1)
            com[nb] = mshell->lstcom->command[nb];
        com[nb] = ft_substr(mshell->input, 0, *i);
        com[++nb] = NULL;
        if (mshell->lstcom->command)
            free(mshell->lstcom->command);
        mshell->lstcom->command = com;
    }
}