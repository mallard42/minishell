/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 17:48:12 by mallard           #+#    #+#             */
/*   Updated: 2017/05/21 18:35:32 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int		main(int ac, char**av, char **env)
{
	char	*line;

	while (42)
	{
		ft_putstr("$> ");
		get_next_line(0, &line);
		command(line, env);
	}
}

void		command(char *line, char **env)
{
	if (!ft_strcmp(line, "exit"))
		exit(EXIT_SUCCESS);
	else if (ft_strnstr(line, "ls", 2))
		ft_ls(line);
	else if (ft_strnstr(line, "echo", 4))
		ft_putendl("execution echo");
	else if (ft_strnstr(line, "cd", 2))
		ft_putendl("execution cd");
	else if (ft_strnstr(line, "pwd", 3))
		ft_putendl("execution pwd");
	else if (ft_strnstr(line, "setenv", 6))
		ft_putendl("execution setenv");
	else if (ft_strnstr(line, "unsetenv", 8))
		ft_putendl("execution unsetenv");
	else if (ft_strnstr(line, "env", 3))
		print_tab(env);
	else
	{
		ft_putstr(line);
		ft_putendl(": command not found");
	}
}
