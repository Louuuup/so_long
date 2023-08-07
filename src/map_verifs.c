/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verifs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:10:21 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/08/07 15:49:40 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_possible(t_data *data)
{
	t_co player;
	t_co co;
	int	keys;
	int i;
	
	i = 0;
	keys = char_count(KEY, data->map);
	player = where_is(0, PLAYER, data->map);
	flood_clean(data);
	flood_fill(data, player.x, player.y, 1);
	while (i < keys)
	{
		co = where_is(i, KEY, data->map);
		if (!data->distance_map[co.y][co.x])
			ft_error("Key unreachable");
		i++;
	}
	co = where_is(0, PORTAL, data->map);
	if (!data->distance_map[co.y][co.x])
			ft_error("Exit unreachable");
}
// Tests if the map has '1's all around it. 
static int	map_is_framed(t_data *data, char map[][MAX_TILES_X])
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x <= (int)data->length)
	{
		if (map[y][x] != WALL)
			return (NO);
		x++;
	}
	x = 0;
	while (y <= (int)data->height)
	{
		if (map[y][x] != WALL)
			return (NO);
		y++;
	}
	y--;
	while (x <= (int)data->length)
	{
		if (map[y][x] != WALL)
			return (NO);
		x++;
	}
	x--;
	y = 0;
	while (y <= (int)data->height)
	{
		if (map[y][x] != WALL)
			return (NO);
		y++;
	}
	return (YES);
}

int	map_legal(t_data *data, char map[][MAX_TILES_X])
{
    int result;

    result = char_count(PLAYER, map);
    if (result < 1)
		ft_error("Need a player.");
   	else if (result > 1)
		ft_error("Too many players. One max");
    result = char_count(PORTAL, map);
	if (result < 1)
		ft_error("Need an exit.");
   	else if (result > 1)
		ft_error("Too exits. One max");
	else if (!map_is_framed(data, map))
		ft_error("Walls(1) are needed all around the map");
	if (data->zombie_count > MAX_ZOMBIES)
		ft_error("Too many zombies(Z). Change maximum in header file");
	map_possible(data);
	return (0);
}
