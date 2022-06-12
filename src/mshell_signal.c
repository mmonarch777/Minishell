/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mshell_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:03:53 by mmonarch          #+#    #+#             */
/*   Updated: 2022/06/12 07:17:02 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	rl_replace_line(const char *string, int i);

void	ctrl_c(int number_sig)
{
	(void)number_sig;
	write(2, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_last_exit_status = 130;
}

void	ctrl_c2(int sig)
{
	(void)sig;
	write(2, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	errno = 1;
	g_last_exit_status = 130;
}

void	rl_replace_line(const char *string, int i)
{
	(void )string;
	(void )i;
}

void	chenge_signal(void)
{
	signal(SIGQUIT, SIG_IGN);
}

void	eof_input(void)
{
	write(2, "exit\n", 5);
	exit(0);
}
