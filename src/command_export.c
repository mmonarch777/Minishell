/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:01:02 by mmonarch          #+#    #+#             */
/*   Updated: 2022/06/12 14:19:49 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(t_env **env, t_env **print, t_env **head, int *count)
{
	(*print)->flag = 1;
	if (ft_strcmp((*print)->key, "_"))
	{
		write(1, "declare -x ", 11);
		write(1, (*print)->key, ft_strlen((*print)->key));
		if ((*print)->value != NULL && (*print)->equals == 0)
		{
			write(1, "=\"", 2);
			write(1, (*print)->value, ft_strlen((*print)->value));
			write(1, "\"\n", 2);
		}
		else
			write(1, "\n", 1);
	}
	(*env) = (*head);
	--(*count);
}

void	found_print(t_env **env, t_env **print, int count, int not_big_alpha)
{
	if (count != 1)
	{
		(*env) = (*env)->next;
		while ((*env))
		{
			if (ft_strcmp((*print)->key, (*env)->key) > 0 && !(*env)->flag)
				(*print) = (*env);
			if (not_big_alpha >= count && !(*env)->flag
				&& ft_strcmp((*print)->key, (*env)->key) > 0)
				(*print) = (*env);
			(*env) = (*env)->next;
		}
	}
}

void	check_print(t_env **env, t_env **print, int count, int not_big_alpha)
{
	t_env	*head;

	head = (*env);
	while (count > 0)
	{
		(*print) = (*env);
		if ((*env)->flag == 0)
		{
			found_print(env, print, count, not_big_alpha);
			print_env(env, print, &head, &count);
		}
		else
			(*env) = (*env)->next;
	}
}

int	sort_and_print_env(t_shell *mshell)
{
	t_env	*env;
	t_env	*print;
	int		count;
	int		not_big_alpha;

	env = mshell->environment;
	count = 0;
	not_big_alpha = 0;
	while (env)
	{
		count++;
		if (!ft_is_big_alpha(*env->key))
			not_big_alpha++;
		env = env->next;
	}
	env = mshell->environment;
	check_print(&env, &print, count, not_big_alpha);
	return (0);
}

int	my_export(t_shell *mshell)
{
	if (!ft_strcmp(mshell->lstcom->command[0], "export"))
	{
		g_last_exit_status = 0;
		if (mshell->lstcom->command[1] == NULL)
			return (sort_and_print_env(mshell));
		else
			return (add_to_env(mshell));
	}
	return (1);
}
