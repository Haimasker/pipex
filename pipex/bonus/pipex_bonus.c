/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumfred <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:38:01 by lumfred           #+#    #+#             */
/*   Updated: 2022/01/19 12:38:01 by lumfred          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	here_doc(char *arg, t_pipe *pipex)
{
	int		file;
	char	*buf;

	file = open(".heredoc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0000644);
	error_message("here_doc", file < 0);
	while (1)
	{
		write(1, "heredoc> ", 9);
		buf = get_next_line(0);
		if (!buf)
			exit(1);
		if (!ft_strncmp(arg, buf, ft_strlen(arg)))
			break ;
		write(file, buf, ft_strlen(buf));
		write(file, "\n", 1);
		free(buf);
	}
	free(buf);
	close(file);
	pipex->in = open(".heredoc_tmp", O_RDONLY);
	if (pipex->in < 0)
		unlink(".heredoc_tmp");
	error_message("here_doc", pipex->in < 0);
}

void	create_pipes(t_pipe *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->cmd_num - 1)
		if (pipe(pipex->pipe + 2 * i++) < 0)
			parent_free(pipex);
}

void	close_pipes(t_pipe *pipex)
{
	int	i;

	i = 0;
	while (i < (pipex->pipe_num))
		close(pipex->pipe[i++]);
}

void	child_process(t_pipe pipex, char **argv, char **envp)
{
	pipex.p = fork();
	if (pipex.p)
		return ;
	make_dup(&pipex);
	close_pipes(&pipex);
	pipex.cmd_args = ft_split(argv[2 + pipex.here_doc + pipex.id], ' ');
	pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		pipe_error_message(pipex.cmd_args[0]);
		child_free(&pipex);
		parent_free(&pipex);
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
	child_free(&pipex);
	parent_free(&pipex);
	perror(strerror(errno));
	exit(1);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipe	pipex;

	if (argc < 5)
		return (message("Invalid number of arguments\n"));
	check_args(argc, argv, &pipex);
	get_infile(argv, &pipex);
	get_outfile(argv[argc - 1], &pipex);
	pipex.pipe = (int *)malloc(sizeof(int) * pipex.pipe_num);
	error_message("pipe", !pipex.pipe);
	pipex.env_path = get_path(envp);
	pipex.cmd_paths = ft_split(pipex.env_path, ':');
	if (!pipex.cmd_paths)
		pipe_free(&pipex);
	create_pipes(&pipex);
	pipex.id = -1;
	while (++(pipex.id) < pipex.cmd_num)
		child_process(pipex, argv, envp);
	close_pipes(&pipex);
	waitpid(-1, NULL, 0);
	parent_free(&pipex);
	return (0);
}
