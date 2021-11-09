/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 15:43:28 by fbarros           #+#    #+#             */
/*   Updated: 2021/04/21 19:13:07 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_tmp_update(char **tmp, char **buf, ssize_t r, char **line)
{
	char	*tmp2;

	if (0 > r || !*tmp)
		return (-1);
	tmp2 = ft_strjoin(*tmp, *buf);
	free(*tmp);
	if (!tmp2)
		return (-1);
	*tmp = tmp2;
	if (BUFFER_SIZE > r)
		return (ft_final(line, tmp));
	if (!ft_strchr(*tmp, '\n'))
		return (0);
	return (ft_line_ret(tmp, line));
}

int	ft_line_ret(char **tmp, char **line)
{
	int		i;
	char	*tmp2;
	char	*tmp3;

	if (!*tmp)
		return (0);
	i = 0;
	tmp2 = ft_strchr(*tmp, '\n');
	if (tmp2)
	{
		while ('\n' != tmp[0][i])
			i++;
		*line = ft_substr(*tmp, 0, i);
		if (!*line)
			return (-1);
		tmp2++;
		tmp3 = ft_strdup(tmp2);
		free(*tmp);
		if (!tmp3)
			return (-1);
		*tmp = tmp3;
		return (1);
	}
	return (0);
}

int	ft_final(char **line, char **tmp)
{
	int	len;

	len = ft_strlen(*tmp);
	if (NULL == *tmp)
		*line = ft_strdup("");
	if (!ft_strchr(*tmp, '\n'))
	{
		*line = ft_strdup(*tmp);
		free(*tmp);
		*tmp = NULL;
	}
	else
		return (ft_line_ret(tmp, line));
	return (0);
}

int	ft_err(char **buf, char **tmp, char **line, int i)
{
	free(*buf);
	if (-1 == i)
	{
		if (*tmp != NULL)
		{
			free(*tmp);
			*tmp = NULL;
		}
		if (!line)
			*line = ft_strdup("");
	}
	return (i);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*tmp[1024];
	ssize_t		r;
	int			i;

	if (!line || -1 == read(fd, 0, 0) || 0 >= BUFFER_SIZE)
		return (-1);
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	i = 0;
	r = BUFFER_SIZE;
	while (0 == i && r == BUFFER_SIZE)
	{
		r = read(fd, buf, BUFFER_SIZE);
		buf[r] = '\0';
		if (!tmp[fd])
		{
			tmp[fd] = ft_strdup(buf);
			*buf = '\0';
		}
		i = ft_tmp_update(&tmp[fd], &buf, r, line);
	}
	return (ft_err(&buf, &tmp[fd], line, i));
}
