/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:33:13 by tpipi             #+#    #+#             */
/*   Updated: 2024/02/20 11:12:47 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_UTILS_H
# define EVENT_UTILS_H

int		key_hook(int key, void *param);
int		window_hook(int event, void *param);
int		are_collectible_left(t_container container);
void	change_image(t_container *container, char *new_img);
void	make_move(t_container *container, int new_x, int new_y, char *new_img);

#endif