/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:11:17 by nrontey           #+#    #+#             */
/*   Updated: 2024/12/20 13:33:17 by nrontey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	draw_player_glow(t_data *data, float pxy[2], int radius, int glow_color)
{
	int	i;
	int	j;
	int	pixel_x;
	int	pixel_y;

	i = -radius;
	while (i <= radius)
	{
		j = -radius;
		while (j <= radius)
		{
			pixel_x = pxy[0] + i;
			pixel_y = pxy[1] + j;
			if (pixel_x < WIDTH && pixel_y < HEIGHT && \
				pixel_x >= 0 && pixel_y >= 0)
			{
				if (i * i + j * j <= radius * radius)
					mlx_draw_pixel(data->img, pixel_x, pixel_y, glow_color);
			}
			j++;
		}
		i++;
	}
}

void	draw_player(t_data *data, int x, int y, int size_modifier)
{
	int		player_size;
	int		radius;
	float	pxy[2];

	player_size = size_modifier / 2;
	pxy[0] = x * size_modifier + (data->map->player->current_position->y - \
		(int)data->map->player->current_position->y) * size_modifier;
	pxy[1] = y * size_modifier + (data->map->player->current_position->x - \
		(int)data->map->player->current_position->x) * size_modifier;
	radius = player_size / 2;
	while (radius >= 0)
	{
		draw_player_glow(data, pxy, radius, \
		mlx_rgb_to_int(0, 255 - (radius * 30), 215 - (radius * 25), 0));
		radius--;
	}
}
