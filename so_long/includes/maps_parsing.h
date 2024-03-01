/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_parsing.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:56:33 by tpipi             #+#    #+#             */
/*   Updated: 2024/02/18 18:08:54 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPS_PARSING_H
# define MAPS_PARSING_H

int	has_one_exit(char **map);
int	has_one_start(char **map);
int	has_an_item(char **map);
int	is_rectangular(char **map);
int	is_framed(char **map);

#endif