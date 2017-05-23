/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 17:48:52 by mallard           #+#    #+#             */
/*   Updated: 2017/05/22 17:38:46 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include "../libft/include/libft.h"
# include <unistd.h>
# include <stdlib.h>

void		command(char *str, char **env);

void		ft_ls(char *line);
void        ft_pwd(char *line);

void		print_tab(char **tab);

#endif
