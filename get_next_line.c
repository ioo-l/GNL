/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leheng <leheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:10:54 by leheng            #+#    #+#             */
/*   Updated: 2022/11/14 11:44:54 by leheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_null(char *buff)
{
	while (*buff)
	{
		if (*buff == '\0')
			return (1);
		buff++;
	}
	return (0);
}

int	ft_strlen(char *string)
{
	int	i;

	i = 0;
	while (string[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *txt, char *buff)
{
	char	*new;
	int		i;
	int		cbuff;
	int		ctxt;

	cbuff = ft_strlen(buff);
	if (!(txt))
		ctxt = 0;
	else
		ctxt = ft_strlen(txt);
	new = malloc(sizeof(char) * (cbuff + ctxt + 100));
	if (!(new))
		return (NULL);
	i = 0;
	while (i < ctxt)
		*new ++ = txt[i++];
	i = 0;
	while (i < cbuff)
		*new ++ = buff[i++];
	*new = '\0';
	if (txt)
		free(txt);
	return (new - ctxt - cbuff);
}

//Above are utils functions

char	*free_used(char *txt)
{
	int		i;
	int		n;
	char	*hold;

	i = 0;
	while (txt[i] && txt[i] != '\n')
		i++;
	hold = malloc((ft_strlen(txt) - i) * sizeof(char) + 100);
	if (!(hold))
		return (NULL);
	i += 1;
	n = 0;
	while (txt[i])
		hold[n++] = txt[i++];
	hold[n] = '\0';
	free (txt);
	return (hold);
}

char	*next_line(char *txt)
{
	char	*line;
	int		i;

	i = 0;
	while (txt[i] && txt[i] != '\n')
		i++;
	line = malloc(sizeof(char) * i + 100);
	if (!(line))
		return (NULL);
	while (i >= 0)
	{
		line[i] = txt[i];
		i--;
	}
	return (line);
}

char	*read_file(int fd, char *txt)
{
	char	*buffer;
	int		bytes;

	buffer = malloc((BUFFER_SIZE + 100) * sizeof(char));
	if (!(buffer))
		return (NULL);
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[BUFFER_SIZE] = '\0';
		if (bytes <= 0)
			break ;
		txt = ft_strjoin(txt, buffer);
	}
	free (buffer);
	if (bytes < 0)
		return (NULL);
	return (txt);
}

char	*get_next_line(int fd)
{
	static char	*txt[1024];
	char		*nxtline;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	txt[fd] = read_file(fd, txt[fd]);
	if (!(txt[fd]))
		return (NULL);
	nxtline = next_line(txt[fd]);
	txt[fd] = free_used(txt[fd]);
	return (nxtline);
}

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*nextline;

	fd = open("abc.txt", O_RDONLY);
	nextline = get_next_line(fd);
	printf("%s", nextline);
	free(nextline);
	nextline = get_next_line(fd);
	printf("%s", nextline);
	free(nextline);
	nextline = get_next_line(fd);
	printf("%s", nextline);
	free(nextline);
	nextline = get_next_line(fd);
	printf("%s", nextline);
	free(nextline);
	nextline = get_next_line(fd);
	printf("%s", nextline);
	free(nextline);

	close(fd);
}