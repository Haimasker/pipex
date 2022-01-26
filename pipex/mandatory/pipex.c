/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumfred <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:30:43 by lumfred           #+#    #+#             */
/*   Updated: 2022/01/18 12:30:43 by lumfred          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_args_free(t_pipe *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd_args[i])
		free(pipex->cmd_args[i++]);
	free(pipex->cmd_args);
	free(pipex->cmd);
}

void	first_child_process(t_pipe pipex, char *argv[], char *envp[])
{
	int		i;

	dup2(pipex.pipe[1], 1);
	close(pipex.pipe[0]);
	dup2(pipex.in, 0);
	pipex.cmd_args = ft_split(argv[2], ' ');
	pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		cmd_args_free(&pipex);
		message("Command not found\n");
		cmd_paths_free(&pipex);
		exit(127);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
	cmd_args_free(&pipex);
	cmd_paths_free(&pipex);
	perror(strerror(errno));
	exit(1);
}

void	second_child_process(t_pipe pipex, char *argv[], char *envp[])
{
	int		i;

	dup2(pipex.pipe[0], 0);
	close(pipex.pipe[1]);
	dup2(pipex.out, 1);
	pipex.cmd_args = ft_split(argv[3], ' ');
	pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		cmd_args_free(&pipex);
		message("Command not found\n");
		cmd_paths_free(&pipex);
		exit(127);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
	cmd_args_free(&pipex);
	cmd_paths_free(&pipex);
	perror(strerror(errno));
	exit(1);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipe	pipex;

	if (argc != 5)
		return (message("Invalid number of arguments\n"));
	pipex.in = open(argv[1], O_RDONLY);
	pipex.out = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0000644);
	error_message(argv[1], (int)(pipex.in < 0));
	error_message(argv[4], (int)(pipex.out < 0));
	error_message("Pipe", (int)(pipe(pipex.pipe) < 0));
	pipex.paths = get_path(envp);
	pipex.cmd_paths = ft_split(pipex.paths, ':');
	pipex.p1 = fork();
	if (pipex.p1 == 0)
		first_child_process(pipex, argv, envp);
	pipex.p2 = fork();
	if (pipex.p2 == 0)
		second_child_process(pipex, argv, envp);
	close(pipex.pipe[0]);
	close(pipex.pipe[1]);
	waitpid(pipex.p1, NULL, 0);
	waitpid(pipex.p2, NULL, 0);
	cmd_paths_free(&pipex);
	return (0);
}
