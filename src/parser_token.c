/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:05:47 by mmonarch          #+#    #+#             */
/*   Updated: 2022/06/11 19:05:54 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int parser_pipe(t_shell *mshell, int *i)
{
    char *buf;

    if (*i != 0)
        expand_com(mshell, i);
    mshell->lstcom->token = PIPE;
    add_command(mshell);
    ++(*i);
    while ((mshell->input[*i] == ' ' || mshell->input[*i] == '\t')
        && mshell->input[*i] != '\0')
        ++(*i);
    buf = ft_strdup(mshell->input + *i);
    free(mshell->input);
    mshell->input = buf;
    mshell->have_pipe = 1;
    *i = -1;
    return (0);
}

int parser_redirect_out(t_shell *mshell, int *i)
{
    char *buf;

    if (*i != 0)
       expand_com(mshell, i);
    mshell->lstcom->token = REDIRECT_OUT_APPEND;
    if (mshell->input[*i + 1] == '>')
        ++(*i);
    else
        mshell->lstcom->token = REDIRECT_OUT;
    ++(*i);
    while ((mshell->input[*i] == ' ' || mshell->input[*i] == '\t')
        && mshell->input[*i])
        ++(*i);
    buf = ft_strdup(mshell->input + *i);
    free(mshell->input);
    mshell->input = buf;
    *i = -1;
    return (0);
}

int parser_redirect_in(t_shell *mshell, int *i)
{
    char *buf;

    if (*i != 0)
        expand_com(mshell, i);
    mshell->lstcom->token = HERE_DOCUMENT;
    if (mshell->input[*i + 1] == '<')
        ++(*i);
    else
        mshell->lstcom->token = REDIRECT_IN;
    ++(*i);
    while ((mshell->input[*i] == ' ' || mshell->input[*i] == '\t')
        && mshell->input[*i] != '\0')
        ++(*i);
    buf = ft_strdup(mshell->input + *i);
    free(mshell->input);
    mshell->input = buf;
    *i = -1;
    return (0);
}

int parser_token(char symbol, int *i, t_shell *mshell)
{
    if (symbol == '|')
        return (parser_pipe(mshell, i));
    if (symbol == '>')
        return (parser_redirect_out(mshell, i));
    if (symbol == '<')
        return (parser_redirect_in(mshell, i));
    return (0);
}
