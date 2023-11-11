/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:49:30 by tpipi             #+#    #+#             */
/*   Updated: 2023/11/09 14:56:56 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_split(const char *str, char c)
{
	int	split_count;
	int	i;

	split_count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			split_count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (split_count);
}

static void	*free_all(char **char_tab, const char *s, char c)
{
	int	i;

	i = count_split(s, c);
	while (i >= 0)
	{
		free(char_tab[i]);
		i--;
	}
	free(char_tab);
	return (NULL);
}

static char	*ft_const_strdup(const char *str, int i, int k)
{
	int		l;
	char	*dup;

	l = 0;
	dup = malloc(sizeof(char) * (i - k + 1));
	if (dup == NULL)
		return (NULL);
	while (k < i)
	{
		dup[l] = str[k];
		l++;
		k++;
	}
	dup[l] = '\0';
	return (dup);
}

static char	**cut(char **char_tab, const char *str, char c, int size)
{
	int		i;
	int		k;
	int		index_malloc;

	i = 0;
	index_malloc = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		k = i;
		while (str[i] && str[i] != c)
			i++;
		if (str[i] || index_malloc == size - 1)
		{
			char_tab[index_malloc] = ft_const_strdup(str, i, k);
			if (!char_tab[index_malloc])
				return (free_all(char_tab, str, c));
			index_malloc++;
		}
	}
	char_tab[index_malloc] = NULL;
	return (char_tab);
}

char	**ft_split(char const *s, char c)
{
	char	**char_tab;

	if (s == NULL)
	{
		char_tab = malloc(sizeof(char *) * 1);
		char_tab[0] = NULL;
		return (char_tab);
	}
	char_tab = malloc(sizeof(char *) * (count_split(s, c) + 1));
	if (char_tab == NULL)
		return (NULL);
	char_tab = cut(char_tab, s, c, count_split(s, c));
	return (char_tab);
}
