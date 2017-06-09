/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 17:48:12 by mallard           #+#    #+#             */
/*   Updated: 2017/06/08 15:35:47 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void		my_prompt(void)
{
	char			*tmp;

	tmp = NULL;
	ft_putstr("\e[38;5;105mMinishell \e[38;5;246m");
	tmp = getcwd(tmp, 512);
	ft_putstr(tmp);
	ft_putstr(" \e[38;5;11m✗ \e[0m");
	free(tmp);
}

int			main(void)
{
	char			*line;

	while (42)
	{
		my_prompt();
		get_next_line(0, &line);
		if (*line)
			check(line);
		ft_strdel(&line);
	}
	return (0);
}

void		check(char *line)
{
	if (!ft_strcmp(line, "exit"))
		exit(EXIT_SUCCESS);
	is_built(line);
}

void		is_built(char *line)
{
	extern char		**environ;

	if (!ft_strncmp(line, "cd", 2) && *environ)
		ft_cd(line);
	else if (!ft_strncmp(line, "echo", 4))
		ft_echo(line);
	else if (!ft_strncmp(line, "setenv", 6) && *environ)
		ft_setenv(line);
	else if (!ft_strncmp(line, "unsetenv", 8) && *environ)
		ft_unsetenv(line);
	else if (!ft_strcmp(line, "env") && *environ)
		print_tab(environ);
	else
		is_command(line);
}
