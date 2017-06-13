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

void		env_cpy(void)
{
	extern char		**environ;
	char			**env;
	int				i;

	i = 0;
	if (!(env = newtab(tablen(environ))))
		exit(EXIT_FAILURE);
	while (environ[i])
	{
		env[i] = ft_strdup(environ[i]);
		if (!env[i])
			exit(EXIT_FAILURE);
		i++;
	}
	environ = env;
}

int			main(void)
{
	char			*line;

	env_cpy();
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
