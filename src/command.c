/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 18:10:32 by mallard           #+#    #+#             */
/*   Updated: 2017/05/23 17:11:38 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void		ft_ls(char *line)
{
	ft_putendl(line);
	ft_putendl("execution ls");
}

void		ft_pwd(char *line)
{
	char	*path;
	char	*buf;

	path = getcwd(".", 0);
	ft_putendl(buf);
}
