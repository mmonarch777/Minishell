#include "minishell.h"

int change_fd(t_shell *mshell)
{
    if (mshell->lstcom->token == PIPE)
        if (pipe(mshell->lstcom->fd_pipe))
            return (object_error(mshell, "pipe"));
    if (mshell->lstcom->output_file != NULL)
        if (dup2(mshell->lstcom->fd_out_file, 1) == -1)
            return (object_error(mshell, "dup2"));
    if (mshell->lstcom->here_document != NULL)
        if (dup2(mshell->lstcom->here_document[0], 0) == -1)
            return (object_error(mshell, "dup2"));
    return (0);
}

int comply_with_pipe(t_shell *mshell)
{
    pid_t   pid;

    pid = fork();
    if (pid == 0)
    {
        if (mshell->lstcom->token == PIPE && !mshell->lstcom->output_file)
        {
            dup2(mshell->lstcom->fd_pipe[1], 1);
            close(mshell->lstcom->fd_pipe[0]);
        }
        if (mshell->lstcom->input_file)
            if (dup2(mshell->lstcom->fd_in_file, 0) == -1)
                exit(1);
        if (mshell_exec(mshell))
            exit(mshell->status_last_command);
        else if (execve())
            ;
        exit(mshell->status_last_command);
    }
    if (pid == -1)
        return (error_pid(mshell));
    wait_fork(mshell);
    return (0);
}

int comply_without_pipe(t_shell *mshell)
{
    if (!my_pwd(mshell))
        return (0);
    else if (!my_echo(mshell))
        return (0);
    else if (!my_cd(mshell))
        return (0);
}

void    comply(t_shell *mshell)
{
    mshell->lstcom = mshell->lstcom->head;
    while (mshell->lstcom)
    {
        if (change_fd(mshell))
            break;
        if (mshell->have_pipe && mshell->lstcom->command)
        {
            if (comply_with_pipe(mshell))
                break;
        }
        else if (mshell->lstcom->command)
        {
            if (comply_without_pipe(mshell))
                break;
        }

    }
}

void    comply_com(t_shell *mshell)
{
    mshell->fd0 = dup(0);
    mshell->fd1 = dup(1);
    mshell->fd2 = dup(2);
    comply(mshell);
    close(mshell->fd0);
    close(mshell->fd1);
    close(mshell->fd2);
}