#include "minishell.h"

void	ctrl_c(int number_sig)
{
    (void)number_sig;
    write(2, "\n", 1);
    rl_on_new_line();
    rl_replace_line("", 0);
    rl_redisplay();

}

void    change_signal(void)
{
    signal(SIGINT, ctrl_c);
    signal(SIGQUIT, SIG_IGN);
}

void    eof_input(void)
{
    write(2, "exit\n", 5);
    exit(0);
}