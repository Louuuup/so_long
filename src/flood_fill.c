/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:52:22 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/08/11 14:43:46 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_data *data, int x, int y, int distance)
{
	if (x > MAX_TILES_X || x < 0 || y > MAX_TILES_Y || y < 0
		|| data->map[y][x] == WALL || (data->distance_map[y][x] != 0
	&& data->distance_map[y][x] <= distance))
		return ;
	data->distance_map[y][x] = distance;
	flood_fill(data, x + 1, y, distance + 1);
	flood_fill(data, x - 1, y, distance + 1);
	flood_fill(data, x, y + 1, distance + 1);
	flood_fill(data, x, y - 1, distance + 1);
}

void	flood_clean(t_data *data)
{
	int	y;

	y = 0;
	while (y < MAX_TILES_Y)
	{
		ft_bzero(data->distance_map[y], MAX_TILES_X * sizeof(int));
		y++;
	}
}
