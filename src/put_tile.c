/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_tile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:22:24 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/06/29 18:01:59 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


int	iso_x(int x, int y, int anchor)
{
	int x_out;
	x_out = x * 0.5 * TILE_SIZE + y * -0.5 * TILE_SIZE - TILE_SIZE / 2 + anchor;
	return (x_out);
}

int	iso_y(int x, int y, int anchor)
{
	int	y_out;
	y_out = x * 0.25 * TILE_SIZE + y * 0.25 * TILE_SIZE + TILE_SIZE / 2 + anchor;
	return (y_out);
}

int	put_tile(mlx_t *mlx, mlx_image_t *img, int x, int y)
{
	int	i;
	
	i = mlx_image_to_window(mlx, img, x, y);
	// printf("x: %zu\n", x);
	printf("Placing tile at (%d,%d,%d)\n", x, y, i);
    if (i == -1)
        ft_error();
	return (i);
}

void    depth_hander(void)
{
    size_t  i;
    t_tile *tiles;

    tiles = get_data()->tiles;
    i = 0;
    printf("\n");
    // printf("z is %d\n", tiles->floor->instances[0].z);
    while (tiles->floor->instances[i].enabled)
    {
        tiles->floor->instances[i].x += 64;
        i++;
    }
}

int	parse_tiles(char c, mlx_image_t *tile)
{
	size_t	i;
	size_t	j;
	t_data	*data;

	data = get_data();

	i = 0;
	j = 0;

	while (j < MAX_TILES_Y)
	{
		while (i < MAX_TILES_X)
		{
			if (c == '0' && data->line[j][i] == 'P')
			{
				put_tile(data->mlx, get_data()->tiles->floor, iso_x(i, j, data->tiles->anchor_x), iso_y(i, j, data->tiles->anchor_y));
			}
			else if (data->line[j][i] == c)
			{
				printf("Gerenating '%c' tile.\n", c);
				put_tile(data->mlx, tile, iso_x(i, j, data->tiles->anchor_x), iso_y(i, j, data->tiles->anchor_y));
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}
