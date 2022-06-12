/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <mmonarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 20:52:34 by mmonarch          #+#    #+#             */
/*   Updated: 2021/04/30 13:02:56 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_size(int i)
{
	int		nb;

	nb = 0;
	if (i <= 0)
		nb++;
	while (i != 0)
	{
		nb++;
		i = i / 10;
	}
	return (nb);
}

char	*ft_itoa(int n)
{
	char	*mass;
	long	i;
	size_t	nb;

	i = n;
	nb = ft_size(n);
	mass = (char *) malloc((nb + 1) * sizeof (char));
	if (mass == NULL)
		return (NULL);
	mass[nb] = '\0';
	if (i < 0)
	{
		mass[0] = '-';
		i = i * (-1);
	}
	if (i == 0)
		mass[0] = 48;
	while (i > 0)
	{
		nb--;
		mass[nb] = (i % 10) + 48;
		i = i / 10;
	}
	return (mass);
}
