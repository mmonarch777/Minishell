#include "minishell.h"

void    free_here_document(t_shell *mshell)
{
    close(mshell->lstcom->fd_here_document[0]);
    free(mshell->lstcom->here_document);
    mshell->lstcom->here_document = NULL;
}

int check_mshell_input(char *str)
{
    while (*str)
    {
        if (*str == ' ' || *str == '\t')
            str++;
        else
            return (1);
    }
    return (0);
}

void    wait_fork(t_shell *mshell)
{
    int status;

    status = 0;
    waitpid(-1, &status, 0);
    mshell->status_last_command = status;
}