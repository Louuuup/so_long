/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:07:51 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/06/29 18:02:32 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


void	player_anchor(void)
{
		int	x;
		int	y;
		int tmp;
		
		x = 0;
		y = 0;
		tmp = 0;
	while (y < MAX_TILES_Y)
	{
		while (x < MAX_TILES_X)
		{
			if (get_data()->line[y][x] == 'P')
			{
				get_data()->start[0] = x;
				get_data()->start[1] = y;
				get_data()->tiles->anchor_x = WIDTH / 2 - iso_x(x, y, 0);
				get_data()->tiles->anchor_y = HEIGHT / 2 - iso_y(x, y, 0);
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
	data->height = 1;
	data->length = 1;
	while (data->line[data->height][data->length] != '\0' &&  data->length <= MAX_TILES_X)
	{
		data->length++;
	}
	data->length--;
	while (data->line[data->height][data->length] != '\0' && data->height <= MAX_TILES_Y)
	{
		data->height++;
	}
	// data->tiles->anchor = data->length / 2 * TILE_SIZE;
	// printf("X: %zu\nY: %zu\nANCHOR: %zu\n", data->length, data->height, data->tiles->anchor);
	
}

void	parse_read(void)
{
	char	*line;
	int		fd;
	size_t	i;
	
	i = 0;
    fd = 0;
	line = NULL;
	fd = open(MAP, O_RDONLY);
	if (fd < 0)
		return ;
	while (1)
	{
		line = get_next_line(fd);
		ft_strlcpy(get_data()->line[i], line, MAX_TILES_X);
		if (!line || line[0] == '\0')
			break ;
		else
			free(line);
		line = NULL;
		i++;
	}
    fd = close(fd);
	ft_dimensions(); //might be useless soon =D
}

void	parse_main(mlx_t *mlx, t_tile *tiles)
{
	size_t	i;
	
	i = 0;
	(void)mlx;
	parse_read();
	player_anchor();
	parse_tiles('P', tiles->player);
	tiles->player->instances->z = (parse_tiles('0', tiles->floor) + parse_tiles('1', tiles->wall));
}


// get_data()->images;