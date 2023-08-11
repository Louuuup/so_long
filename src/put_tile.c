/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_tile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:22:24 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/08/11 15:45:29 by ycyr-roy         ###   ########.fr       */
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
	int	x;
	int	y;

	x = -MAX_RANGE;
	y = -MAX_RANGE;
	while (y <= (int)data->height + MAX_RANGE && y \
		<= data->player.y + MAX_RANGE)
	{
		while (x <= (int)data->length + MAX_RANGE && x \
			<= data->player.x + MAX_RANGE)
		{
			put_tile(data->mlx, data->tiles->floor[ft_rand(8, x, y)], \
				iso_x(x, y, data->anc.x), iso_y(x, y, data->anc.y));
			x++;
		}
		x = -MAX_RANGE - 1;
		y++;
	}
}

static void	put_animated(int x, int y, char map[][MAX_TILES_X], t_data *data)
{
	int	i;

	if (map[y][x] == KEY)
	{
		i = -1;
		while (++i < NB_KEY_TX)
			put_tile(data->mlx, data->tiles->key[i], \
				iso_x(x, y, data->anc.x), iso_y(x, y, data->anc.y));
	}
	else if (map[y][x] == PORTAL)
	{
		if (data->key_count > data->key_found)
			put_tile(data->mlx, data->tiles->portal_off, \
				iso_x(x, y, data->anc.x), iso_y(x, y, data->anc.y));
		else
		{
			i = -1;
			while (++i < NB_PORTAL_TX)
				put_tile(data->mlx, data->tiles->portal[i], \
					iso_x(x, y, data->anc.x), iso_y(x, y, data->anc.y));
		}
	}
}

//t_data renamed dt for space purposes
static void	put_other(int x, int y, t_data *dt)
{
	if (dt->base_map[y][x] == KEY || dt->base_map[y][x] == PORTAL)
		put_animated(x, y, dt->base_map, dt);
	if (dt->map[y][x] == ZOMBIE)
	{
		if (dt->zombie_facing[dt->zb_count] < 0)
			dt->zombie_facing[dt->zb_count] = 0;
		put_tile(dt->mlx, dt->tiles->zombie[dt->zombie_facing[dt->zb_count]], \
			iso_x(x, y, dt->anc.x), iso_y(x, y, dt->anc.y));
		dt->zb_count++;
	}
	else if (dt->map[y][x] == PLAYER)
		put_tile(dt->mlx, dt->tiles->player, iso_x(x, y, dt->anc.x), \
			iso_y(x, y, dt->anc.y));
}

void	put_object(t_data	*dt)
{
	t_co	co;

	co.y = 0;
	while (!(co.y >= dt->player.y - MAX_RANGE))
		co.y++;
	while (co.y <= (int)dt->height && co.y <= dt->player.y + MAX_RANGE \
		&& co.y >= dt->player.y - MAX_RANGE)
	{
		co.x = 0;
		while (co.x <= (int)dt->length && co.x <= dt->player.x + MAX_RANGE)
		{
			if (dt->map[co.y][co.x] == WALL)
				put_tile(dt->mlx, dt->tiles->wall[ft_rand(24, co.x, co.y)], \
					iso_x(co.x, co.y, dt->anc.x), iso_y(co.x, co.y, dt->anc.y));
			else if (dt->map[co.y][co.x] == PLAYER)
				put_tile(dt->mlx, dt->tiles->player, \
					iso_x(co.x, co.y, dt->anc.x), iso_y(co.x, co.y, dt->anc.y));
			else if (dt->map[co.y][co.x] == KEY || dt->map[co.y][co.x] == 69)
				put_animated(co.x, co.y, dt->map, dt);
			else if (dt->map[co.y][co.x] == PLAYER || dt->map[co.y][co.x] == 90)
				put_other(co.x, co.y, dt);
			co.x++;
		}
		co.y++;
	}
}
