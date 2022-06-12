/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comply_com2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:02:43 by mmonarch          #+#    #+#             */
/*   Updated: 2022/06/12 09:25:11 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	comply_without_pipe(t_shell *mshell)
{
	if (!my_pwd(mshell))
		return (0);
	else if (!my_echo(mshell))
		return (0);
	else if (!my_cd(mshell))
		return (0);
	else if (!my_env(mshell))
		return (0);
	else if (!my_export(mshell))
		return (0);
	else if (!my_unset(mshell))
		return (0);
	else if (!my_exit(mshell))
		return (0);
	else
		if (comply_with_pipe(mshell))
			return (1);
	return (0);
}

int	my_com(t_shell *mshell)
{
	if (!my_pwd(mshell))
		return (0);
	else if (!my_echo(mshell))
		return (0);
	else if (!my_cd(mshell))
		return (0);
	else if (!my_env(mshell))
		return (0);
	else if (!my_export(mshell))
		return (0);
	else if (!my_unset(mshell))
		return (0);
	else if (!my_exit(mshell))
		return (0);
	return (1);
}
