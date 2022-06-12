/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:05:36 by mmonarch          #+#    #+#             */
/*   Updated: 2022/06/12 09:42:52 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	split_output_file(t_shell *mshell, int *i)
{
	if (mshell->lstcom->output_file != NULL)
	{
		close(mshell->lstcom->fd_out_file);
		free(mshell->lstcom->output_file);
		mshell->lstcom->output_file = NULL;
	}
	mshell->lstcom->output_file = ft_substr(mshell->input, 0, *i);
	if (mshell->lstcom->output_file == NULL)
		return (object_error(mshell, "malloc output_file error"));
	if (mshell->lstcom->token == REDIRECT_OUT)
		mshell->lstcom->fd_out_file = open(mshell->lstcom->output_file, O_WRONLY
				| O_CREAT | O_TRUNC, 0744);
	else
		mshell->lstcom->fd_out_file = open(mshell->lstcom->output_file, O_RDWR
				| O_CREAT | O_APPEND, 0744);
	if (mshell->lstcom->fd_out_file == -1)
		return (object_error(mshell, "fd output_file error"));
	mshell->lstcom->token = 0;
	return (0);
}

int	split_input_file(t_shell *mshell, int *i)
{
	if (mshell->lstcom->input_file != NULL)
	{
		close(mshell->lstcom->fd_in_file);
		free(mshell->lstcom->input_file);
		mshell->lstcom->input_file = NULL;
	}
	mshell->lstcom->input_file = ft_substr(mshell->input, 0, *i);
	if (mshell->lstcom->input_file == NULL)
		return (object_error(mshell, "malloc input_file error"));
	mshell->lstcom->fd_in_file
		= open(mshell->lstcom->input_file, O_RDONLY, 0744);
	if (mshell->lstcom->fd_in_file == -1)
		return (object_error(mshell, mshell->lstcom->input_file));
	mshell->lstcom->token = 0;
	return (0);
}

int	split_here_document(t_shell *mshell, int *i)
{
	char	*buf;

	if (mshell->lstcom->here_document != NULL)
		free_here_document(mshell);
	mshell->lstcom->here_document = ft_substr(mshell->input, 0, *i);
	if (mshell->lstcom->here_document == NULL
		|| pipe(mshell->lstcom->fd_here_document))
		object_error(mshell, "create here_document");
	while (1)
	{
		buf = readline("> ");
		if (!buf)
			break ;
		if (!ft_strcmp(mshell->lstcom->here_document, buf))
			break ;
		write(mshell->lstcom->fd_here_document[1], buf, ft_strlen(buf));
		write(mshell->lstcom->fd_here_document[1], "\n", 1);
		free(buf);
	}
	free(buf);
	close(mshell->lstcom->fd_here_document[1]);
	mshell->lstcom->token = 0;
	return (0);
}

int	split_input(t_shell *mshell, int *i)
{
	char	*buf;

	buf = NULL;
	expand_com(mshell, i);
	while ((mshell->input[*i] == ' ' || mshell->input[*i] == '\t')
		&& mshell->input[*i])
		(*i)++;
	if (mshell->input[*i] != '\0')
		buf = ft_strdup(mshell->input + *i);
	free(mshell->input);
	*i = -1;
	mshell->input = buf;
	return (0);
}
