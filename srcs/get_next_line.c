/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:38:11 by jmetelin          #+#    #+#             */
/*   Updated: 2019/11/20 14:30:33 by jmetelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	cpy_leftovers(char *buff, int start)
{
	int	i;

	i = 0;
	while (buff[start])
		buff[i++] = buff[start++];
	while (buff[i])
		buff[i++] = '\0';
}

static int	del_line(char **line, int ret)
{
	if (*line)
		ft_strdel(line);
	return (ret);
}

static int	cpy_line(char **line, char *buff)
{
	int		ret;
	char	*s1;
	char	*s2;
	int		i;

	ret = 0;
	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		ret = 1;
	if (!(s2 = ft_strsub(buff, 0, i)))
		return (del_line(line, -1));
	if (!*line)
		*line = s2;
	else
	{
		s1 = *line;
		if (!(*line = ft_strjoin(s1, s2)))
			return (del_line(line, -1));
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	cpy_leftovers(buff, ret ? i + 1 : i);
	return (ret);
}

int			get_next_line(const int fd, char **line)
{
	static char	buff[MAX_FD][BUFF_SIZE + 1];
	int			ret;

	if (!line || fd < 0 || fd > MAX_FD || BUFF_SIZE < 1)
		return (-1);
	ret = -1;
	*line = NULL;
	if (*buff[fd] != '\0' && (ret = cpy_line(line, buff[fd])))
		return (ret);
	while ((ret = read(fd, buff[fd], BUFF_SIZE)) > 0)
	{
		buff[fd][ret] = '\0';
		if ((ret = cpy_line(line, buff[fd])))
			return (ret);
	}
	if (*line)
		return (1);
	return (del_line(line, ret));
}
