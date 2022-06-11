/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:00:17 by mmonarch          #+#    #+#             */
/*   Updated: 2022/06/11 19:05:54 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	my_env(t_shell *mshell)
{
	t_env	*env;

	if (!strcmp(mshell->lstcom->command[0], "env"))
	{
		env = mshell->environment;
		while (env)
		{
			if (env->equals == 0)
			{
				write(1, env->key, ft_strlen(env->key));
				write(1, "=", 1);
				if (env->value != NULL)
					write(1, env->value, ft_strlen(env->value));
				write(1, "\n", 1);
			}
			env = env->next;
		}
		last_exit_status = 0;
		return (0);
	}
	return (1);
}
