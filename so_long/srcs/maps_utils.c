/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 10:25:29 by tpipi             #+#    #+#             */
/*   Updated: 2024/02/20 16:50:24 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_size(t_container *container)
{
	int	i;

	if (!(*container).map || !(*container).map[0])
		return ;
	i = 0;
	(*container).win_size.width = (ft_strlen((*container).map[0]) - 1) * 50;
	(*container).win_size.height = 0;
	while ((*container).map[i])
	{
		i++;
		(*container).win_size.height += 50;
	}
}

int	get_nb_tab(char **map)
{
	int	i;

	i = 0;
	while (map && map[i] && map[i][0])
		i++;
	return (i);
}

int	get_nb_line(char *map)
{
	int		i;
	int		fd;
	char	*gnl;

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (0);
	while (1)
	{
		gnl = get_next_line(fd);
		if (!gnl)
			break ;
		i++;
		free(gnl);
	}
	close(fd);
	return (i);
}

int	get_map_score(char **map)
{
	int	i;
	int	j;
	int	score;

	i = 0;
	score = 0;
	while (map && map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E' || map[i][j] == 'C')
				score++;
			j++;
		}
		i++;
	}
	return (score);
}

int	is_only_1(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}
