/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:08:50 by tpipi             #+#    #+#             */
/*   Updated: 2024/02/19 19:27:23 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct mlx_struct
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct win_size_struct
{
	int	width;
	int	height;
}	t_win;

typedef struct images_struct
{
	void	*background;
	void	*ship;
	void	*planet;
	void	*asteroid;
	void	*astronaut;
}	t_img;

typedef struct t_container_struct
{
	t_mlx	mlx;
	t_win	win_size;
	t_img	imgs;
	char	**map;
	int		x_pos;
	int		y_pos;
	int		nb_mov;
}	t_container;

#endif