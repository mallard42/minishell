/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstresearch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 17:51:41 by mallard           #+#    #+#             */
/*   Updated: 2017/04/20 18:00:46 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int			ft_lstresearch(int fd, t_list **lst)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *lst;
	while (tmp)
	{
		if (tmp->content_size == (size_t)fd)
		{
			while (i > 0)
			{
				*lst = (*lst)->next;
				i--;
			}
			return (1);
		}
		tmp = tmp->next;
		i++;
	}
	tmp = ft_lstnew(NULL, 0);
	tmp->content_size = fd;
	ft_lstaddend(lst, tmp);
	lstresearch(fd, lst);
	return (0);
}
