/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 18:17:08 by mallard           #+#    #+#             */
/*   Updated: 2017/07/03 23:29:34 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../libft/include/libft.h"
#include <stdlib.h>

void	print_tab(char **tab)
{
	int		i;

	if (*tab)
	{
		i = 0;
		while (tab[i] != NULL)
		{
			ft_putstr(tab[i]);
			ft_putstr("\n");
			i++;
		}
	}
	else
		ft_putendl("NULL");
}

char	**newtab(int size)
{
	char	**tab;

	if (!(tab = (char **)malloc(sizeof(char *) * (size + 1))))
		return (0);
	tab[size] = NULL;
	return (tab);
}

void	tabdel(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
	{
		ft_strdel(&(tab[i]));
		i++;
	}
	free(tab);
	tab = NULL;
}

int		tablen(char **tab)
{
	int		i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i] != NULL)
		i++;
	return (i);
}

char	**add_str_to_tab(char **tab, char *str, int free)
{
	char	**tmp;
	int		i;

	i = 0;
	if (!(tmp = newtab(tablen(tab) + 1)))
		return (NULL);
	while (tab[i] != NULL)
	{
		tmp[i] = ft_strdup(tab[i]);
		i++;
	}
	if (free == 1)
		tabdel(tab);
	tmp[i] = ft_strdup(str);
	return (tmp);
}
