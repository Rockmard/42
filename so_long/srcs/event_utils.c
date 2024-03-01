/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:32:35 by tpipi             #+#    #+#             */
/*   Updated: 2024/02/20 11:45:51 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	change_image(t_container *container, char *new_img)
{
	int		width;
	int		height;
	void	*tmp;

	tmp = (*container).imgs.ship;
	(*container).imgs.ship = mlx_png_file_to_image((*container).mlx.mlx, \
		new_img, &width, &height);
	mlx_destroy_image((*container).mlx.mlx, tmp);
}

int	are_collectible_left(t_container container)
{
	int	i;
	int	j;

	i = 0;
	while (container.map && container.map[i])
	{
		j = 0;
		while (container.map[i][j])
		{
			if (container.map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	make_move(t_container *container, int new_x, int new_y, char *new_img)
{
	change_image(container, new_img);
	if (new_x > 0 && new_y > 0 && (*container).map[new_y] && \
	(*container).map[new_y][new_x] && (*container).map[new_y][new_x] != '1' && \
	(*container).map[new_y][new_x] != '\n')
	{
		if ((*container).map[new_y][new_x] == 'C')
			(*container).map[new_y][new_x] = '0';
		(*container).x_pos = new_x;
		(*container).y_pos = new_y;
		(*container).nb_mov++;
		ft_putstr_fd("Movement number :", 1);
		ft_putnbr_fd((*container).nb_mov, 1);
		ft_putstr_fd("\n", 1);
		if (!are_collectible_left(*container) && \
			(*container).map[new_y][new_x] == 'E')
			mlx_loop_end((*container).mlx.mlx);
	}
}

int	key_hook(int key, void *param)
{
	t_container	*container;

	container = (t_container *)param;
	if (key == 41)
		mlx_loop_end((*container).mlx.mlx);
	else if (key == 26)
		make_move(container, (*container).x_pos, (*container).y_pos - 1, \
		"textures/ship_up.png");
	else if (key == 4)
		make_move(container, (*container).x_pos - 1, (*container).y_pos, \
		"textures/ship_left.png");
	else if (key == 22)
		make_move(container, (*container).x_pos, (*container).y_pos + 1, \
		"textures/ship_down.png");
	else if (key == 7)
		make_move(container, (*container).x_pos + 1, (*container).y_pos, \
		"textures/ship_right.png");
	return (0);
}

int	window_hook(int event, void *param)
{
	if (event == 0)
		mlx_loop_end(param);
	return (0);
}
