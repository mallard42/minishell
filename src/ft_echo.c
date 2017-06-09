/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 17:15:28 by mallard           #+#    #+#             */
/*   Updated: 2017/06/08 17:15:42 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void		rm_quote(char **str)
{
	char			*tmp;
	int				i;
	int				j;

	i = 1;
	while (str[i])
	{
		if (str[i][0] == '"')
		{
			tmp = str[i];
			str[i] = ft_strsub(str[i], 1, ft_strlen(str[i]));
			ft_strdel(&tmp);
		}
		j = ft_strlen(str[i]) - 1;
		if (str[i][j] == '"')
		{
			tmp = str[i];
			str[i] = ft_strsub(str[i], 0, j);
			ft_strdel(&tmp);
		}
		i++;
	}
}

void		ft_echo(char *line)
{
	char			**tab;
	int				i;
	int				n;

	tab = ft_split(line);
	if (ft_strcmp(tab[0], "echo"))
		error_command(tab[0]);
	else if (tablen(tab) > 1)
	{
		n = (!ft_strcmp(tab[1], "-n")) ? 1 : 0;
		i = (n == 1) ? 2 : 1;
		rm_quote(tab);
		while (tab[i])
		{
			ft_putstr(tab[i]);
			if (tab[i + 1] == NULL && n == 0)
				ft_putchar('\n');
			else if (tab[i + 1] != NULL)
				ft_putchar(' ');
			i++;
		}
	}
	else
		ft_putstr("\n");
	tabdel(tab);
}
