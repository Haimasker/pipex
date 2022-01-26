/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumfred <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:36:12 by lumfred           #+#    #+#             */
/*   Updated: 2021/11/28 11:39:04 by lumfred          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

char	*make_line(char **str, int chars, char **buf)
{
	int		index;
	char	*line;
	char	*tmp;

	free(*buf);
	tmp = NULL;
	if (chars < 0 || *str == NULL)
		return (NULL);
	if (!chars && !ft_strchr(*str, '\n'))
	{
		line = ft_strdup_gnl(*str);
		free(*str);
		*str = NULL;
		return (line);
	}
	index = 0;
	while ((*str)[index] != '\n')
		index++;
	line = ft_substr_gnl(*str, 0, index + 1);
	if ((int)ft_strlen(*str) - index - 1 >= 1)
		tmp = ft_substr_gnl(*str, index + 1, ft_strlen(*str) - index - 1);
	free(*str);
	*str = tmp;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buf;
	char		*tmp;
	int			chars;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	chars = read(fd, buf, BUFFER_SIZE);
	while (chars > 0)
	{
		buf[chars] = '\0';
		if (!str)
			tmp = ft_strdup_gnl(buf);
		else
			tmp = ft_strjoin_gnl(str, buf);
		str = tmp;
		if (ft_strchr(str, '\n'))
			break ;
		chars = read(fd, buf, BUFFER_SIZE);
	}
	return (make_line(&str, chars, &buf));
}
