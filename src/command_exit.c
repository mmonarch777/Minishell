#include "minishell.h"

int check_exit_option(char *option)
{
    int i;

    i = 0;
    while (option[i] != '\0')
    {
        if (option[i] == '-' && i == 0)
            i++;
        if (option[i] == '\0' || !ft_isdigit(option[i]))
            return (1);
        i++;
    }
    return (0);
}

int	exit_error(char *option)
{
    write(2, "minishell: exit: ", 17);
    write(2, option, ft_strlen(option));
    write(2, ": numeric argument required\n", 28);
    exit(255);
}

int my_exit(t_shell *mshell)
{
    if (!ft_strcmp(mshell->lstcom->command[0], "exit"))
    {
        if (mshell->lstcom->command[1] != NULL)
        {
            write(2, "exit\n", 5);
            if (check_exit_option(mshell->lstcom->command[1]))
                exit_error(mshell->lstcom->command[1]);
            else if (mshell->lstcom->command[2] != NULL)
            {
                write(2, "minishell: exit: too many arguments\n", 36);
                last_exit_status = 1;
                return (0);
            }
            exit(ft_atoi(mshell->lstcom->command[1]));
        }
        write(2, "exit\n", 5);
        exit(0);
    }
    return (1);
}