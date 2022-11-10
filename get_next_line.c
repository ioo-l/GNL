/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leheng <leheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:10:54 by leheng            #+#    #+#             */
/*   Updated: 2022/11/10 13:13:23 by leheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		if (bytes < 0)
		{
			free(buffer);
			return (NULL);
		}
		txt = ft_strjoin(txt, buffer);
		if (check_n == 0)
			break;
	}
	free (buffer);
	return (txt);
}

char	*get_next_line(int fd)
{
	static char	*txt[1024];
	char		*nxtline;

	txt[fd] = read_file(fd, txt[fd]);
}