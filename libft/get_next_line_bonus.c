/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 13:57:33 by yang              #+#    #+#             */
/*   Updated: 2021/11/24 15:08:05 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	next_line(int fd, char **content, char **line)
{
	char	*temp;
	size_t	i;

	i = 0;
	temp = NULL;
	while (content[fd][i] != '\n' && content[fd][i] != '\0')
		i++;
	if (content[fd][i] == '\n')
	{
		*line = ft_substr1(content[fd], 0, i);
		temp = ft_strdup1(content[fd] + i + 1);
		free(content[fd]);
		content[fd] = temp;
	}
	else
	{
		*line = ft_strdup1(content[fd]);
		free(content[fd]);
		content[fd] = NULL;
	}
	if (content[fd] == NULL)
		return (0);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*temp;
	static char	*content[MAX_FILE];
	int			ret;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!content[fd])
		content[fd] = ft_calloc1(1, 1);
	ret = read(fd, buffer, BUFFER_SIZE);
	while (ret > 0)
	{
		buffer[ret] = '\0';
		temp = ft_strjoin1(content[fd], buffer);
		free(content[fd]);
		content[fd] = temp;
		if (ft_strchr1(buffer, '\n'))
			break ;
		ret = read(fd, buffer, BUFFER_SIZE);
	}
	if (ret >= 0)
		return (next_line(fd, content, line));
	else
		free (content[fd]);
	return (-1);
}
