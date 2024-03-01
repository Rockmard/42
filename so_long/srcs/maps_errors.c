/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 09:58:05 by tpipi             #+#    #+#             */
/*   Updated: 2024/02/22 13:43:21 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <errno.h>

int	is_file_valid(char *map)
{
	int		fd;
	char	*ext;

	ext = ft_strrchr(map, '.');
	if (!ext || ft_strncmp(ext, ".ber", 5) != 0)
	{
		ft_putstr_fd("Error\nInvalid extension\n", 2);
		return (0);
	}
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nFile doesn't exist\n", 2);
		return (0);
	}
	if (errno == 21)
	{
		ft_putstr_fd("Error\nIs a directory\n", 2);
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int	is_map_valid(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("10EPC\n", map[i][j]) == NULL)
			{
				ft_putstr_fd("Error\nMap has invalid parameters\n", 2);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	char_errors_check(char **map)
{
	if (!has_one_exit(map))
	{
		ft_putstr_fd("Error\nMap must have one and only one exit\n", 2);
		return (0);
	}
	else if (!has_one_start(map))
	{
		ft_putstr_fd("Error\nMap must have one and only one start\n", 2);
		return (0);
	}
	else if (!has_an_item(map))
	{
		ft_putstr_fd("Error\nMap must have at least one collectable\n", 2);
		return (0);
	}
	return (1);
}

int	errors_check(char **map, char *file)
{
	if (!is_file_valid(file))
		return (0);
	else if (!is_map_valid(map) || !char_errors_check(map))
		return (0);
	else if (!is_framed(map))
	{
		ft_putstr_fd("Error\nMap must be framed by walls\n", 2);
		return (0);
	}
	else if (!is_rectangular(map))
	{
		ft_putstr_fd("Error\nMap must be rectangular\n", 2);
		return (0);
	}
	else if (!is_path_valid(file))
		return (0);
	return (1);
}
