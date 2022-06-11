/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 18:58:22 by mmonarch          #+#    #+#             */
/*   Updated: 2022/06/11 18:58:27 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_input(t_shell *mshell, int *n)
{
	char	*buf;

	buf = ft_strjoin(mshell->time_input, mshell->input);
	free(mshell->input);
	mshell->input = buf;
	*n += ft_strlen(mshell->time_input);
	free(mshell->time_input);
	mshell->time_input = NULL;
}

void	new_input(t_shell *mshell)
{
	char	*buf;

	buf = ft_strjoin(mshell->time_input, mshell->input);
	free(mshell->input);
	mshell->input = buf;
	free(mshell->time_input);
	mshell->time_input = NULL;
}

int	chenge_input(t_shell *mshell, int *n)
{
	int	ret;

	if (mshell->time_input != NULL)
		update_input(mshell, n);
	mshell->time_input = mshell->input;
	while (1)
	{
		mshell->input = readline("> ");
		if (mshell->input == NULL)
			eof_input();
		ret = check_syntax_input(mshell, 0);
		if (ret == 1)
			return (1);
		else if (ret == 2)
		{
			free(mshell->input);
			continue ;
		}
		else
			break ;
	}
	if (mshell->time_input != NULL)
		new_input(mshell);
	return (0);
}
