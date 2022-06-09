/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <mmonarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 16:20:09 by mmonarch          #+#    #+#             */
/*   Updated: 2021/04/30 13:02:56 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *last, const void *mass, size_t n)
{
	size_t	i;

	i = 0;
	if (!mass && !last)
		return (last);
	while (n != 0)
	{
		((char *)last)[i] = ((char *)mass)[i];
		i++;
		n--;
	}
	return (last);
}
