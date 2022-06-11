/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:01:40 by mmonarch          #+#    #+#             */
/*   Updated: 2022/06/11 19:05:54 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	my_pwd(t_shell *mshell)
{
	char	*mass;

	if (!ft_strcmp("pwd", mshell->lstcom->command[0]))
	{
		mass = getcwd(NULL, 0);
		write(1, mass, ft_strlen(mass));
		write(1, "\n", 1);
		free(mass);
		last_exit_status = 0;
		return (0);
	}
	return (1);
}
