/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:07:51 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/07/11 20:10:23 by ycyr-roy         ###   ########.fr       */
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
			// printf("(%d,%d) working\n", x, y);
			if (data->map[y][x] == 'P')
			{
				// printf("(%d,%d) working, found P\n", x, y);
				data->player.x = x;
				data->player.y = y;
				data->anchor.x = WIDTH / 2 - iso_x(x, y, 0);
				data->anchor.y = HEIGHT / 2 - iso_y(x, y, 0);
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
	while (data->map[data->height][data->length] != '\0' &&  data->length <= MAX_TILES_X)
	{
		data->length++;
	}
	data->length--;
	while (data->map[data->height][data->length] != '\0' && data->height <= MAX_TILES_Y)
	{
		data->height++;
	}
	data->height--;
	
	// data->tiles->anchor = data->length / 2 * TILE_SIZE;
	// printf("X: %zu\nY: %zu\nANCHOR: %zu\n", data->length, data->height, data->tiles->anchor);
	
}

void	parse_read(void)
{
	int		fd;
	size_t	i;
	t_data	*data;
	
	data = get_data();
	i = 0;
    fd = 0;
	fd = open(MAP, O_RDONLY);
	if (fd < 0)
		return ;
	map_read(fd, data);
    fd = close(fd);
	ft_dimensions();
	printf("Reading DONE\n");
}

void	parse_main(mlx_t *mlx, t_tile *tiles)
{
	size_t	i;
	
	i = 0;
	(void)mlx;
	(void)tiles;
	printf("Reading...\n");
	parse_read();
	printf("Rendering...\n");
    rendering(get_data());
	printf("Parsing DONE\n");
	// printf("\nBase_depth: %d\n", get_data()->player_base_depth);
	// printf("Player at z=%d\n", tiles->player->instances->z);
}


// get_data()->images;