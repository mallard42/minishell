/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 18:10:03 by mallard           #+#    #+#             */
/*   Updated: 2017/06/18 17:07:10 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int		ft_strncount(char const *s, char c, char d)
{
	int			i;
	int			result;

	i = 0;
	result = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c || ((s[i] == d || s[i + 1] == '\0') && \
					(s[i + 1] != c && s[i + 1] != d)))
			result++;
		i++;
	}
	return (result);
}

static char		**ft_cut(char **str, const char *s)
{
	int			i;
	int			d;
	int			j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		d = i;
		if (s[i] != '\t' && s[i] != ' ')
		{
			while ((s[d] != '\t' && s[d] != ' ') && s[d] != '\0')
				d++;
			if (!(str[j] = ft_strnew(d - i)))
				return (NULL);
			d = 0;
			while ((s[i] != '\t' && s[i] != ' ') && s[i] != '\0')
				str[j][d++] = s[i++];
			j++;
		}
		else
			i++;
	}
	str[j] = NULL;
	return (str);
}

char			**ft_split(char const *s)
{
	int			i;
	char		**str;

	if (!s)
		return (NULL);
	i = 0;
	if (!(str = ft_memalloc(sizeof(char *) * (ft_strncount(s, ' ', '\t') + 1))))
		return (NULL);
	str = ft_cut(str, s);
	return (str);
}
