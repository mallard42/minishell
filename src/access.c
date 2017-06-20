/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 16:32:14 by mallard           #+#    #+#             */
/*   Updated: 2017/06/18 17:54:59 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	check_a(char **str, char *test)
{
	extern char		**environ;

	if (access(test, F_OK) == 0)
		*str = ft_strdup(test);
	else if (*environ)
		check_access(str, test);
	else
		ft_putendl("env is not enable");
}

void	check_access(char **str, char *test)
{
	extern char		**environ;
	int				i;
	char			*tmp;
	char			**tab;

	i = env_chr("PATH", 4);
	tmp = ft_strchr(environ[i], '=') + 1;
	tab = ft_strsplit(tmp, ':');
	i = 0;
	while (tab[i])
	{
		tmp = double_path(tab[i], test);
		if (access(tmp, F_OK) == 0)
		{
			*str = tmp;
			tabdel(tab);
			return ;
		}
		else
			ft_strdel(&tmp);
		i++;
	}
	tabdel(tab);
	error_command(test);
}

int		env_chr(char *test, int size)
{
	extern char		**environ;
	int				i;

	i = -1;
	while (environ[++i])
	{
		if (!ft_strncmp(environ[i], test, size))
			return (i);
	}
	return (-1);
}

char	*double_path(char *s1, char *s2)
{
	char			*str;

	if (!s1 || !s2)
		return (NULL);
	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	else
	{
		str = ft_strjoin(s1, "/");
		str = ft_strjoin_f(str, s2, 0);
	}
	return (str);
}
