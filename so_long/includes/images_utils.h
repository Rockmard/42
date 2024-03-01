/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:35:39 by tpipi             #+#    #+#             */
/*   Updated: 2024/02/19 14:49:08 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGES_UTILS_H
# define IMAGES_UTILS_H

# include "./so_long.h"

void	fill_background(t_container container);
void	put_walls(t_container container);
void	put_exit(t_container container);
void	put_astronaut(t_container container);
void	put_ship(t_container container);

#endif