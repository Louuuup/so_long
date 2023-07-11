/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_tile_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:22:03 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/07/11 17:44:20 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	iso_x(int x, int y, int anchor)
{
	int x_out;
	x_out = (x * 0.5 * TILE_SIZE) + (y * -0.5 * TILE_SIZE) - (TILE_SIZE / 2) + anchor;
	return (x_out);
}

int	iso_y(int x, int y, int anchor)
{
	int	y_out;
	y_out = (x * 0.25 * TILE_SIZE) + (y * 0.25 * TILE_SIZE) + (TILE_SIZE / 2) + anchor;
	return (y_out);
}

// RETURNS AMOUNT OF WALLS('1') IN MAP UNTIL P.
// int    depth_hander(void)
// {
//     int  z;
//     int  i;
//     int  j;
//   	t_data	*data;

//     data = get_data();
// 	i = 0;
// 	j = 0;
// 	z = data->player_base_depth;
// 	while (j < MAX_TILES_Y)
// 	{
// 		while (i < MAX_TILES_X)
// 		{
// 			if (data->line[j][i] == '1')
// 			{
// 				z++;
// 				printf("WAll AT %d\n", z);
// 			}
// 			else if (i == data->start.x && j == data->start.y)
// 				return (z);
// 			i++;
// 		}
// 		i = 0;
// 		j++;
// 	}
// 	return (z + 1);
// }