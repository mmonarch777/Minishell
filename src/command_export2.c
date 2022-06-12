/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_export2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:01:23 by mmonarch          #+#    #+#             */
/*   Updated: 2022/06/12 19:03:54 by mmonarch         ###   ########.fr       */
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

int	check_valid(t_shell *mshell, char *mass, int i)
{
	while (mass[i] != '\0')
	{
		if (i == 0)
		{
			if (!(ft_isalpha(mass[i]) || mass[i] == '_'))
			{
				error_valid(mshell, mass);
				return (0);
			}
		}
		else if (mass[i] == '=')
			break ;
		else if (!(ft_isalnum(mass[i]) || mass[i] == '_'))
		{
			error_valid(mshell, mass);
			return (0);
		}
		++i;
	}
	return (i);
}

void	double_free(char **key, char **value)
{
	if (key != NULL)
		free(*key);
	if (key != NULL)
		free(*value);
}

int	check_dup_and_valid(t_shell *mshell, char *mass)
{
	t_env	*env;
	char	*key;
	char	*value;
	int		i;

	env = mshell->environment;
	i = check_valid(mshell, mass, 0);
	if (i == 0)
		return (1);
	key = ft_substr(mass, 0, i);
	value = ft_strdup(mass + i + 1);
	while (env)
	{
		if (!ft_strcmp(env->key, key))
		{
			free(key);
			if (env->value != NULL)
				free(env->value);
			env->value = value;
			return (1);
		}
		env = env->next;
	}
	double_free(&key, &value);
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
