#include "minishell.h"

int syntax_error(t_shell *mshell, char symbol)
{
    if (symbol == 0)
        write(2, "minishell: syntax error near unexpected token `newline", 54);
    else
    {
        write(2, "minishell: syntax error near unexpected token `", 47);
        write(2, &symbol, 1);
    }
    write(2, "'\n", 2);
    mshell->status_last_command = 2;
    if (mshell->time_input)
        free(mshell->time_input);
    return (1);
}

int	object_error(t_shell *mshell, char *object_error)
{
    write(2, "minishell: ", 11);
    perror(object_error);
    mshell->status_last_command = 1;
    return (1);
}

int error_pid(t_shell *mshell)
{
    dup2(mshell->fd0, 0);
    dup2(mshell->fd1, 1);
    dup2(mshell->fd2, 2);
    if (mshell->lstcom->input_file)
        close(mshell->lstcom->fd_in_file);
    if (mshell->lstcom->output_file)
        close(mshell->lstcom->fd_out_file);
    if (mshell->lstcom->here_document)
        close(mshell->lstcom->fd_here_document[0]);
    return (object_error(mshell, "fork"));
}