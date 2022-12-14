/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: looi <looi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:43:11 by leheng            #+#    #+#             */
/*   Updated: 2022/11/14 18:14:48 by looi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 24
# endif

char	*get_next_line(int fd);
int		check_n(char *buff);
int		ft_strlen(char *string);
char	*ft_strjoin(char *txt, char *buff);

#endif