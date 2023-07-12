/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_tile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakary <yakary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:22:24 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/07/11 21:14:32 by yakary           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_tile(mlx_t *mlx, mlx_image_t *img, int x, int y)
{
	int	i;
	
	// printf("(%d,%d)\n", x, y);
	i = mlx_image_to_window(mlx, img, x, y);
	// printf("x: %zu\n", x);
	// printf("Placing tile at (%d,%d,%d)\n", x, y, i);
    if (i == -1)
        ft_error();
	else
		return ;
}

//OLD BUT ON SAIT JAMAIS
// int	parse_tiles(char c, mlx_image_t *tile)
// {
// 	int	i;
// 	int	j;
// 	t_data	*data;

// 	data = get_data();
// 	i = 0;
// 	j = 0;
// 	while (j < MAX_TILES_Y && j < data->player.y + MAX_RANGE)
// 	{
// 		while (i < MAX_TILES_X && i < data->player.x + MAX_RANGE)
// 		{
// 			if (data->map[j][i] == c)
// 			{
// 				// printf("Gerenating '%c' tile.\n", c);
// 				put_tile(data->mlx, tile, iso_x(i, j, data->anchor.x), iso_y(i, j, data->anchor.y));
// 			}
// 			i++;
// 		}
// 		i = 0;
// 		j++;
// 	}
// 	return (0);
// }

void	put_floor(t_data	*data)
{
	int x;
	int y;
	
	x = -MAX_RANGE;
	y = -MAX_RANGE;
	while (y <= (int)data->height + MAX_RANGE && y <= data->player.y + MAX_RANGE)
	{
		while (x <= (int)data->length + MAX_RANGE && x <= data->player.x + MAX_RANGE)
		{
			// printf("Placing some floors at (%d,%d)\n", x, y);
			put_tile(data->mlx, data->tiles->floor[rand_8(x, y)], iso_x(x, y, data->anchor.x), iso_y(x, y, data->anchor.y));
			x++;
		}
		x = -MAX_RANGE - 1;
		y++;
	}
}
void	put_object(t_data	*data)
{
	int x;
	int y;
	
	x = 0;
	y = 0;
	while (y <= (int)data->height && y <= data->player.y + MAX_RANGE)
	{
		while (x <= (int)data->length && x <= data->player.x + MAX_RANGE)
		{
			if (data->map[y][x] == '1')
				put_tile(data->mlx, data->tiles->wall, iso_x(x, y, data->anchor.x), iso_y(x, y, data->anchor.y));
			else if (data->map[y][x] == 'P')
				put_tile(data->mlx, data->tiles->player[1], iso_x(x, y, data->anchor.x), iso_y(x, y, data->anchor.y));
			x++;
		}
		x = 0;
		y++;
	}
}

int	rand_8(int	x, int	y)
{
	t_data		*data;

	// printf("Randomizing...\n");
	data = get_data();
	if (x < 0)
		x = -x;
	if (y < 0)
		y = -y;
	// printf("RDM_KEY: %llu\n", data->rdm_key);
	data->rdm_key = x * data->rdm_key + y;
	// printf("Randomized %llu\n", data->rdm_key % 8);
	return (data->rdm_key % 8);
}