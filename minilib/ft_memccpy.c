/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <mmonarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:51:59 by mmonarch          #+#    #+#             */
/*   Updated: 2021/04/30 13:02:56 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dast, const void *cat, int c, size_t n)
{
	unsigned char	*van;
	unsigned char	*too;
	size_t			i;

	van = (unsigned char *)dast;
	too = (unsigned char *)cat;
	i = 0;
	if (!van && !too)
		return (NULL);
	while (n--)
	{
		van[i] = too[i];
		if (too[i] == (unsigned char)c)
			return (dast + i +1);
		i++;
	}
	return (NULL);
}
