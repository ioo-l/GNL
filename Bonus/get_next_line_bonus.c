/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: looi <looi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:10:54 by leheng            #+#    #+#             */
/*   Updated: 2022/11/14 18:31:24 by looi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*free_used(char *txt)
{
	int		i;
	int		n;
	char	*hold;

	i = 0;
	while (txt[i] && txt[i] != '\n')
		i++;
	hold = malloc((ft_strlen(txt) - i) * sizeof(char) + 1);
	if (!(hold))
		return (NULL);
	n = 0;
	while (txt[i])
		hold[n++] = txt[1 + i++];
	hold[n] = '\0';
	free (txt);
	return (hold);
}

char	*next_line(char *txt)
{
	char	*line;
	int		i;

	i = 0;
	if (!(txt[i]))
		return (NULL);
	while (txt[i] && txt[i] != '\n')
		i++;
	line = malloc(sizeof(char) * i + 2);
	if (!(line))
		return (NULL);
	line[i + 1] = '\0';
	while (i >= 0)
	{
		line[i] = txt[i];
		i--;
	}
	return (line);
}

char	*read_file(int fd, char *txt)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes;

	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		buffer[bytes] = 0;
		txt = ft_strjoin(txt, buffer);
		if (check_n(buffer) == 1)
			break ;
	}
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
	if (!nxtline)
	{
		free(nxtline);
		free(txt[fd]);
		txt[fd] = NULL;
		return(NULL);
	}
	txt[fd] = free_used(txt[fd]);
	return (nxtline);
}

// #include <fcntl.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int		fd;
// 	int		fd2;
// 	char	*nextline;

// 	fd = open("lyrics.txt", O_RDONLY);
// 	fd2 = open("abc.txt", O_RDONLY);
// 	nextline = get_next_line(fd);
// 	printf("%s", nextline);
// 	free(nextline);
// 	nextline = get_next_line(fd2);
// 	printf("%s", nextline);
// 	free(nextline);
// 	nextline = get_next_line(fd);
// 	printf("%s", nextline);
// 	free(nextline);
// 	nextline = get_next_line(fd2);
// 	printf("%s", nextline);
// 	free(nextline);
// 	nextline = get_next_line(fd);
// 	printf("%s", nextline);
// 	free(nextline);
// 	nextline = get_next_line(fd2);
// 	printf("%s", nextline);
// 	free(nextline);
// 	nextline = get_next_line(fd);
// 	printf("%s", nextline);
// 	free(nextline);
// 	nextline = get_next_line(fd2);
// 	printf("%s", nextline);
// 	free(nextline);
// 	nextline = get_next_line(fd);
// 	printf("%s", nextline);
// 	free(nextline);
// 	nextline = get_next_line(fd2);
// 	printf("%s", nextline);
// 	free(nextline);
// 	nextline = get_next_line(fd);
// 	printf("%s", nextline);
// 	free(nextline);
// 	nextline = get_next_line(fd2);
// 	printf("%s", nextline);
// 	free(nextline);
// 	nextline = get_next_line(fd);
// 	printf("%s", nextline);
// 	free(nextline);
// 	nextline = get_next_line(fd2);
// 	printf("%s", nextline);
// 	free(nextline);
// 	nextline = get_next_line(fd);
// 	printf("%s", nextline);
// 	free(nextline);
// 	nextline = get_next_line(fd2);
// 	printf("%s", nextline);
// 	free(nextline);
// 	nextline = get_next_line(fd);
// 	printf("%s", nextline);
// 	free(nextline);
// 	nextline = get_next_line(fd2);
// 	printf("%s", nextline);
// 	free(nextline);
// 	nextline = get_next_line(fd);
// 	printf("%s", nextline);
// 	free(nextline);
// 	nextline = get_next_line(fd2);
// 	printf("%s", nextline);
// 	free(nextline);
// 	nextline = get_next_line(fd);
// 	printf("%s", nextline);
// 	free(nextline);
// 	nextline = get_next_line(fd2);
// 	printf("%s", nextline);
// 	free(nextline);
// 	nextline = get_next_line(fd);
// 	printf("%s", nextline);
// 	free(nextline);
	
// 	system ("leaks a.out");
	
// 	close(fd);
// }