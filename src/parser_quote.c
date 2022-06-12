/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:05:09 by mmonarch          #+#    #+#             */
/*   Updated: 2022/06/11 19:05:54 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	one_quote(t_shell *mshell, int *i)
{
	char	*mass;
	char	*mass1;
	char	*mass2;
	char	*mass3;
	int		nb;

	nb = *i;
	while (mshell->input[++(*i)] != '\0')
		if (mshell->input[*i] == '\'')
			break ;
	mass = ft_substr(mshell->input, 0, nb);
	mass1 = ft_substr(mshell->input, nb + 1, *i - nb -1);
	mass2 = ft_strdup(mshell->input + *i + 1);
	mass3 = ft_strjoin(mass, mass1);
	free(mass);
	free(mass1);
	mass = ft_strjoin(mass3, mass2);
	free(mass3);
	free(mass2);
	free(mshell->input);
	mshell->input = mass;
	*i = *i - 2;
	return (0);
}

void	find_quote(t_shell *mshell, int *i)
{
	while (mshell->input[++(*i)] != '\0')
	{
		if (mshell->input[*i] == '\"')
			break ;
		if (mshell->input[*i] == '$' && mshell->input[*i + 1] != '\"')
			check_dollar(mshell, i);
	}
}

int	two_quote(t_shell *mshell, int *i)
{
	char	*mass;
	char	*mass1;
	char	*mass2;
	char	*mass3;
	int		nb;

	nb = *i;
	find_quote(mshell, i);
	mass = ft_substr(mshell->input, 0, nb);
	mass1 = ft_substr(mshell->input, nb + 1, *i - nb - 1);
	mass2 = ft_strdup(mshell->input + *i + 1);
	mass3 = ft_strjoin(mass, mass1);
	free(mass);
	free(mass1);
	mass = ft_strjoin(mass3, mass2);
	free(mass3);
	free(mass2);
	free(mshell->input);
	mshell->input = mass;
	*i = *i - 2;
	return (0);
}
