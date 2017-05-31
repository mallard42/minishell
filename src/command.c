/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 18:10:32 by mallard           #+#    #+#             */
/*   Updated: 2017/05/31 17:55:05 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void		ft_ls(char *line)
{
	char	**str;
	char	*path;
	pid_t	f;

	str = ft_strsplit(line, ' ');
	f = fork();
	if (f > 0)
		wait(0);
	if (f == 0)
		execve("/bin/ls", str, NULL);
	if (f < 0)
		exit(EXIT_FAILURE);
}

void		ft_pwd(char *line)
{
	char    *path;
	char	**tab;
	pid_t   f;


	f = fork();
	if (f > 0)
		wait(0);
	if (f == 0)
		execve("/bin/pwd", tab, NULL);
	if (f < 0)
		exit(EXIT_FAILURE);
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
