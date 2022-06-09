/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 14:23:25 by mmonarch          #+#    #+#             */
/*   Updated: 2021/04/30 13:02:56 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *mass, int a, size_t b)
{
	int				i;
	unsigned char	*muss;

	muss = (unsigned char *)mass;
	i = 0;
	while (b != 0)
	{
		muss[i] = a;
		b--;
		i++;
	}
	return (mass);
}
