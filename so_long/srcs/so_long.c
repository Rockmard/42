/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:17:07 by tpipi             #+#    #+#             */
/*   Updated: 2024/02/22 13:47:31 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	update(void *param)
{
	t_container		*container;

	container = (t_container *)param;
	if (!check_textures())
		mlx_loop_end((*container).mlx.mlx);
	mlx_clear_window(container->mlx.mlx, container->mlx.win);
	fill_background(*container);
	put_walls(*container);
	put_exit(*container);
	put_astronaut(*container);
	put_ship(*container);
	return (0);
}

void	initialize_loop(t_mlx mlx, void *p)
{
	mlx_on_event(mlx.mlx, mlx.win, MLX_KEYDOWN, key_hook, p);
	mlx_on_event(mlx.mlx, mlx.win, MLX_WINDOW_EVENT, window_hook, mlx.mlx);
	mlx_loop_hook(mlx.mlx, update, p);
	mlx_loop(mlx.mlx);
}

void	*initialize_container(t_mlx mlx, t_container *container)
{
	container->mlx = mlx;
	container->imgs = get_images(container->mlx.mlx);
	get_start_pos(&container->x_pos, &container->y_pos, container->map);
	container->nb_mov = 0;
	return (container);
}

int	main(int argc, char **argv)
{
	t_mlx		mlx;
	t_container	container;
	void		*p;

	if (argc == 2)
	{
		container.map = create_tab(argv[1]);
		if (!errors_check(container.map, argv[1]) || !check_textures())
		{
			free_tab(container.map);
			return (-1);
		}
		get_size(&container);
		mlx.mlx = mlx_init();
		mlx.win = mlx_new_window(mlx.mlx, container.win_size.width, \
			container.win_size.height, "./so_long");
		p = initialize_container(mlx, &container);
		initialize_loop(mlx, p);
		destroy_all(container);
	}
	else if (argc < 2)
		ft_putstr_fd("Error\nMissing argv\n", 2);
	else if (argc > 2)
		ft_putstr_fd("Error\nMany argv\n", 2);
	return (0);
}
