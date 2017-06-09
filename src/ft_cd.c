/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 17:04:31 by mallard           #+#    #+#             */
/*   Updated: 2017/06/09 17:53:22 by mallard          ###   ########.fr       */
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

// void        ft_pwd(void)
// {
//     extern char		**environ;
//     int             i;
//     char            *tmp;
//     int             j;
//
//     tmp = NULL;
//     if ((i = env_chr("PWD", 3)) >= 0 && (j = env_chr("OLDPWD", 6)) >= 0)
//     {
//         // tmp = environ[j];
//         // ft_strdel(&tmp);
//         // environ[i] = ft_strsub(environ[j], 3, ft_strlen(environ[j]) - 3);
//         tmp = getcwd(tmp, 1024);
//         ft_putendl(tmp);
//         // tmp = ft_strjoin("PWD=", tmp);
//         // environ[i] = tmp;
//     }
// }

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
    tabdel(tmp);
    return (tmp);
}

char        *path_sup(char *str)
{
	int     i;
	char    *tmp;

	if (str == NULL)
		return (NULL);
	i = ft_strlen(str) - 1;
	if (i == 0)
		return (str);
	while (str[i] && str[i] != '/')
		i--;
	if (!ft_strrchr(str, '/'))
		return (str);
	tmp = ft_strsub(str, 0, i);
	return (tmp);
}

void		ft_cd(char *line)
{
	extern char     **environ;
	char			*tmp;
	char            **tab;

	if (!(tab = ft_split(line)))
		return ;
	if (tablen(tab) >= 1)
	{
		if (tablen(tab) == 1)
			chdir(ft_home());
		else
		{
			if (check_mode(tab[0]) == 1)
				chdir(tab[1]);
			else
			{
				if (tab[1])
				{
					ft_putstr("cd: permission denied:");
					ft_putendl(tab[1]);
				}
			}
		}
	}
	else
		ft_putendl("usage");
}
