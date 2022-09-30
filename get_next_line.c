/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcela <amarcela@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 09:17:55 by amarcela          #+#    #+#             */
/*   Updated: 2022/09/30 10:35:48 by amarcela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_rest(char	*str)
{
	int		i;
	int		p;
	char	*rest;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free (str);
		str = NULL;
		return (NULL);
	}
	rest = ft_calloc((ft_strlen(str) - i + 1), sizeof(char));
	i++;
	p = 0;
	while (str[i] && str[i] != 0)
	{
		rest[p] = str[i];
		i++;
		p++;
	}
	free(str);
	return (rest);
}

char	*get_line(char *str)
{
	int		i;
	char	*line;
	
	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;	
	}
	if (str[i] && str[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*read_fd(int fd, char *str)
{
	int		read_size;
	char	*found;
	char	*temp;
	
	if (!str)
			str = ft_calloc(BUFFER_SIZE, sizeof(char));
	found = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	read_size = 1;
	while (read_size > 0)
	{	
		read_size = read(fd, found, BUFFER_SIZE);
		if (read_size == -1)
			return (NULL);
		found[read_size] = 0;
		temp = ft_strjoin(str, found);
		free(str);
		str = temp;
		if (ft_strchr(found, '\n'))
			break;
	}
	free(found);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	str = read_fd(fd, str);
	if (!str)
		return (NULL);
	line = get_line(str);
	str = get_rest(str);
	return (line);
}
