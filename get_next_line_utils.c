/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elengarc <elengarc@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:33:44 by elengarc          #+#    #+#             */
/*   Updated: 2025/04/18 18:33:45 by elengarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2, size_t len1, size_t len2)
{
	char	*result;
	size_t	i;

	if (!s2 || !s1)
		return (free(s1), s1 = NULL, NULL);
	result = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!result)
		return (free(s1), s1 = NULL, NULL);
	i = 0;
	while (i < len1)
	{
		result[i] = s1[i];
		i++;
	}
	while (i < len1 + len2)
	{
		result[i] = s2[i - len1];
		i++;
	}
	result[i] = '\0';
	free(s1);
	return (result);
}

char	*ft_strchr_gnl(char *s, int c)
{
	int		i;
	char	*p;

	i = 0;
	p = (char *)s;
	if (!s)
		return (NULL);
	while (p[i])
	{
		if ((char)p[i] == (char)c)
			return (&p[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&p[i]);
	return (NULL);
}

char	*ft_substr_gnl(char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if (len > ft_strlen_gnl(s + start))
		len = ft_strlen_gnl(s + start);
	substr = malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	i = start;
	j = 0;
	while (s[i] && j < len)
	{
		substr[j] = s[i];
		i++;
		j++;
	}
	substr[j] = '\0';
	return (substr);
}
