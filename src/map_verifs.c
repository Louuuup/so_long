/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verifs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:10:21 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/08/01 14:47:58 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_possible(void)
{
    return ;
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
		if (map[y][x] != '1')
			return (ERROR);
		x++;
	}
	x = 0;
	while (y <= (int)data->height)
	{
		if (map[y][x] != '1')
			return (ERROR);
		y++;
	}
	y--;
	while (x <= (int)data->length)
	{
		if (map[y][x] != '1')
			return (ERROR);
		x++;
	}
	x--;
	y = 0;
	while (y <= (int)data->height)
	{
		if (map[y][x] != '1')
			return (ERROR);
		y++;
	}
	return (NO_ERROR);
}
int	map_legal(t_data *data, char map[][MAX_TILES_X])
{
    int result;

    result = char_count('P', map);
    if (result < 1)
		ft_error("Need a player.");
   	else if (result > 1)
		ft_error("Too many players. One max");
	if (map_is_framed(data, map))
		ft_error("Walls(1) are needed all around the map");
return (0);
}