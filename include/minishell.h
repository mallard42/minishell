/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 17:48:52 by mallard           #+#    #+#             */
/*   Updated: 2017/06/08 11:03:40 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
# include <stdio.h>
# include "../libft/include/libft.h"
# include <unistd.h>
# include <stdlib.h>

void		error_command(char *str);

void		check(char *line);
void		is_command(char *line);
void		is_built(char *line);

void		print_tab(char **tab);
char		**newtab(int size);
int			tablen(char **tab);
char		**add_str_to_tab(char **tab, char *str, int free);
void		tabdel(char **tab);

void		ft_setenv(char *line);
void		ft_unsetenv(char *line);
void		char_del(char **tab, int i);
void		ft_echo(char *line);
void		rm_quote(char **str);
void		ft_cd(char *line);
int         check_mode(char *path);

void		check_access(char **str, char *test);
char		*double_path(char *s1, char *s2);
int			env_chr(char *test, int size);

char        **ft_split(char const *s);

#endif
