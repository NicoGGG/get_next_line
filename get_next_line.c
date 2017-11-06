/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguelfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 15:25:46 by nguelfi           #+#    #+#             */
/*   Updated: 2017/05/12 15:26:02 by nguelfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_line	*new_file(t_line **buf, int fd)
{
	t_line	*tmp;

	tmp = *buf;
	if ((tmp = (t_line*)malloc(sizeof(t_line))) == NULL)
		return (NULL);
	tmp->fd = fd;
	if ((tmp->content = ft_strnew(BUFF_SIZE + 1)) == NULL)
		return (NULL);
	tmp->next = *buf;
	*buf = tmp;
	return (tmp);
}

static t_line	*load_buf(t_line **buf, int fd)
{
	t_line	*tmp;
	char	*content;
	char	*copy;

	tmp = *buf;
	while (tmp)
	{
		if (tmp->fd == fd)
		{
			content = ft_strchr(tmp->content, 10);
			if (content)
			{
				if ((copy = ft_strdup(content + 1)) == NULL)
					return (NULL);
				ft_strclr(tmp->content);
				tmp->content = ft_strcpy(tmp->content, copy);
				ft_strdel(&copy);
			}
			else
				ft_strclr(tmp->content);
			return (tmp);
		}
		tmp = tmp->next;
	}
	return (new_file(buf, fd));
}

static char		*resize_line(char *tmp, char *buf)
{
	int		i;
	int		j;
	char	*copy;

	i = ft_strlench(buf, 10);
	j = ft_strlen(tmp);
	if ((copy = ft_strnew(i + j + 1)) == NULL)
		return (NULL);
	copy = ft_strncat(copy, tmp, j);
	copy = ft_strncat(copy, buf, i);
	copy[i + j] = 0;
	ft_strdel(&tmp);
	return (copy);
}

int				get_next_line(int fd, char **line)
{
	static t_line	*buf = NULL;
	t_line			*tmp;
	int				i;

	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	if ((tmp = load_buf(&buf, fd)) == NULL)
		return (-1);
	*line = ft_strdupch(tmp->content, 10);
	while (*line && !(ft_strchr(tmp->content, 10)) &&
		(i = read(fd, tmp->content, BUFF_SIZE)))
	{
		(tmp->content)[i] = 0;
		if ((*line = resize_line(*line, tmp->content)) == NULL)
			return (-1);
	}
	if (ft_strlen(tmp->content) == 0 && ft_strlen(*line) == 0 && i == 0)
		return (0);
	return (1);
}
