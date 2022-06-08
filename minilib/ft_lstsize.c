/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <mmonarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 17:42:50 by mmonarch          #+#    #+#             */
/*   Updated: 2021/04/27 17:52:03 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*ggvp;
	int		i;

	ggvp = lst;
	i = 0;
	while (ggvp != NULL)
	{
		i++;
		ggvp = ggvp->next;
	}
	return (i);
}
