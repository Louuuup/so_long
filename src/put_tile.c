/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_tile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:22:24 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/08/02 16:20:13 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_tile(mlx_t *mlx, mlx_image_t *img, int x, int y)
{
    if (mlx_image_to_window(mlx, img, x, y) == -1)
        ft_error_mlx();
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
static void put_animated(int x, int y, char map[][MAX_TILES_X], t_data *data)
{
	int i;

	if (map[y][x] == KEY)
	{	
		i = -1;
		while (++i < NB_KEY_TX)
			put_tile(data->mlx, data->tiles->key[i], iso_x(x, y, data->anchor.x), iso_y(x, y, data->anchor.y));
	}
	else if (map[y][x] == PORTAL)
	{
		if (data->key_count > data->key_found)
			put_tile(data->mlx, data->tiles->portal_off, iso_x(x, y, data->anchor.x), iso_y(x, y, data->anchor.y));
		else
		{
			i = -1;
			while (++i < NB_PORTAL_TX)
				put_tile(data->mlx, data->tiles->portal[i], iso_x(x, y, data->anchor.x), iso_y(x, y, data->anchor.y));
		}
	}
}

static void put_other(int x, int y, t_data *data)
{
	if (data->base_map[y][x] == KEY || data->base_map[y][x] == PORTAL)
	put_animated(x, y, data->base_map, data);
	if (data->map[y][x] == ZOMBIE)
	{
		// printf("here I place zombie #%d looking %d\n", data->zombie_count, data->zombie_facing[data->zombie_count]);
		if (data->zombie_facing[data->zombie_count] < 0)
			data->zombie_facing[data->zombie_count] = 0;
		put_tile(data->mlx, data->tiles->zombie[data->zombie_facing[data->zombie_count]], iso_x(x, y, data->anchor.x), iso_y(x, y, data->anchor.y));
	}
	else if (data->map[y][x] == PLAYER)
		put_tile(data->mlx, data->tiles->player, iso_x(x, y, data->anchor.x), iso_y(x, y, data->anchor.y));
}

void	put_object(t_data	*data)
{
	int x;
	int y;
	
	y = 0;
	data->zombie_count = 0;
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
			else if (data->map[y][x] == KEY || data->map[y][x] == PORTAL)
				put_animated(x, y, data->map, data);
			else if (data->map[y][x] == PLAYER || data->map[y][x] == ZOMBIE)
				put_other(x, y, data);
			x++;
		}
		y++;
	}
}

