/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:07:51 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/08/15 11:50:12 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_placement(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < MAX_TILES_Y)
	{
		while (x < MAX_TILES_X)
		{
			if (data->map[y][x] == 'P')
			{
				data->player.x = x;
				data->player.y = y;
				data->anc.x = WIDTH / 2 - iso_x(x, y, 0) - 64;
				data->anc.y = HEIGHT / 2 - iso_y(x, y, 0) - 32;
				return ;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_dimensions(void)
{
	t_data	*data;

	data = get_data();
	data->height = 0;
	data->length = 0;
	while (data->map[data->height][data->length] != '\0' && data->length \
	<= MAX_TILES_X)
	{
		data->length++;
	}
	data->length--;
	while (data->map[data->height][data->length] != '\0' && data->height \
	<= MAX_TILES_Y)
	{
		data->height++;
	}
	data->height--;
}

void	parse_read(void)
{
	int		fd;
	t_data	*data;

	data = get_data();
	fd = 0;
	fd = open(data->map_path, O_RDONLY);
	if (fd < 0)
		ft_error("Invalid map name or path\n(maps/<map_name>)");
	map_read(fd, data, 0, 0);
	fd = close(fd);
	ft_dimensions();
}

void	parse_main(mlx_t *mlx, t_tile *tiles)
{
	(void)mlx;
	(void)tiles;
	parse_read();
	rendering(get_data());
}
