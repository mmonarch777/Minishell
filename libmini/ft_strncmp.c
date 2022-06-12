/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <mmonarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 21:41:30 by mmonarch          #+#    #+#             */
/*   Updated: 2021/04/30 13:02:56 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*van;
	unsigned char	*too;
	size_t			i;

	van = (unsigned char *)s1;
	too = (unsigned char *)s2;
	i = 0;
	while (n != 0)
	{
		if (van[i] == '\0' && too[i] == '\0')
			return (0);
		if (van[i] > too[i])
			return (van[i] - too[i]);
		if (van[i] < too[i])
			return (van[i] - too[i]);
		i++;
		n--;
	}
	return (0);
}
