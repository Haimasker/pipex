/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumfred <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:30:16 by lumfred           #+#    #+#             */
/*   Updated: 2022/01/18 12:30:16 by lumfred          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>

# include <sys/types.h>
# include <sys/uio.h>
# include <sys/stat.h>
# include <sys/wait.h>

# include <errno.h>

typedef struct s_pipe
{
	pid_t	p1;
	pid_t	p2;
	int		pipe[2];
	int		in;
	int		out;
	char	*paths;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
}	t_pipe;

void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);

int		message(char *message);
void	error_message(char *message, int state);

void	cmd_paths_free(t_pipe *pipex);
void	cmd_args_free(t_pipe *pipex);

char	*get_path(char **envp);
char	*get_cmd(char **paths, char *cmd);

void	first_child_process(t_pipe pipex, char *argv[], char *envp[]);
void	second_child_process(t_pipe pipex, char *argv[], char *envp[]);

#endif
