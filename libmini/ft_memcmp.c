/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <mmonarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:06:18 by mmonarch          #+#    #+#             */
/*   Updated: 2021/04/30 13:02:56 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *arr, const void *arr2, size_t n)
{
	unsigned char	*van;
	unsigned char	*too;
	size_t			i;

	van = (unsigned char *)arr;
	too = (unsigned char *)arr2;
	i = 0;
	while (n != 0)
	{
		if (van[i] > too[i])
			return (van[i] - too[i]);
		if (van[i] < too[i])
			return (van[i] - too[i]);
		i++;
		n--;
	}
	return (0);
}
