/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: looi <looi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:24:47 by leheng            #+#    #+#             */
/*   Updated: 2022/11/14 18:16:15 by looi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	check_n(char *buff)
{
	while (*buff)
	{
		if (*buff == '\n')
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
	new = malloc(sizeof(char) * (cbuff + ctxt + 1));
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
