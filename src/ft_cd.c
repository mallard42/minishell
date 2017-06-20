/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 17:04:31 by mallard           #+#    #+#             */
/*   Updated: 2017/06/20 16:17:46 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int			check_mode(char *path)
{
	struct stat		buf;

	lstat(path, &buf);
	if (buf.st_mode & S_IRUSR)
		return (1);
	return (0);
}

void		move(char *str, int home)
{
	if (check_mode(str) == 1)
	{
		if (chdir(str) == -1)
		{
			ft_putstr("cd: no such file or directory:");
			ft_putendl(str);
		}
		else
			ft_set_pwd(str, home);
	}
	else
	{
		ft_putstr("cd: permission denied:");
		ft_putendl(str);
	}
}

void		ft_set_pwd(char *str, int home)
{
	char			*tmp;
	extern char		**environ;
	int				i;
	int				j;
	char			*t;

	i = env_chr("OLDPWD", 6);
	j = env_chr("PWD", 3);
	if (i >= 0 && j >= 0)
	{
		tmp = environ[i];
		environ[i] = ft_strjoin("OLD", environ[j]);
		ft_strdel(&tmp);
		tmp = NULL;
		tmp = getcwd(tmp, 512);
		t = environ[j];
		environ[j] = ft_strjoin_f("PWD=", tmp, 1);
		ft_strdel(&t);
		return ;
	}
	if (j >= 0)
		environ = add_str_to_tab(environ, ft_strjoin("OLD", environ[j]), 1);
	else
		environ = add_str_to_tab(environ, ft_strjoin("PWD=", ft_path(str)), 1);
}

void		ft_cd(char *line)
{
	extern char		**environ;
	char			*tmp;
	char			**tab;
	int				i;

	if (!(tab = ft_split(line)))
		return ;
	if (tablen(tab) == 1 || (tab[1] && !ft_strcmp(tab[1], "~")))
		move(ft_home(), 1);
	else if (tablen(tab) >= 1)
	{
		if (tab[1] && ft_strcmp(tab[1], "-") == 0)
		{
			if ((i = env_chr("OLDPWD", 6)) >= 0)
				move(ft_strchr(environ[i], '=') + 1, 1);
		}
		else
			move(tab[1], 0);
	}
	else
		ft_putendl("usage: cd [dir]");
	tabdel(tab);
}
