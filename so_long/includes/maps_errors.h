/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_errors.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 09:58:16 by tpipi             #+#    #+#             */
/*   Updated: 2024/02/22 13:43:11 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPS_ERRORS_H
# define MAPS_ERRORS_H

int	is_file_valid(char *map);
int	is_map_valid(char **map);
int	char_errors_check(char **map);
int	errors_check(char **map, char *file);

#endif