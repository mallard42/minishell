/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 17:40:57 by mallard           #+#    #+#             */
/*   Updated: 2017/09/02 17:33:55 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../include/minishell.h"
#include "../libft/include/libft.h"

void		char_del(char **tab, int i)
{
	int				size;
	char			*tmp;

	size = tablen(tab);
	tmp = tab[i];
	ft_strdel(&tmp);
	while (i < size)
	{
		tab[i] = tab[i + 1];
		i++;
	}
}

char		*path_sup(char *str)
{
	int				i;
	char			*tmp;

	if (str == NULL)
		return (NULL);
	i = ft_strlen(str) - 1;
	if (i == 0)
		return (str);
	while (str[i] && str[i] != '/')
		i--;
	tmp = ft_strsub(str, 0, i);
	return (tmp);
}

char		*ft_path(char *arg)
{
	int				i;
	char			**tab;
	char			*tmp;
	extern char		**environ;

	tmp = NULL;
	tab = ft_strsplit(arg, '/');
	i = 0;
	tmp = getcwd(tmp, 512);
	if (env_chr("PWD", 3) == -1)
	{
		printf("0\n");
		return (tmp);
	}
	while (tab[i])
	{
		if (ft_strcmp(tab[i], "..") == 0)
			tmp = path_sup(tmp);
		else if (ft_strcmp(tab[i], "."))
			tmp = double_path(tmp, tab[i]);
		i++;
	}
	return (tmp);
}

char		*ft_home(void)
{
	char			*tmp;
	extern char		**environ;
	int				i;

	if ((i = env_chr("HOME", 4)) == -1)
		return (NULL);
	tmp = ft_strchr(environ[i], '=');
	return (tmp + 1);
}
