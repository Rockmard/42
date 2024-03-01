/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:28:54 by tpipi             #+#    #+#             */
/*   Updated: 2024/02/20 11:34:23 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

int		is_image_missing(char *img);
int		check_textures(void);
t_img	get_images(void *mlx);
void	destroy_all(t_container container);

#endif