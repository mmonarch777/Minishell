/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <mmonarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 20:43:13 by mmonarch          #+#    #+#             */
/*   Updated: 2021/04/27 23:06:34 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mass;

	if (!lst)
		return (NULL);
	mass = ft_lstnew(f(lst->content));
	if (mass == NULL)
	{
		ft_lstclear(&mass, del);
		return (NULL);
	}
	if (lst->next != NULL)
		mass->next = ft_lstmap(lst->next, f, del);
	return (mass);
}
