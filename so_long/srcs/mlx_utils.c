/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:22:39 by tpipi             #+#    #+#             */
/*   Updated: 2024/02/20 12:33:44 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_image_missing(char *img)
{
	int	fd;

	fd = open(img, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nMissing texture\n", 2);
		return (0);
	}
	close(fd);
	return (1);
}

int	check_textures(void)
{
	if (!is_image_missing("textures/background.png"))
		return (0);
	if (!is_image_missing("textures/asteroid.png"))
		return (0);
	if (!is_image_missing("textures/astronaut.png"))
		return (0);
	if (!is_image_missing("textures/ship_up.png"))
		return (0);
	if (!is_image_missing("textures/ship_left.png"))
		return (0);
	if (!is_image_missing("textures/ship_down.png"))
		return (0);
	if (!is_image_missing("textures/ship_right.png"))
		return (0);
	if (!is_image_missing("textures/planet.png"))
		return (0);
	return (1);
}

t_img	get_images(void *mlx)
{
	t_img	imgs;
	int		width;
	int		height;

	imgs.background = mlx_png_file_to_image(mlx, \
		"textures/background.png", &width, &height);
	imgs.asteroid = mlx_png_file_to_image(mlx, \
		"textures/asteroid.png", &width, &height);
	imgs.astronaut = mlx_png_file_to_image(mlx, \
		"textures/astronaut.png", &width, &height);
	imgs.ship = mlx_png_file_to_image(mlx, \
		"textures/ship_up.png", &width, &height);
	imgs.planet = mlx_png_file_to_image(mlx, \
		"textures/planet.png", &width, &height);
	return (imgs);
}

void	destroy_all(t_container container)
{
	mlx_destroy_image(container.mlx.mlx, container.imgs.background);
	mlx_destroy_image(container.mlx.mlx, container.imgs.asteroid);
	mlx_destroy_image(container.mlx.mlx, container.imgs.astronaut);
	mlx_destroy_image(container.mlx.mlx, container.imgs.planet);
	mlx_destroy_image(container.mlx.mlx, container.imgs.ship);
	mlx_destroy_window(container.mlx.mlx, container.mlx.win);
	mlx_destroy_display(container.mlx.mlx);
	free_tab(container.map);
}
