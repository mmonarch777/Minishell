/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:00:04 by mmonarch          #+#    #+#             */
/*   Updated: 2022/06/11 19:05:54 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_with_n(t_shell *mshell, int i)
{
	char	*buf;

	while (mshell->lstcom->command[i] != NULL)
	{
		buf = mshell->lstcom->command[i];
		write(1, buf, ft_strlen(buf));
		if (mshell->lstcom->command[i + 1] != NULL)
			write(1, " ", 1);
		i++;
	}
}

int	my_echo(t_shell *mshell)
{
	int	i;

	i = 1;
	if (!ft_strcmp("echo", mshell->lstcom->command[0]))
	{
		if (mshell->lstcom->command[i] != NULL)
		{
			if (!ft_strcmp("-n", mshell->lstcom->command[1]))
				i = 2;
			print_with_n(mshell, i);
		}
		if (i == 1)
			write(1, "\n", 1);
		g_last_exit_status = 0;
		return (0);
	}
	return (1);
}
