/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 05:54:36 by nrontey           #+#    #+#             */
/*   Updated: 2024/12/20 13:33:16 by nrontey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

unsigned int	mlx_rgb_to_int(int o, int r, int g, int b)
{
	return (o << 24 | r << 16 | g << 8 | b);
}

unsigned int	mlx_get_pixel(t_img *img, int x, int y)
{
	return (*(unsigned int *)
		(img->data + (x * img->bpp / 8 + y * img->size_line)));
}

void	mlx_draw_pixel(t_img *mlx_img, int x, int y, int color)
{
	char			*target;

	target = mlx_img->data + (x * mlx_img->bpp / 8 + y * mlx_img->size_line);
	*(unsigned int *)target = color;
}

int	get_tile_color(t_data *data, int x, int y)
{
	if (data->map->map_2d[y][x] == '1')
		return (mlx_rgb_to_int(0, 70, 130, 180));
	return (mlx_rgb_to_int(0, 47, 79, 79));
}

void	draw_pixel_if_valid(t_data *data, int x, int y, int color)
{
	if (x < WIDTH && y < HEIGHT && x >= 0 && y >= 0)
		mlx_draw_pixel(data->img, x, y, color);
}
