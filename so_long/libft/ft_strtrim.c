/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:07:45 by tpipi             #+#    #+#             */
/*   Updated: 2023/11/09 15:18:23 by tpipi            ###   ########.fr       */
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

static int	is_in(char c, const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void	ft_get_size(char const *s, char const *set, int *start, int *end)
{
	int	s_len;
	int	i;

	i = 0;
	s_len = ft_const_strlen(s) - 1;
	while (is_in(s[s_len], set))
		s_len--;
	while (s_len > 0 && s[i] && is_in(s[i], set))
		i++;
	*start = i;
	*end = s_len;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	int		start;
	int		end;
	int		i;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	start = 0;
	end = 0;
	ft_get_size(s1, set, &start, &end);
	new_str = malloc(sizeof(char) * (end - start + 2));
	if (!new_str)
		return (NULL);
	while (s1[start] && start <= end)
	{
		new_str[i] = s1[start];
		i++;
		start++;
	}
	new_str[i] = '\0';
	return (new_str);
}
