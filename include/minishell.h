/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 17:48:52 by mallard           #+#    #+#             */
/*   Updated: 2017/05/24 18:01:50 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include "../libft/include/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_env
{
	char			*cat;
	char			*value;
	struct s_env	*next;
}				t_env;

void		command(char *str, t_env *env);

void		ft_ls(char *line);
void        ft_pwd(t_env *env);
void        ft_env(t_env *lst);

t_env		*newenv(char *cat, char *value);
void		addenv(t_env **lst, t_env *new);
t_env		*env_to_lst(char **env);

#endif
