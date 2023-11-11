/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:45:17 by tpipi             #+#    #+#             */
/*   Updated: 2023/11/09 15:15:51 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_const_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str != NULL)
		while (str[i])
			i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	str = malloc(ft_const_strlen(s1) + ft_const_strlen(s2) + 1);
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
	str[i + j] = '\0';
	return (str);
}
