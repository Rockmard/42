/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:48:30 by tpipi             #+#    #+#             */
/*   Updated: 2023/11/02 16:34:43 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int	i;

	i = 1;
	if (n < 0)
		i++;
	while (n / 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	ft_get_next_char(char *s, int *n, int *i)
{
	s[*i] = *n % 10 + 48;
	*n /= 10;
	*i -= 1;
}

char	*ft_itoa(int n)
{
	char	*ascii;
	int		i;
	int		last_index;

	ascii = malloc((ft_numlen(n) + 1) * sizeof(char));
	if (!ascii)
		return (NULL);
	i = ft_numlen(n) - 1;
	last_index = ft_numlen(n);
	if (n < 0)
	{
		if (n == -2147483648)
		{
			ascii[1] = '2';
			n = -147483648;
		}
		n *= -1;
		ascii[0] = '-';
	}
	while (n >= 10)
		ft_get_next_char(ascii, &n, &i);
	ascii[i] = n + 48;
	ascii[last_index] = 0;
	return (ascii);
}
