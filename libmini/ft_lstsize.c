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
	t_list	*list;
	int		i;

	list = lst;
	i = 0;
	while (list != NULL)
	{
		i++;
		list = list->next;
	}
	return (i);
}
