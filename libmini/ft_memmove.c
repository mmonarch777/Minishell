/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <mmonarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 21:28:11 by mmonarch          #+#    #+#             */
/*   Updated: 2021/04/30 13:02:56 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *stc, size_t len)
{
	unsigned char	*van;
	unsigned char	*too;

	van = (unsigned char *)dst;
	too = (unsigned char *)stc;
	if (!dst && !stc)
		return (NULL);
	if (van > too)
	{
		while (len--)
			van[len] = too[len];
	}
	else
		van = ft_memcpy(dst, stc, len);
	return (van);
}
