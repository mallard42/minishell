/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 17:48:52 by mallard           #+#    #+#             */
/*   Updated: 2017/05/31 17:24:26 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include "../libft/include/libft.h"
# include <unistd.h>
# include <stdlib.h>

void		command(char *str);

void		print_tab(char **tab);
char		**newtab(int size);
int			tablen(char **tab);
char		**add_str_to_tab(char **tab, char *str, int free);
void		tabdel(char **tab);

void		ft_ls(char *line);
void        ft_pwd(char *line);

void		error_command(char *str);

#endif
