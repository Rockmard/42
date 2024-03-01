/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:02:39 by tpipi             #+#    #+#             */
/*   Updated: 2023/11/02 16:35:44 by tpipi            ###   ########.fr       */
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

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	full_size;

	if (size == 0)
		return (ft_const_strlen(src));
	i = ft_strlen(dst);
	j = 0;
	full_size = ft_strlen(dst) + ft_strlen(src);
	if (ft_strlen(dst) >= size)
		return (ft_strlen(src) + size);
	while ((i < size - 1) && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (full_size);
}
