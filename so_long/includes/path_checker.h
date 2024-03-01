/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 13:22:49 by tpipi             #+#    #+#             */
/*   Updated: 2024/02/19 14:16:52 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_CHECKER_H
# define PATH_CHECKER_H

char	**create_tab(char *map);
void	get_start_pos(int *x, int *y, char **map);
void	free_tab(char **tab);
void	does_path_exist(char **map, int x, int y, int *score);
int		is_path_valid(char *map);

#endif