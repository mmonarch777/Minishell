/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mshell_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:03:42 by mmonarch          #+#    #+#             */
/*   Updated: 2022/06/12 10:30:03 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	syntax_error(t_shell *mshell, char symbol)
{
	if (symbol == 0)
		write(2, "minishell: syntax error near unexpected token `newline", 54);
	else
	{
		write(2, "minishell: syntax error near unexpected token `", 47);
		write(2, &symbol, 1);
	}
	write(2, "'\n", 2);
	g_last_exit_status = 2;
	if (mshell->time_input)
		free(mshell->time_input);
	return (1);
}

int	object_error(t_shell *mshell, char *object_error)
{
	(void )mshell;
	write(2, "minishell: ", 11);
	perror(object_error);
	g_last_exit_status = 1;
	return (1);
}

int	error_pid(t_shell *mshell)
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
