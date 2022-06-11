/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 18:59:28 by mmonarch          #+#    #+#             */
/*   Updated: 2022/06/11 20:08:19 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_value_env(t_shell *mshell, char *key)
{
	t_env	*env;
	char	*mass;

	env = mshell->environment;
	while (env)
	{
		if (!ft_strcmp(env->key, key))
		{
			mass = ft_strdup(env->value);
			return (mass);
		}
		env = env->next;
	}
	return (NULL);
}

int	swap_pwd(t_shell *mshell)
{
	char	*old;
	char	*new;

	old = get_value_env(mshell, "OLDPWD");
	if (!old)
		return (error_set_pwd(mshell, "OLDPWD"));
	new = getcwd(NULL, 0);
	if (!new)
		return (error_getcwd(mshell));
	if (chdir(old))
	{
		free(new);
		return (error_directory(mshell, &old));
	}
	chenge_value_pwd(mshell, &new, "OLDPWD");
	chenge_value_pwd(mshell, &old, "PWD");
	ft_putendl_fd(old, 1);
	last_exit_status = 0;
	return (0);
}

int	get_home_pwd(t_shell *mshell)
{
	char	*old;
	char	*home;

	old = getcwd(NULL, 0);
	if (!old)
		return (error_getcwd(mshell));
	home = home_pwd(mshell);
	if (!home)
		return (error_set_pwd(mshell, "HOME"));
	if (chdir(home))
	{
		free(old);
		return (error_directory(mshell, &home));
	}
	check_oldpwd_env(mshell);
	chenge_value_pwd(mshell, &old, "OLDPWD");
	chenge_value_pwd(mshell, &home, "PWD");
	last_exit_status = 0;
	return (0);
}

int	chenge_pwd(t_shell *mshell)
{
	char	*new;
	char	*old;

	old = getcwd(NULL, 0);
	if (!old)
		return (error_getcwd(mshell));
	if (chdir(mshell->lstcom->command[1]))
	{
		free(old);
		return (error_directory(mshell, NULL));
	}
	new = getcwd(NULL, 0);
	if (!new)
		return (error_getcwd(mshell));
	check_oldpwd_env(mshell);
	chenge_value_pwd(mshell, &old, "OLDPWD");
	chenge_value_pwd(mshell, &new, "PWD");
	last_exit_status = 0;
	return (0);
}

int	my_cd(t_shell *mshell)
{
	int	i;

	i = 0;
	if (!ft_strcmp("cd", mshell->lstcom->command[0]))
	{
		while (mshell->lstcom->command[i] != NULL)
			++i;
		if (i == 3)
			return (error_too_many_arguments(mshell));
		if ((mshell->lstcom->command[1] == NULL)
			|| !ft_strcmp("~", mshell->lstcom->command[1]))
			return (get_home_pwd(mshell));
		else if (!ft_strcmp("-", mshell->lstcom->command[1]))
			return (swap_pwd(mshell));
		else
			return (chenge_pwd(mshell));
	}
	return (1);
}
