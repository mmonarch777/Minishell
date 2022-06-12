/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <mmonarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 01:47:56 by mmonarch          #+#    #+#             */
/*   Updated: 2022/06/12 10:03:13 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_strings(const char *s, char c)
{
	int	i;
	int	nb;

	nb = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			nb++;
		}
	}
	return (nb);
}

static	int	ft_lenstr(char *s, char c)
{
	int	len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		s++;
		len++;
	}
	return (len);
}

static	void	*ft_clean(char **mass, int i)
{
	while (i--)
		free (mass[i]);
	free (mass);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**mass;
	int		string;
	int		i;

	if (!s)
		return (NULL);
	string = ft_strings(s, c);
	mass = (char **) malloc((string + 1) * sizeof(char *));
	if (!mass)
		return (NULL);
	i = 0;
	while (i < string)
	{
		while (*s == c && *s != '\0')
			s++;
		mass[i] = ft_substr((char *)s, 0, ft_lenstr((char *)s, c));
		if (!mass[i])
			return (ft_clean(mass, i));
		s = s + ft_lenstr((char *)s, c);
		i++;
	}
	mass[i] = NULL;
	return (mass);
}
