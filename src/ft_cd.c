/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 17:04:31 by mallard           #+#    #+#             */
/*   Updated: 2017/06/13 17:43:14 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int         check_mode(char *path)
{
	struct stat     buf;

	lstat(path, &buf);
	if (buf.st_mode & S_IRUSR)
		return (1);
	return (0);
}

char        *ft_home(void)
{
	char        *tmp;
	char        **tab;

	tmp = NULL;
	tmp = getcwd(tmp, 512);
	tab = ft_strsplit(tmp, '/');
	tmp = NULL;
	if (tab[0] && tab[1])
	{
		tmp = ft_strdup("/");
		tmp = ft_strjoin_f(tmp, tab[0], 0);
		tmp = ft_strjoin_f(tmp, "/", 0);
		tmp = ft_strjoin_f(tmp, tab[1], 0);
	}
	tabdel(tab);
	return (tmp);
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

char		*path_sup(char *str)
{
	int		i;
	char	*tmp;

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

void		ft_set_pwd(char *str, int home)
{
	char			*tmp;
	extern char     **environ;
	int				i;
	int				j;
	char			*t;

	i = env_chr("OLDPWD", 6);
	j = env_chr("PWD", 3);
	tmp = environ[j];
	if (ft_strcmp(str, "-") == 0)
	{
		tmp = environ[i];
		environ[i] = ft_strsub(environ[i], 3, ft_strlen(environ[i]) - 3);
		ft_strdel(&tmp);
		environ[j] = ft_strjoin_f("OLD", environ[j], 1);
	}
	else
	{
		if (ft_strcmp(str, "..") == 0)
			environ[j] = path_sup(environ[j]);
		else
			if (home == 0)
				environ[j] = double_path(environ[j], str);
			else
				environ[j] = ft_strjoin("PWD=", str);
		t = environ[i];
		environ[i] = ft_strjoin("OLD", tmp);
		ft_strdel(&tmp);
		ft_strdel(&t);
	}
}

void		ft_cd(char *line)
{
	extern char     **environ;
	char			*tmp;
	char            **tab;
	int				i;

	if (!(tab = ft_split(line)))
		return ;
	if (tablen(tab) == 1)
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
		ft_putendl("usage");
	tabdel(tab);
}
