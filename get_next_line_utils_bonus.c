/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcela <amarcela@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 09:23:24 by amarcela          #+#    #+#             */
/*   Updated: 2022/09/30 03:41:15 by amarcela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*ptr;

	if (size > 2147483647)
		return (NULL);
	ptr = malloc(size * nitems);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (size * nitems));
	return (ptr);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *s3;
    int     i;
    int     j;

    s3 = malloc (sizeof (char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (!s3)
        return (NULL);
    i = 0;
    while (s1[i] != '\0')
    {
        s3[i] = (char)s1[i];
        i++;
    }
    j = 0;
    while (s2[j] != '\0')
    {
        s3[i] = (char)s2[j];
        i++;
        j++;
    }
    s3[i] = '\0';
    return (s3);
}

char	*ft_strchr(const char *str, int c)
{
	char	*str1;

	str1 = (char *)str;
	if (c > 255 || str[0] == '\0')
		return (str1);
	while (*str1)
	{
		if (*str1 == c)
			return (str1);
		str1++;
	}
	if (*str1 == c)
		return (str1);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}
