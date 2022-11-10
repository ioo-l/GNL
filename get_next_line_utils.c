/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: looi <looi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:24:47 by leheng            #+#    #+#             */
/*   Updated: 2022/11/10 21:09:20 by looi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_null(char *buff)
{
	while (*buff)
	{
		if (*buff == '\0')
			return (1);
		*buff++;
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
	ctxt = ft_strlen(txt);
	new = malloc(sizeof(char) * (cbuff + ctxt + 1));
	if (!(new))
		return (NULL);
	i = 0;
	while (i < ctxt)
		;
	*new ++ = txt[i++];
	i = 0;
	while (i < cbuff)
		*new ++ = buff[i++];
	*new = '\0';
	if (txt)
		free(txt);
	return (new - ctxt - cbuff);
}
