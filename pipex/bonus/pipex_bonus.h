/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumfred <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 10:31:25 by lumfred           #+#    #+#             */
/*   Updated: 2022/01/19 10:31:25 by lumfred          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

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
	pid_t	p;
	int		*pipe;
	int		pipe_num;
	int		in;
	int		out;
	char	*paths;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
	int		cmd_num;
	char	*env_path;
	int		here_doc;
	int		id;

}	t_pipe;

void	check_args(int argc, char *argv[], t_pipe *pipex);
int		message(char *message);
void	error_message(char *message, int state);
void	pipe_error_message(char *message);

void	pipe_free(t_pipe *pipex);
void	parent_free(t_pipe *pipex);
void	child_free(t_pipe *pipex);

char	*get_path(char **envp);
char	*get_cmd(char **paths, char *cmd);
void	get_infile(char *argv[], t_pipe *pipex);
void	get_outfile(char *arg, t_pipe *pipex);

void	make_dup(t_pipe *pipex);
void	here_doc(char *arg, t_pipe *pipex);
void	create_pipes(t_pipe *pipex);
void	close_pipes(t_pipe *pipex);
void	child_process(t_pipe pipex, char **argv, char **envp);

void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strdup_gnl(const char *s1);
char	*ft_substr_gnl(char const *s, unsigned int start, size_t len);
char	*make_line(char **str, int chars, char **buf);
char	*get_next_line(int fd);

#endif
