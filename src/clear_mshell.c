#include "minishell.h"

void    clear_mshell(t_shell *mshell)
{
    t_command   *command;
    int		i;

    mshell->lstcom = mshell->lstcom->head;
    while (mshell->lstcom)
    {
        i = 0;
        while (mshell->lstcom->command && mshell->lstcom->command[i])
            free(mshell->lstcom->command[i++]);
        free(mshell->lstcom->command);
        if (mshell->lstcom->output_file != NULL)
            free(mshell->lstcom->output_file);
        if (mshell->lstcom->input_file != NULL)
            free(mshell->lstcom->input_file);
        if (mshell->lstcom->here_document != NULL)
            free(mshell->lstcom->here_document);
        if (mshell->lstcom->token == PIPE && mshell->lstcom->fd_pipe[0] != 0)
            close(mshell->lstcom->fd_pipe[0]);
        command = mshell->lstcom;
        mshell->lstcom = mshell->lstcom->next;
        free(command);
    }
    mshell->have_pipe = 0;
}
