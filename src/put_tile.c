/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_tile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:22:24 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/07/19 15:34:00 by ycyr-roy         ###   ########.fr       */
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
			put_tile(data->mlx, data->tiles->floor[ft_rand(8, x, y)], iso_x(x, y, data->anchor.x), iso_y(x, y, data->anchor.y));
			x++;
		}
		x = -MAX_RANGE - 1;
		y++;
	}
}
static void put_other(int x, int y, t_data *data)
{
	if (data->map[y][x] == ZOMBIE)
	{
		put_tile(data->mlx, data->tiles->zombie[0], iso_x(x, y, data->anchor.x), iso_y(x, y, data->anchor.y));
		put_tile(data->mlx, data->tiles->zombie[1], iso_x(x, y, data->anchor.x), iso_y(x, y, data->anchor.y));
		put_tile(data->mlx, data->tiles->zombie[2], iso_x(x, y, data->anchor.x), iso_y(x, y, data->anchor.y));
		put_tile(data->mlx, data->tiles->zombie[3], iso_x(x, y, data->anchor.x), iso_y(x, y, data->anchor.y));
	}
}
void	put_object(t_data	*data)
{
	int x;
	int y;
	
	y = 0;
	while (!(y >= data->player.y - MAX_RANGE))
		y++;
	while (y <= (int)data->height && y <= data->player.y + MAX_RANGE && y >= data->player.y - MAX_RANGE)
	{
		x = 0;
		while (x <= (int)data->length && x <= data->player.x + MAX_RANGE)
		{
			if (data->map[y][x] == WALL)
				put_tile(data->mlx, data->tiles->wall[ft_rand(24, x, y)], iso_x(x, y, data->anchor.x), iso_y(x, y, data->anchor.y));
			else if (data->map[y][x] == PLAYER)
				put_tile(data->mlx, data->tiles->player, iso_x(x, y, data->anchor.x), iso_y(x, y, data->anchor.y));
			else
				put_other(x, y, data);
			x++;
		}
		y++;
	}
}

int	ft_rand(int range, int x, int y)
{
	t_data		*data;
	int			out;

	// printf("Randomizing...\n");
	data = get_data();
	// printf("RDM_KEY: %llu\n", data->rdm_key);
	
	data->rdm_key = x * data->rdm_key + y;
	if (!(data->rdm_key % range))
		data->rdm_key++;
	out = data->rdm_key % range;
	// printf("Randomized %llu\n", data->rdm_key % 8);
	return (out);
}