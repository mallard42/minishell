/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 18:10:32 by mallard           #+#    #+#             */
/*   Updated: 2017/08/26 14:31:20 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../libft/include/libft.h"
#include <stdlib.h>
#include <unistd.h>

int			tab_chr(char **tab, char *home)
{
	int				i;
	char			*tmp;
	char			*t;

	i = -1;
	while (tab[++i])
	{
		if ((tmp = ft_strchr(tab[i], '~')))
		{
			t = tab[i];
			if (!(tab[i] = ft_strdup(home)))
			{
				ft_strdel(&t);
				return (0);
			}
			if (tmp + 1 && tmp + 2)
				tab[i] = ft_strjoin_f(tab[i], tmp + 1, 0);
			ft_strdel(&t);
		}
	}
	return (0);
}

void		ft_fork(char *path, char **str)
{
	extern char		**environ;
	pid_t			f;

	if (path)
	{
		f = fork();
		if (f > 0)
			wait(0);
		if (f == 0)
		{
			if ((execve(path, str, environ)) == -1)
			{
				error_command(path);
				exit(EXIT_SUCCESS);
			}
		}
		if (f < 0)
			exit(EXIT_FAILURE);
		ft_strdel(&path);
	}
}

void		is_command(char *line, char *home)
{
	char			**str;
	char			*path;

	path = NULL;
	str = ft_split(line);
	if (str[0] == NULL)
	{
		tabdel(str);
		return ;
	}
	tab_chr(str, home);
	check_a(&path, str[0]);
	if (!ft_strcmp(str[0], "./minishell"))
		ft_shlvl();
	ft_fork(path, str);
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
		ft_putendl_fd("usage: unsetenv [name]", 2);
	tabdel(tab);
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
			environ = add_str_to_tab(environ, str, 1);
		ft_strdel(&str);
	}
	else
		ft_putendl_fd("usage: setenv [name] [value]", 2);
	tabdel(tab);
}
