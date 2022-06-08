/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <mmonarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:44:41 by mmonarch          #+#    #+#             */
/*   Updated: 2021/04/30 13:02:56 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t nb)
{
	size_t	i;
	size_t	van;
	size_t	too;

	i = 0;
	van = ft_strlen(dst);
	too = ft_strlen(src);
	if (nb <= van || !nb)
		return (nb + too);
	while (src[i] != '\0' && (i + van) < nb - 1)
	{
		dst[van + i] = src[i];
		i++;
	}
	dst[van + i] = '\0';
	return (van + too);
}
