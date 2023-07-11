/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:00:29 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/07/11 17:49:54 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    map_read(int fd, t_data *data)
{
    char	buffer[MAX_TILES_X * MAX_TILES_Y];
	int		i;
	int		x;
	int		y;

	ft_bzero(buffer, MAX_TILES_X * MAX_TILES_Y);
	i = 0;
	x = 0;
	y = 0;

    read(fd, buffer, MAX_TILES_X * MAX_TILES_Y);
		while (y < MAX_TILES_Y)
		{
			x = 0;
			while ((buffer[i] != '\n' && buffer[i] != '\0'))
			{
				if (x < MAX_TILES_X)
					data->map[y][x] = buffer[i];
				i++;
				x++;
			}
			i++;
			y++;
		}
}
