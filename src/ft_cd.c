/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 17:04:31 by mallard           #+#    #+#             */
/*   Updated: 2017/09/04 14:07:01 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../libft/include/libft.h"
#include <sys/stat.h>
#include <unistd.h>

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
	char		*tmp;
	char		*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	if (check_mode(str) == 1)
	{
		tmp = getcwd(tmp, 512);
		if (chdir(str) == -1)
		{
			ft_putstr_fd("cd: no such file or directory:", 2);
			ft_putendl(str);
		}
		else
		{
			tmp2 = getcwd(tmp2, 512);
			ft_set_pwd(tmp2, tmp);
		}
	}
	else
	{
		ft_putstr_fd("cd: permission denied:", 2);
		ft_putendl(str);
	}
}

void		ft_set_pwd(char *str, char *old)
{
	extern char		**environ;
	int				i;
	int				j;

	i = env_chr("PWD", 3);
	j = env_chr("OLDPWD", 6);
	if (j >= 0)
	{
		ft_strdel(&(environ[j]));
		environ[j] = ft_strjoin("OLDPWD=", old);
	}
	else
		environ = add_str_to_tab(environ, ft_strjoin("OLDPWD=", old), 1);
	if (i >= 0)
	{
		ft_strdel(&(environ[i]));
		environ[i] = ft_strjoin("PWD=", str);
	}
	else
		environ = add_str_to_tab(environ, ft_strjoin("PWD=", str), 1);
}

void		ft_cd(char *line, char *home)
{
	extern char		**environ;
	char			*tmp;
	char			**tab;
	int				i;

	if (!(tab = ft_split(line)))
		return ;
	tab_chr(tab, home);
	if (tablen(tab) == 1 || (tab[1] && !ft_strcmp(tab[1], "~")))
		move(home, 1);
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
		ft_putendl_fd("usage: cd [dir]", 2);
	tabdel(tab);
}
