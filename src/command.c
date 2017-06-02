/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 18:10:32 by mallard           #+#    #+#             */
/*   Updated: 2017/06/02 18:09:42 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void		ft_ls(char *line)
{
	char	**str;
	char	*path;
	pid_t	f;

	str = ft_strsplit(line, ' ');
	check_access(&path, str[0]);
	f = fork();
	if (f > 0)
		wait(0);
	if (f == 0)
		execve(path, str, NULL);
	if (f < 0)
		exit(EXIT_FAILURE);
	tabdel(str);
	ft_strdel(&path);
}

void		ft_pwd(char *line)
{
	char    *path;
	char	**tab;
	pid_t   f;

	tab = ft_strsplit(line, ' ');
	check_access(&path, tab[0]);
	if (!tab[1])
		tab = add_str_to_tab(tab, "-P", 1);
	f = fork();
	if (f > 0)
		wait(0);
	if (f == 0)
		execve(path, tab, NULL);
	if (f < 0)
		exit(EXIT_FAILURE);
	ft_strdel(&path);
	tabdel(tab);
}

void		ft_cd(char *line)
{
	char	*tmp;

	if (line[2] != ' ')
		error_command(line);
	else
	{
		tmp = ft_strsub(line, 3, ft_strlen(line));
	}
}

void		ft_setenv()
{
	
}
