/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 17:48:52 by mallard           #+#    #+#             */
/*   Updated: 2017/09/03 14:59:19 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>

void		check_a(char **str, char *test);
void		check_access(char **str, char *test, int i);
int			env_chr(char *test, int size);
void		ft_shlvl(void);
char		*double_path(char *s1, char *s2);
int			tab_chr(char **tab, char *home);
void		ft_fork(char *path, char **str);
void		is_command(char *line, char *home);
void		ft_unsetenv(char *line);
void		ft_setenv(char *line);
void		error_command(char *str);
int			check_mode(char *path);
void		move(char *str, int home);
void		ft_set_pwd(char *str, char *old);
void		ft_cd(char *line, char *home);
void		rm_quote(char **str);
void		ft_echo(char *line);
char		**ft_split(char const *s);
void		my_prompt(void);
void		env_cpy(void);
void		check(char *line, char *home);
void		is_built(char *line, char *home);
void		char_del(char **tab, int i);
char		*path_sup(char *str);
char		*ft_path(char *arg);
char		*ft_home(void);
void		print_tab(char **tab);
char		**newtab(int size);
void		tabdel(char **tab);
int			tablen(char **tab);
char		**add_str_to_tab(char **tab, char *str, int free);

#endif
