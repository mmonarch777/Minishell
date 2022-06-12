/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <mmonarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:11:27 by mmonarch          #+#    #+#             */
/*   Updated: 2021/04/30 13:02:56 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_rav(const char *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s, const char *set)
{
	char	*mass;
	int		i;
	int		nb;
	int		go;

	if (!s || !set)
		return (NULL);
	nb = ft_strlen(s);
	i = 0;
	while (ft_rav(set, s[i]))
		i++;
	while (ft_rav(set, s[nb - 1]) && nb > i)
		nb--;
	go = 0;
	mass = (char *) malloc((nb - i) * sizeof(char) + 1);
	if (mass == NULL)
		return (NULL);
	while (i < nb)
		mass[go++] = s[i++];
	mass[go] = '\0';
	return (mass);
}
