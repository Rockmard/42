/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:34:48 by tpipi             #+#    #+#             */
/*   Updated: 2024/02/20 10:56:06 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	fill_background(t_container container)
{
	int		i;
	int		j;

	i = 0;
	while (i < container.win_size.height)
	{
		j = 0;
		while (j < container.win_size.width)
		{
			mlx_put_image_to_window(container.mlx.mlx, container.mlx.win, \
				container.imgs.background, j, i);
			j += 50;
		}
		i += 50;
	}
}

void	put_walls(t_container container)
{
	int		x;
	int		y;

	y = 0;
	while (container.map[y])
	{
		x = 0;
		while (container.map[y][x])
		{
			if (container.map[y][x] == '1')
				mlx_put_image_to_window(container.mlx.mlx, container.mlx.win, \
					container.imgs.asteroid, x * 50, y * 50);
			x++;
		}
		y++;
	}
}

void	put_exit(t_container container)
{
	int		x;
	int		y;

	y = 0;
	while (container.map[y])
	{
		x = 0;
		while (container.map[y][x])
		{
			if (container.map[y][x] == 'E')
				mlx_put_image_to_window(container.mlx.mlx, container.mlx.win, \
					container.imgs.planet, x * 50, y * 50);
			x++;
		}
		y++;
	}
}

void	put_astronaut(t_container container)
{
	int		x;
	int		y;

	y = 0;
	while (container.map[y])
	{
		x = 0;
		while (container.map[y][x])
		{
			if (container.map[y][x] == 'C')
				mlx_put_image_to_window(container.mlx.mlx, container.mlx.win, \
					container.imgs.astronaut, x * 50, y * 50);
			x++;
		}
		y++;
	}
}

void	put_ship(t_container container)
{
	mlx_put_image_to_window(container.mlx.mlx, container.mlx.win, \
		container.imgs.ship, container.x_pos * 50, container.y_pos * 50);
}
