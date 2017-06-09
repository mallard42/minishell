/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 18:10:32 by mallard           #+#    #+#             */
/*   Updated: 2017/06/08 17:43:26 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void		is_command(char *line)
{
	extern char		**environ;
	char			**str;
	char			*path;
	pid_t			f;

	path = NULL;
	str = ft_split(line);
	if (str[0] == NULL)
		return ;
	check_access(&path, str[0]);
	if (path)
	{
		f = fork();
		if (f > 0)
			wait(0);
		if (f == 0)
			execve(path, str, environ);
		if (f < 0)
			exit(EXIT_FAILURE);
		ft_strdel(&path);
	}
	tabdel(str);
}

void		ft_unsetenv(char *line)
{
	char			**tab;
	char			*str;
	extern char		**environ;
	int				i;

	if (!(tab = ft_split(line)))
		return ;
	if (tablen(tab) == 2)
	{
		if ((i = env_chr(tab[1], ft_strlen(tab[1]))) >= 0)
		{
			char_del(environ, i);
		}
	}
	else
		ft_putendl("usage");
	tabdel(tab);
}

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

void		ft_setenv(char *line)
{
	char			**tab;
	char			*str;
	extern char		**environ;
	int				i;

	if (!(tab = ft_split(line)))
		return ;
	if (tablen(tab) == 3)
	{
		str = ft_strjoin(tab[1], "=");
		str = ft_strjoin_f(str, tab[2], 0);
		if ((i = env_chr(tab[1], ft_strlen(tab[1]))) >= 0)
		{
			ft_strdel(&(environ[i]));
			environ[i] = ft_strdup(str);
		}
		else
			environ = add_str_to_tab(environ, str, 0);
		ft_strdel(&str);
	}
	else
		ft_putendl("usage");
	tabdel(tab);
}
