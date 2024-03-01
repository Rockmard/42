/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:02:33 by tpipi             #+#    #+#             */
/*   Updated: 2023/10/31 18:43:15 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	last_seen;

	i = 0;
	last_seen = 0;
	while (s[i])
	{
		i++;
		if (s[i] == (unsigned char)c)
			last_seen = i;
	}
	if (s[last_seen] == (unsigned char)c)
		return ((char *)s + last_seen);
	return (0);
}
