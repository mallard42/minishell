/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:10:34 by mallard           #+#    #+#             */
/*   Updated: 2017/05/24 14:01:47 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

static int			ft_read(int fd, char **line, t_list **lst)
{
	int				ret;
	char			buff[BUFF_SIZE + 1];
	char			*tmp;

	if ((*lst)->content)
	{
		*line = ft_strjoin_f((*lst)->content, *line, 1);
		ft_memdel(&((*lst)->content));
	}
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret < 0)
			return (ret);
		buff[ret] = '\0';
		if ((tmp = ft_strchr(buff, '\n')) != NULL)
		{
			*line = ft_strjoin_f(*line, ft_strsub(buff, 0, ft_strlen(buff) -
						ft_strlen(tmp)), 2);
			(*lst)->content = ft_strdup(tmp + 1);
			return (ret);
		}
		*line = ft_strjoin_f(*line, buff, 0);
	}
	return (ret);
}

int					get_next_line(int fd, char **line)
{
	static t_list	*list;
	int				ret;
	t_list			*tmp;
	char			*lol;

	if (!line || fd < 0)
		return (-1);
	*line = malloc(1);
	**line = '\0';
	if (!list)
		list = ft_lstnew(NULL, 0);
	tmp = list;
	ft_lstresearch(fd, &tmp);
	if (tmp->content && (lol = ft_strchr(tmp->content, '\n')))
	{
		ft_strdel(line);
		*line = ft_strsub(tmp->content, 0, ft_strlen(tmp->content) -
				ft_strlen(lol));
		tmp->content = ft_strdup(lol + 1);
		return (1);
	}
	if ((ret = ft_read(fd, line, &tmp)) == -1)
		return (-1);
	return (ret > 0 || ft_strlen(*line)) ? 1 : 0;
}
