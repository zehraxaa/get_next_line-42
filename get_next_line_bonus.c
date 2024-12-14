/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 23:56:59 by marvin            #+#    #+#             */
/*   Updated: 2024/12/14 23:56:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*joinfunc(char *stash, char *buffer, int fd)
{
	int	count;

	count = 1;
	while (!ft_strchr(stash, '\n') && count != 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == -1)
		{
			free(stash);
			free(buffer);
			return (NULL);
		}
		buffer[count] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*getbefore(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] != '\n' && stash[i])
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i])
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*getafter(char *stash)
{
	char	*newstash;
	int		i;
	int		j;

	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	newstash = (char *)malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!newstash)
		return (NULL);
	j = 0;
	i++;
	while (stash[i])
		newstash[j++] = stash[i++];
	newstash[j] = '\0';
	free(stash);
	return (newstash);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*stash[1024];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	stash[fd] = joinfunc(stash[fd], buffer, fd);
	if (!stash[fd])
		return (NULL);
	line = getbefore(stash[fd]);
	stash[fd] = getafter(stash[fd]);
	return (line);
}
