/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:48:12 by tpipi             #+#    #+#             */
/*   Updated: 2023/10/31 18:41:43 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (((unsigned char *)s)[i] != (unsigned char)c && i < n - 1)
		i++;
	if (((unsigned char *)s)[i] == (unsigned char)c)
		return ((void *)s + i);
	return (0);
}
