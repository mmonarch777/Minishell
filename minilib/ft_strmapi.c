/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <mmonarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 23:49:47 by mmonarch          #+#    #+#             */
/*   Updated: 2021/04/30 13:02:56 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char ))
{
	char	*mass;
	size_t	i;
	size_t	nb;

	if (!s)
		return (NULL);
	i = 0;
	nb = ft_strlen(s);
	mass = (char *)malloc(nb * sizeof (char) + 1);
	if (mass == NULL)
		return (NULL);
	while (nb != 0)
	{
		mass[i] = f(i, s[i]);
		i++;
		nb--;
	}
	mass[i] = '\0';
	return (mass);
}
