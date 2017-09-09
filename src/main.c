/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 17:48:12 by mallard           #+#    #+#             */
/*   Updated: 2017/09/09 17:53:45 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../libft/include/libft.h"
#include <unistd.h>
#include <stdlib.h>

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

void		check(char *line, char *home)
{
	char			*tmp;
	extern char		**environ;

	tmp = ft_strtrim(line);
	if (!ft_strcmp(tmp, "exit")){
		exit(EXIT_SUCCESS);}
	else if (!ft_strncmp(tmp, "env", 3)){
		ft_env(line);}
	else{
		is_built(tmp, home, environ);}
	ft_strdel(&tmp);
}

void		is_built(char *line, char *home, char **env)
{
	if (!ft_strncmp(line, "cd", 2))
		ft_cd(line, home, env);
	else if (!ft_strncmp(line, "echo", 4))
		ft_echo(line);
	else if (!ft_strncmp(line, "setenv", 6))
		ft_setenv(line, env);
	else if (!ft_strncmp(line, "unsetenv", 8))
		ft_unsetenv(line, env);
	else
		is_command(line, home, env);
}

int			main(void)
{
	char			*line;
	int				i;
	char			**tab;
	char			*home;
	extern char		**environ;

	home = ft_home();
	env_cpy();
	while (42)
	{
		my_prompt();
		get_next_line(0, &line);
		i = -1;
		/*if (!*line)
			return (1);*/
		if (*line)
		{
			tab = ft_strsplit(line, ';');
			if (*tab)
			{
				while (tab[++i])
					check(tab[i], home);
			}
			tabdel(tab);
		}
		ft_strdel(&line);
	}
	//tabdel(environ);
	return (0);
}
