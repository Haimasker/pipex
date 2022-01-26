/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumfred <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:40:22 by lumfred           #+#    #+#             */
/*   Updated: 2022/01/19 12:40:22 by lumfred          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	message(char *message)
{
	write(2, message, ft_strlen(message));
	return (1);
}

void	error_message(char *message, int state)
{
	if (!state)
		return ;
	perror(message);
	exit(1);
}

void	pipe_error_message(char *message)
{
	write(2, "command not found: ", 19);
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
}

void	check_args(int argc, char *argv[], t_pipe *pipex)
{
	pipex->here_doc = 0;
	if (!ft_strncmp("here_doc", argv[1], 9))
		pipex->here_doc = 1;
	pipex->cmd_num = argc - 3 - pipex->here_doc;
	pipex->pipe_num = 2 * (pipex->cmd_num - 1);
}
