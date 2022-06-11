/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_input.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 18:56:24 by mmonarch          #+#    #+#             */
/*   Updated: 2022/06/11 19:31:39 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_syntax_redir_out(t_shell *mshell, int *n)
{
	if (mshell->input[*n] == '>')
	{
		if (mshell->input[*n + 1] == '>')
			++*n;
		++*n;
		while ((mshell->input[*n] == ' ' || mshell->input[*n] == '\t')
			&& mshell->input[*n] != '\0')
			++*n;
		if (mshell->input[*n] == '\0' || mshell->input[*n] == '>'
			|| mshell->input[*n] == '<' || mshell->input[*n] == '|')
			return (syntax_error(mshell, mshell->input[*n]));
		--(*n);
	}
	return (0);
}

int	check_syntax_redir_in(t_shell *mshell, int *n)
{
	if (mshell->input[*n] == '<')
	{
		if (mshell->input[*n + 1] == '<')
			++*n;
		++*n;
		while ((mshell->input[*n] == ' ' || mshell->input[*n] == '\t')
			&& mshell->input[*n] != '\0')
			++*n;
		if (mshell->input[*n] == '\0' || mshell->input[*n] == '>'
			|| mshell->input[*n] == '<' || mshell->input[*n] == '|')
			return (syntax_error(mshell, mshell->input[*n]));
		--(*n);
	}
	return (0);
}

int	check_syntax_pipe(t_shell *mshell, int *n)
{
	if (mshell->input[*n] == '|')
	{
		++(*n);
		while ((mshell->input[*n] == ' ' || mshell->input[*n] == '\t')
			&& mshell->input[*n] != '\0')
			++(*n);
		if (mshell->input[*n] == '|')
			return (syntax_error(mshell, mshell->input[*n]));
		if (mshell->input[*n] == '\0')
		{
			if (chenge_input(mshell, n))
				return (1);
			else
				return (2);
		}
		--(*n);
	}
	return (0);
}

int	check_syntax_qoute(t_shell *mshell, int j)
{
	while (mshell->input[j])
	{
		if (mshell->input[j] == '\'' || mshell->input[j] == '\"')
		{
			if (mshell->input[j] == '\'')
			{
				++j;
				while (mshell->input[j] != '\0' && mshell->input[j] != '\'')
					++j;
				if (mshell->input[j] == '\0')
					return (syntax_error(mshell, '\''));
			}
			else
			{
				++j;
				while (mshell->input[j] != '\0' && mshell->input[j] != '\"')
					++j;
				if (mshell->input[j] == '\0')
					return (syntax_error(mshell, '\"'));
			}
		}
		++j;
	}
	return (0);
}

int	check_syntax_input(t_shell *mshell, int n)
{
	int	ret;

	if (check_syntax_qoute(mshell, 0))
		return (1);
	while (mshell->input[n] == ' ' || mshell->input[n] == '\t')
		n++;
	if (mshell->input[n] == '|')
		return (syntax_error(mshell, '|'));
	if (mshell->input[n] == '\0')
		return (2);
	while (mshell->input[n] != '\0')
	{
		if (check_syntax_redir_out(mshell, &n))
			return (1);
		ret = check_syntax_pipe(mshell, &n);
		if (ret == 1)
			return (1);
		if (ret == 2)
			break ;
		if (check_syntax_redir_in(mshell, &n))
			return (1);
		++n;
	}
	return (0);
}
