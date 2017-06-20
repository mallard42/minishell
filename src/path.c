/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 17:40:57 by mallard           #+#    #+#             */
/*   Updated: 2017/06/18 17:51:35 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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

	tmp = NULL;
	tab = ft_strsplit(arg, '/');
	i = 0;
	tmp = getcwd(tmp, 512);
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
