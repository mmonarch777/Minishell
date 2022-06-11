/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_cd_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 18:59:48 by mmonarch          #+#    #+#             */
/*   Updated: 2022/06/11 19:05:54 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	chenge_value_pwd(t_shell *mshell, char **value, char *key)
{
	t_env	*env;

	env = mshell->environment;
	while (env)
	{
		if (!ft_strcmp(key, env->key))
		{
			if (env->value != NULL)
				free(env->value);
			env->value = *value;
			break ;
		}
		env = env->next;
	}
}

void	check_oldpwd_env(t_shell *mshell)
{
	t_env	*env;
	char	**mass;

	env = mshell->environment;
	while (env)
	{
		if (!ft_strcmp(env->value, "OLDPWD"))
			return ;
		env = env->next;
	}
	mass = ft_split("OLDPWD=", '=');
	add_env(mshell, mass, 0);
	free(mass);
}

char	*home_pwd(t_shell *mshell)
{
	t_env	*env;
	char	*mass;

	env = mshell->environment;
	mass = NULL;
	while (env)
	{
		if (!ft_strcmp(env->key, "HOME"))
		{
			mass = ft_strdup(env->value);
			break ;
		}
		env = env->next;
	}
	return (mass);
}
