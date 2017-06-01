/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 17:48:12 by mallard           #+#    #+#             */
/*   Updated: 2017/06/01 11:50:57 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	my_prompt(void)
{
	char			*tmp;

	tmp = NULL;
	ft_putstr("\e[38;5;105mMinishell \e[38;5;246m");
	tmp = getcwd(tmp, 512);
	ft_putstr(tmp);
	ft_putstr(" \e[38;5;11m✗ \e[0m"); 
	free(tmp);
}

int		main(void)
{
	char			*line;
	//char			**env;

	//env = env_cpy();
	while (42)
	{
		my_prompt();
		get_next_line(0, &line);
		if (*line)
		{
			command(line);
			ft_strdel(&line);
		}
	}
	return (0);
}

void		command(char *line)
{
	extern char		**environ;

	if (!ft_strcmp(line, "exit"))
		exit(EXIT_SUCCESS);
	else if (!ft_strncmp(line, "ls", 2))
		ft_ls(line);
	else if (!ft_strncmp(line, "pwd", 3))
		ft_pwd(line);
	else if (!ft_strncmp(line, "cd", 2))
		ft_putendl("execution cd");
	else if (!ft_strncmp(line, "echo", 4))
		ft_putendl("execution echo");
	else if (!ft_strncmp(line, "setenv", 6))
		ft_putendl("execution setenv");
	else if (!ft_strncmp(line, "unsetenv", 8))
		ft_putendl("execution unsetenv");
	else if (!ft_strncmp(line, "env", 3))
		print_tab(environ);
	else
		error_command(line);
}
