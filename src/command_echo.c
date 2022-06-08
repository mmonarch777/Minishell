# include "minishell.h"

void    print_with_n(t_shell *mshell, int i)
{
    char *buf;

    while (mshell->lstcom->command[i] != NULL)
    {
        buf = mshell->lstcom->command[i];
        write(1, buf, ft_strlen(buf));
        if (mshell->lstcom->command[i + 1] != NULL)
            write(1, " ", 1);
        i++;
    }
}

int my_echo(t_shell *mshell)
{
    int i;

    i = 1;
    if (!ft_strcmp("echo", mshell->lstcom->command[0]))
    {
        if (!ft_strcmp("-n", mshell->lstcom->command[1]))
            i = 2;
        print_with_n(mshell, i);
        if (i == 1)
            write(1, "\n", 1);
        mshell->status_last_command = 0;
        return (0);
    }
    return (1);
}