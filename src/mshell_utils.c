/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mshell_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:04:08 by mmonarch          #+#    #+#             */
/*   Updated: 2022/06/12 17:04:42 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_here_document(t_shell *mshell)
{
	close(mshell->lstcom->fd_here_document[0]);
	free(mshell->lstcom->here_document);
	mshell->lstcom->here_document = NULL;
}

int	check_mshell_input(char *str)
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

void	wait_fork(t_shell *mshell)
{
	int	status;

	(void )mshell;
	status = 0;
	waitpid(WAIT_ANY, &status, 0);
	if (WIFSIGNALED(status))
		g_last_exit_status = WTERMSIG(status) + 128;
	else if (WIFEXITED(status))
		g_last_exit_status = WEXITSTATUS(status);
	else
		g_last_exit_status = status;
}
