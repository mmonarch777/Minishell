/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <mmonarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 20:25:24 by mmonarch          #+#    #+#             */
/*   Updated: 2021/04/30 13:02:56 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*mass;
	int		i;
	int		nb;

	mass = (char *)s;
	nb = ft_strlen(mass);
	if ((char)c == '\0')
		return (&mass[nb]);
	i = 0;
	while (mass[i] != '\0')
	{
		if (mass[i] == (char)c)
			return (mass + i);
		i++;
	}
	return (NULL);
}
