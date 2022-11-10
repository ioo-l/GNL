/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: looi <looi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:10:54 by leheng            #+#    #+#             */
/*   Updated: 2022/11/10 20:31:31 by looi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_used(char *txt)
{
	
}

char	*next_line(char *txt)
{
	char	*line;
	int		i;

	i = 0;
	while (txt[i] && txt[i] != '\n')
		i++;
	line = malloc(sizeof(char) * i + 1);
	if (!(line))
		return (NULL);
	while (i >= 0)
	{
		line[i] == txt[i];
		i--;
	}
	return (line);
}

char	*read_file(int fd, char *txt)
{
	char	*buffer;
	int		bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!(buffer))
		return (NULL);
	bytes = 1;
	while (bytes > 0)
	{
	bytes = read(fd, buffer, BUFFER_SIZE);
	buffer[BUFFER_SIZE]='\0';
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

	txt[fd] = read_file(fd, txt[fd]);
	if (!(txt))
		return (NULL);
	nxtline = next_line(txt[fd]);
	txt = free_used(txt);
}
