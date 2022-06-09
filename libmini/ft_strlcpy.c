/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <mmonarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:27:02 by mmonarch          #+#    #+#             */
/*   Updated: 2021/04/30 13:02:56 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t nb)
{
	size_t	i;

	i = 0;
	if (nb == 0)
		return (ft_strlen(src));
	if (!dst && !src)
		return (0);
	while (src[i] != '\0' && i < (nb - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
