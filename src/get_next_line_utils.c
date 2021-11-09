/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 15:23:52 by fbarros           #+#    #+#             */
/*   Updated: 2021/04/22 15:49:31 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	n;

	if (!s)
		return (0);
	n = 0;
	while (s[n])
		n++;
	return (n);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == (unsigned char)c)
			return (&((char *)s)[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*s3;

	if (!s2 || !s1)
		return (NULL);
	s3 = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!s3)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		s3[i++] = s2[j++];
	s3[i] = '\0';
	return (s3);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*p;

	i = 0;
	if (!s)
		return (NULL);
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	if (start > ft_strlen(s))
		len = 0;
	p = (char *)malloc(len * sizeof(char) + 1);
	if (!p)
		return (NULL);
	while (0 < len-- && s[start])
		p[i++] = s[start++];
	p[i] = '\0';
	return (p);
}

//substr(s, 0, ft_strlen(s)) 
//has been changed, might need recheck
char	*ft_strdup(const char *s)
{
	char	*s2;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	s2 = (char *)malloc(sizeof(char) * len + 1);
	if (!s2)
		return (NULL);
	i = 0;
	if ((len + 1) > 0)
	{
		while (i < len && s[i])
		{
			s2[i] = s[i];
			i++;
		}
		s2[i] = '\0';
	}
	return (s2);
}
