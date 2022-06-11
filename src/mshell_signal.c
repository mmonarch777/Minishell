#include "minishell.h"

void	ctrl_c(int number_sig)
{
    (void)number_sig;
    write(2, "\n", 1);
    rl_on_new_line();
    rl_replace_line("", 0);
    rl_redisplay();
    last_exit_status = 130;
}

void	ctrl_c2(int sig)
{
    (void)sig;
    write(2, "\n", 1);
    rl_on_new_line();
    rl_replace_line("", 0);
    errno = 1;
    last_exit_status = 130;
}

void    chenge_signal(void)
{
    signal(SIGQUIT, SIG_IGN);
}

void    eof_input(void)
{
    write(2, "exit\n", 5);
    exit(0);
}