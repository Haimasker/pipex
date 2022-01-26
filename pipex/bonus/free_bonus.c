/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumfred <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:42:15 by lumfred           #+#    #+#             */
/*   Updated: 2022/01/19 12:42:15 by lumfred          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	pipe_free(t_pipe *pipex)
{
	close(pipex->in);
	close(pipex->out);
	if (pipex->here_doc)
		unlink(".heredoc_tmp");
	free(pipex->pipe);
	error_message("environment", 1);
}

void	parent_free(t_pipe *pipex)
{
	int	i;

	i = 0;
	close(pipex->in);
	close(pipex->out);
	if (pipex->here_doc)
		unlink(".heredoc_tmp");
	while (pipex->cmd_paths[i])
		free(pipex->cmd_paths[i++]);
	free(pipex->cmd_paths);
	free(pipex->pipe);
}

void	child_free(t_pipe *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd_args[i])
		free(pipex->cmd_args[i++]);
	free(pipex->cmd_args);
	free(pipex->cmd);
}
