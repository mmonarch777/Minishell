/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <mmonarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 20:21:49 by mmonarch          #+#    #+#             */
/*   Updated: 2021/04/30 13:02:56 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*mass;
	size_t	i;
	size_t	nb;

	i = 0;
	nb = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	mass = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof (char));
	if (mass == NULL)
		return (NULL);
	while (s1[nb] != '\0')
	{
		mass[nb] = s1[nb];
		nb++;
	}
	while (s2[i] != '\0')
	{
		mass[nb] = s2[i];
		nb++;
		i++;
	}
	mass[nb] = '\0';
	return (mass);
}
