/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumfred <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 10:41:08 by lumfred           #+#    #+#             */
/*   Updated: 2022/01/19 10:41:08 by lumfred          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	make_dup(t_pipe *pipex)
{
	if (pipex->id == 0)
	{
		dup2(pipex->in, 0);
		dup2(pipex->pipe[1], 1);
	}
	else if (pipex->id == pipex->cmd_num - 1)
	{
		dup2(pipex->pipe[2 * pipex->id - 2], 0);
		dup2(pipex->out, 1);
	}
	else
	{
		dup2(pipex->pipe[2 * pipex->id - 2], 0);
		dup2(pipex->pipe[2 * pipex->id + 1], 1);
	}
}

char	*get_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, F_OK | X_OK) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

void	get_infile(char *argv[], t_pipe *pipex)
{
	if (pipex->here_doc)
		here_doc(argv[2], pipex);
	else
	{
		pipex->in = open(argv[1], O_RDONLY);
		error_message(argv[1], (int)(pipex->in < 0));
	}
}

void	get_outfile(char *arg, t_pipe *pipex)
{
	if (pipex->here_doc)
		pipex->out = open(arg, O_WRONLY | O_CREAT | O_APPEND, 0000644);
	else
		pipex->out = open(arg, O_CREAT | O_RDWR | O_TRUNC, 0000644);
	error_message(arg, pipex->out < 0);
}
