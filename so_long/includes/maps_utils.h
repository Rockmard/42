/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 10:29:59 by tpipi             #+#    #+#             */
/*   Updated: 2024/02/19 15:15:04 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPS_UTILS_H
# define MAPS_UTILS_H

void	get_size(t_container *container);
int		get_nb_line(char *map);
int		get_nb_tab(char **map);
int		get_map_score(char **map);
int		is_only_1(char *line);

#endif