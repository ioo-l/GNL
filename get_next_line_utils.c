/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leheng <leheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:24:47 by leheng            #+#    #+#             */
/*   Updated: 2022/11/10 16:21:41 by leheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *buff, char *txt)
{
	char	*new;
	int		cbuff;
	int		ctxt;

	cbuff = 0;
	while (buff[cbuff])
		cbuff++;
	ctxt = 0;
	while (txt[ctxt])
		ctxt++;
	new = malloc(sizeof(char) * (cbuff + ctxt + 1));
	if (!(new))
		return (NULL);
	
}