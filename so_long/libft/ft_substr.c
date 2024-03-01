/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:11:09 by tpipi             #+#    #+#             */
/*   Updated: 2023/11/09 15:14:27 by tpipi            ###   ########.fr       */
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	int		i;
	int		malloc_size;

	i = 0;
	if (ft_const_strlen(s) < start)
		malloc_size = 0;
	else if (ft_const_strlen(s) - start < len)
		malloc_size = ft_const_strlen(s) - start;
	else
		malloc_size = len;
	new_str = malloc((malloc_size + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	while (i < malloc_size && s[start + i])
	{
		new_str[i] = s[start + i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
