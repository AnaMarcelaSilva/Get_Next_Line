/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcela <amarcela@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 09:15:22 by amarcela          #+#    #+#             */
/*   Updated: 2022/09/30 10:07:31 by amarcela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#	define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int	fd);
void	*ft_calloc(size_t nitems, size_t size);
char    *ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);

#endif