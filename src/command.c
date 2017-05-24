/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 18:10:32 by mallard           #+#    #+#             */
/*   Updated: 2017/05/24 17:59:23 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void		ft_ls(char *line)
{
	ft_putendl(line);
	ft_putendl("execution ls");
}

void		ft_env(t_env *lst)
{
	t_env	*tmp;

	tmp = lst;
	while (tmp)
	{
		ft_putstr(tmp->cat);
		ft_putchar('=');
		ft_putendl(tmp->value);
		tmp = tmp->next;
	}
}

void		ft_pwd(t_env *lst)
{
	t_env	*tmp;

	tmp = lst;
	while (tmp && ft_strcmp(tmp->cat, "PWD"))
		tmp = tmp->next;
	ft_putendl(tmp->value);
}
