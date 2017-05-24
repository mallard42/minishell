/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 17:48:12 by mallard           #+#    #+#             */
/*   Updated: 2017/05/24 18:02:07 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int		main(int ac, char**av, char **env)
{
	char	*line;
	t_env	*lst;

	lst = env_to_lst(env);
	while (42)
	{
		ft_putstr("$> ");
		get_next_line(0, &line);
		command(line, lst);
	}
}

void		command(char *line, t_env *env)
{
	if (!ft_strcmp(line, "exit"))
		exit(EXIT_SUCCESS);
	else if (ft_strnstr(line, "ls", 2))
		ft_ls(line);
	else if (ft_strnstr(line, "echo", 4))
		ft_putendl("execution echo");
	else if (ft_strnstr(line, "cd", 2))
		ft_putendl("execution cd");
	else if (ft_strstr(line, "pwd"))
		ft_pwd(env);
	else if (ft_strnstr(line, "setenv", 6))
		ft_putendl("execution setenv");
	else if (ft_strnstr(line, "unsetenv", 8))
		ft_putendl("execution unsetenv");
	else if (ft_strnstr(line, "env", 3))
		ft_env(env);
	else
	{
		ft_putstr(line);
		ft_putendl(": command not found");
	}
}
