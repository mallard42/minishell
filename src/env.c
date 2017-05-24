/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 14:23:39 by mallard           #+#    #+#             */
/*   Updated: 2017/05/24 18:05:09 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_env	*newenv(char *cat, char *value)
{
	t_env	*lst;

	if (!(lst = malloc(sizeof(t_env))))
		return (0);
	lst->cat = cat;
	lst->value = value;
	return (lst);
}

t_env	*env_to_lst(char **env)
{
	t_env	*lst;
	t_env	*new;
	int		i;
	int		j;

	lst = NULL;
	i = -1;
	while (env[++i])
	{
		printf("1\n");
		while (env[i][j] != '=')
			j++;
		printf("2\n");
		if (lst == NULL)
			lst = newenv(ft_strsub(env[i], 0, j - 1), ft_strsub(env[i], j, ft_strlen(env[i])));
		else
		{
			printf("3\n");
			new = newenv(ft_strsub(env[i], 0, j - 1), ft_strsub(env[i], j, ft_strlen(env[i])));
			printf("3.5\n");
			addenv(&lst, new);
		}
		printf("4\n");
	}
	return (lst);
}

void	addenv(t_env **lst, t_env *new)
{
	t_env	*tmp;

	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
