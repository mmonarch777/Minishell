/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_low_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 10:07:15 by mmonarch          #+#    #+#             */
/*   Updated: 2022/06/12 10:07:17 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_low_alpha(int a)
{
	if (a >= 97 && a <= 122)
		return (1);
	else
		return (0);
}
