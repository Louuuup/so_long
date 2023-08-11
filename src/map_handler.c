/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:00:29 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/08/11 15:08:04 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_read(int fd, t_data *data, int x, int y)
{
	char	buffer[MAX_TILES_X * MAX_TILES_Y];
	int		i;
	int		bytes;

	ft_bzero(buffer, MAX_TILES_X * MAX_TILES_Y);
	i = 0;
	bytes = read(fd, buffer, MAX_TILES_X * MAX_TILES_Y);
	while (y < MAX_TILES_Y)
	{
		x = 0;
		while ((buffer[i] != '\n' && buffer[i] != '\0'))
		{
			if (x < MAX_TILES_X)
				data->map[y][x] = buffer[i];
			data->base_map[y][x] = buffer[i];
			i++;
			x++;
		}
		i++;
		y++;
	}
	base_map_clean(data);
}

void	base_map_clean(t_data *data)
{
	int		i;
	t_co	co;

	i = 0;
	data->zb_count = char_count(ZOMBIE, data->base_map);
	co = where_is(0, PLAYER, data->base_map);
	data->base_map[co.y][co.x] = FLOOR;
	while (i < data->zb_count)
	{
		printf("i = %d\n", i);
		co = where_is(i, ZOMBIE, data->map);
		printf("removing Zombie at (%d,%d)\n", co.x, co.y);
		print_altmap(data);
		data->base_map[co.y][co.x] = FLOOR;
		i++;
	}
	data->key_count = char_count(KEY, data->map);
	print_altmap(data);
	printf ("defining key_count for %d\n", data->key_count);
}
