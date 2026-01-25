/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoukaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 11:04:14 by aoukaamo          #+#    #+#             */
/*   Updated: 2026/01/23 11:04:19 by aoukaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*check_line(char *line, char *buff, ssize_t bytes_read)
{
	char	*tmp;

	if (bytes_read == 0)
		return (line);
	buff[bytes_read] = '\0';
	if (line == NULL)
		line = ft_strdup(buff);
	else
	{
		tmp = line;
		line = ft_strjoin(line, buff);
		free(tmp);
	}
	return (line);
}

static char	*get_line(int fd, char *buff)
{
	ssize_t	bytes_read;
	char	*line;

	line = NULL;
	bytes_read = 1;
	while (ft_strchr(line, '\n') == NULL && bytes_read > 0)
	{
		bytes_read = read(fd, buff, 1);
		if (bytes_read < 0)
		{
			free(buff);
			free(line);
			return (NULL);
		}
		line = check_line(line, buff, bytes_read);
		if (line == NULL)
		{
			free(buff);
			return (NULL);
		}
	}
	free(buff);
	return (line);
}

char	*get_next_line(int fd)
{
	char	*buff;

	buff = malloc(2);
	if (!buff)
		return (NULL);
	return (get_line(fd, buff));
}
