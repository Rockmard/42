/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color_text.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:49:39 by nrontey           #+#    #+#             */
/*   Updated: 2024/12/18 14:34:29 by nrontey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	is_color_ok(t_textures *textures)
{
	int	color_exist;
	int	rgb_valid;

	color_exist = textures->f_r == -1 || textures->f_g == -1 || \
	textures->f_b == -1 || textures->c_r == -1 || \
	textures->c_g == -1 || textures->c_b == -1;
	rgb_valid = textures->f_r < 0 || textures->f_r > 255 || textures->f_g < 0 \
	|| textures->f_g > 255 || textures->f_b < 0 || textures->f_b > 255 || \
	textures->c_r < 0 || textures->c_r > 255 || textures->c_g < 0 \
	|| textures->c_g > 255 || textures->c_b < 0 || textures->c_b > 255;
	return (color_exist || rgb_valid);
}

static int	ends_with_xpm(char *filename)
{
	int	len;

	if (!filename)
		return (0);
	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	return (ft_strncmp(filename + len - 4, ".xpm", 4) == 0);
}

static int	is_xpm_file(char *filename)
{
	int		fd;
	char	buffer[128];
	int		bytes_read;

	if (!ends_with_xpm(filename))
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	close(fd);
	if (bytes_read <= 0)
		return (0);
	buffer[bytes_read] = '\0';
	if (ft_strnstr(buffer, "/* XPM */", bytes_read) == NULL)
		return (0);
	if (ft_strnstr(buffer, "static char *", bytes_read) == NULL)
		return (0);
	return (1);
}

int	is_texture_ok(t_textures *textures)
{
	char	*files[4];
	int		i;
	int		ok_count;

	files[0] = textures->no_file;
	files[1] = textures->so_file;
	files[2] = textures->we_file;
	files[3] = textures->ea_file;
	ok_count = 0;
	i = 0;
	while (i < 4)
	{
		if (is_xpm_file(files[i]))
			ok_count++;
		i++;
	}
	return (ok_count != 4);
}
