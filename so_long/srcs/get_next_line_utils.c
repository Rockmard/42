/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:44:12 by tpipi             #+#    #+#             */
/*   Updated: 2024/02/18 13:07:16 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

size_t	ft_strlen2(char *str)
{
	size_t	i;

	i = 0;
	if (str != NULL)
		while (str[i])
			i++;
	return (i);
}

char	*ft_strdup2(char *str, int i, int k)
{
	int		l;
	char	*dup;

	if (!str)
		return (NULL);
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

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	str = malloc(ft_strlen2(s1) + ft_strlen2(s2) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 != NULL && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 != NULL && s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	if (s1)
		free(s1);
	str[i + j] = '\0';
	return (str);
}

char	*ft_strcut(char *str, size_t cut)
{
	int		i;
	char	*res;

	if (cut == 0)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	res = malloc((ft_strlen2(str) - cut + 1) * sizeof(char));
	if (!res)
		return (NULL);
	if (cut > ft_strlen2(str))
		return (NULL);
	while (str && str[cut + i])
	{
		res[i] = str[cut + i];
		i++;
	}
	res[i] = 0;
	if (str)
		free(str);
	return (res);
}
