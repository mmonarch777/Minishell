/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_export2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:01:23 by mmonarch          #+#    #+#             */
/*   Updated: 2022/06/11 20:14:49 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	error_valid(t_shell *mshell, char *mass)
{
	char	*command;

	command = mshell->lstcom->command[0];
	write(2, "minishell: ", 11);
	write(2, command, ft_strlen(command));
	write(2, ": `", 3);
	write(2, mass, ft_strlen(mass));
	write(2, "': not a valid identifier\n", 26);
	g_last_exit_status = 1;
	return (1);
}

int	check_dup_and_valid(t_shell *mshell, char *mass)
{
	t_env	*env;
	int		i;

	env = mshell->environment;
	i = 0;
	while (mass[i] != '\0')
	{
		if (i == 0)
		{
			if (!(ft_isalpha(mass[i]) || mass[i] == '_'))
				return (error_valid(mshell, mass));
		}
		else if (!(ft_isalnum(mass[i]) || mass[i] == '_' || mass[i] == '='))
			return (error_valid(mshell, mass));
		++i;
	}
	while (env)
	{
		if (!ft_strcmp(env->key, mass))
			return (1);
		env = env->next;
	}
	return (0);
}

int	add_to_env(t_shell *mshell)
{
	int		i;
	char	**mass;

	i = 1;
	while (mshell->lstcom->command[i] != NULL)
	{
		if (check_dup_and_valid(mshell, mshell->lstcom->command[i]))
		{
			i++;
			continue ;
		}
		mass = split_for_env(mshell->lstcom->command[i], '=');
		add_env(mshell, mass, check_equals(mshell->lstcom->command[i], '='));
		free(mass);
		i++;
	}
	return (0);
}
