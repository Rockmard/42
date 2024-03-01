/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:56:04 by tpipi             #+#    #+#             */
/*   Updated: 2024/02/22 14:41:11 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	has_one_exit(char **map)
{
	int	exit_cnt;
	int	i;
	int	j;

	exit_cnt = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				exit_cnt++;
			j++;
		}
		i++;
	}
	return (exit_cnt == 1);
}

int	has_one_start(char **map)
{
	int	start_cnt;
	int	i;
	int	j;

	start_cnt = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				start_cnt++;
			j++;
		}
		i++;
	}
	return (start_cnt == 1);
}

int	has_an_item(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_rectangular(char **map)
{
	int				i;
	int				line_id;
	unsigned long	line_len;

	line_id = 0;
	i = 0;
	if (!map[i])
		return (0);
	line_len = ft_strlen(map[i]);
	while (map[i] && line_id++ < get_nb_tab(map) - 1)
	{
		if (!map[i] || ft_strlen(map[i]) != line_len)
			return (0);
		i++;
	}
	if (!map[i] || (ft_strlen(map[i]) < line_len - 1) || \
		(map[i][line_len - 1] && map[i][line_len - 1] != '\n') || \
		map[i][line_len - 2] != '1')
		return (0);
	return (1);
}

int	is_framed(char **map)
{
	int	i;

	i = 0;
	if (!map[i] || !is_only_1(map[i]) || get_nb_tab(map) < 3)
		return (0);
	while (map[i] && i < get_nb_tab(map) - 1)
	{
		i++;
		if (map[i][0] != '1' || ft_strlen(map[i]) < 2 || \
			map[i][ft_strlen(map[i]) - 2] != '1')
			return (0);
	}
	if (!is_only_1(map[i]))
		return (0);
	return (1);
}
