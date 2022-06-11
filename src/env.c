/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:02:59 by mmonarch          #+#    #+#             */
/*   Updated: 2022/06/11 19:05:54 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int 	ft_lenstr(const char *s, char c)
{
    int	len;

    len = 0;
    while (*s != c && *s != '\0')
    {
        ++(s);
        len++;
    }
    return (len);
}

static	void	*ft_clean(char **mass, int i)
{
    while (i != 0)
        free (mass[--i]);
    free (mass);
    return (NULL);
}

char	**split_for_env(const char *s, char c)
{
    char	**mass;
    int		i;

    if (!s)
        return (NULL);
    mass = (char **) malloc(3 * sizeof(char *));
    if (!mass)
        return (NULL);
    mass[0] = ft_substr((char *)s, 0, ft_lenstr(s, c));
    if (!mass[0])
        return (ft_clean(mass, 1));
    s = s + ft_lenstr(s, c) + 1;
    mass[1] = ft_strdup(s);
    if (!mass[1])
        return (ft_clean(mass, 2));
    mass[2] = NULL;
    return (mass);
}

int check_equals(char *env, char r)
{
    int i;

    i = 0;
    while (env[i] != '\0')
    {
        if (env[i] == r)
            return (0);
        i++;
    }
    return (1);
}

void   get_env(char **env, t_shell *mshell)
{
    char    **mass;
    int     i;
    int     equals;

    i = 0;
    while (env[i])
    {
        mass = split_for_env(env[i], '=');

        add_env(mshell, mass, check_equals(env[i], '='));
        free(mass);
        i++;
    }
}
