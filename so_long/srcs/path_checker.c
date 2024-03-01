/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 13:22:25 by tpipi             #+#    #+#             */
/*   Updated: 2024/02/20 12:54:14 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	does_path_exist(char **map, int x, int y, int *score)
{
	if (x == -1 || y == -1 || !map[y] || !map[y][x] || \
		map[y][x] == '\n' || map[y][x] == '1')
		return ;
	if (map[y][x] == 'E' || map[y][x] == 'C')
	{
		map[y][x] = '0';
		(*score)++;
	}
	map[y][x] = '1';
	does_path_exist(map, x - 1, y, score);
	does_path_exist(map, x + 1, y, score);
	does_path_exist(map, x, y - 1, score);
	does_path_exist(map, x, y + 1, score);
}

char	**create_tab(char *map)
{
	char	**tab;
	char	*gnl;
	int		i;
	int		fd;

	i = 0;
	fd = open(map, O_RDONLY);
	if (!map || fd < 0)
		return (NULL);
	tab = ft_calloc((sizeof(char *)), get_nb_line(map) + 1);
	if (!tab)
		return (NULL);
	while (1)
	{
		gnl = get_next_line(fd);
		if (!gnl)
			break ;
		tab[i] = ft_strdup(gnl);
		free(gnl);
		i++;
	}
	tab[i] = NULL;
	close(fd);
	return (tab);
}

void	get_start_pos(int *x, int *y, char **map)
{
	int		i;
	int		j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'P')
				*x = i;
			if (map[j][i] == 'P')
				*y = j;
			i++;
		}
		j++;
	}
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
		free(tab);
}

int	is_path_valid(char *map)
{
	char	**tab;
	int		x;
	int		y;
	int		score;
	int		path_res;

	tab = create_tab(map);
	if (!tab || !tab[0])
		return (0);
	get_start_pos(&x, &y, tab);
	score = get_map_score(tab);
	path_res = 0;
	does_path_exist(tab, x, y, &path_res);
	free_tab(tab);
	if (score != path_res)
	{
		ft_putstr_fd("Error\nNo valid path\n", 2);
		return (0);
	}
	return (1);
}
