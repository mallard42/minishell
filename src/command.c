/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 18:10:32 by mallard           #+#    #+#             */
/*   Updated: 2017/06/07 11:28:17 by mallard          ###   ########.fr       */
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
	str = ft_strsplit(line, ' ');
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
		tabdel(str);
		ft_strdel(&path);
	}
}

void		ft_cd(char *line)
{
	char			*tmp;

	if (line[2] != ' ')
		error_command(line);
	else
	{
		tmp = ft_strsub(line, 3, ft_strlen(line));
	}
}

void		ft_unsetenv(char *line)
{
	char			**tab;
	char			*str;
	extern char		**environ;
	int				i;

	tab = ft_strsplit(line, ' ');
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

void		rm_quote(char **str)
{
	char			*tmp;
	int				i;

	if ((*str)[0] == '"')
	{
		i = ft_strlen(*str);
		i = ((*str)[0] == '"') ? i - 1 : i;
		tmp = ft_strsub(*str, 1, i - 1);
		ft_strdel(str);
		*str = tmp;
	}
}

void		ft_echo(char *line)
{
	char			**tab;
	int				i;
	int				n;

	tab = ft_strsplit(line, ' ');
	if (tablen(tab) > 1)
	{
		n = (!ft_strcmp(tab[1], "-n")) ? 1 : 0;
		i = (n == 1) ? 2 : 1;
		while (tab[i])
		{
			rm_quote(&(tab[i]));
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

void		ft_setenv(char *line)
{
	char			**tab;
	char			*str;
	extern char		**environ;
	int				i;

	tab = ft_strsplit(line, ' ');
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
