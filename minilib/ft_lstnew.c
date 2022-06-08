/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <mmonarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:54:12 by mmonarch          #+#    #+#             */
/*   Updated: 2021/04/27 15:59:45 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*mass;

	mass = (t_list *)malloc(sizeof (t_list));
	if (!mass)
		return (NULL);
	mass->content = content;
	mass->next = NULL;
	return (mass);
}
