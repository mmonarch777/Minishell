/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comply_execve.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 09:30:20 by mmonarch          #+#    #+#             */
/*   Updated: 2022/06/12 11:06:29 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv_value(t_env *lst, char *key)
{
	t_env	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (!ft_strcmp(key, tmp->key))
			return (tmp->value);
		tmp = tmp->next;
	}
	return ("");
}

char	*prog_name(t_shell *mshell)
{
	int		i;
	char	*mass;
	char	*mass1;
	char	*com;
	char	**path;

	com = mshell->lstcom->command[0];
	path = ft_split(ft_getenv_value(mshell->environment, "PATH"), ':');
	i = 0;
	while (path[i])
	{
		mass1 = ft_strjoin("/", mshell->lstcom->command[0]);
		mass = ft_strjoin(path[i], mass1);
		free(mass1);
		free(path[i]);
		if (access(mass, 0) == 0)
			com = mass;
		else
			free(mass);
		i++;
	}
	free(path);
	return (com);
}

int	size_env(t_shell *mshell)
{
	t_env	*env;
	int		i;

	env = mshell->environment;
	i = 0;
	while (env)
	{
		++i;
		env = env->next;
	}
	return (i);
}

char	**new_arr_env(t_shell *mshell)
{
	t_env	*env;
	char	**mass_env;
	char	*mass;
	int		i;

	env = mshell->environment;
	i = size_env(mshell);
	mass_env = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (env)
	{
		mass = ft_strjoin(env->key, "=");
		mass_env[i] = ft_strjoin(mass, env->value);
		free(mass);
		env = env->next;
		i++;
	}
	mass_env[i] = NULL;
	return (mass_env);
}
