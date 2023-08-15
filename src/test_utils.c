/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:30:57 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/08/14 16:16:44 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_flood(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	printf("\n");
	printf("\n============THE FLOOD MAP============\n");
	while (y < MAX_TILES_X)
	{
		x = 0;
		while (x < MAX_TILES_X)
		{
			if (data->dst_map[y][x] == 0)
				printf("## ");
			else if (data->dst_map[y][x] - 1 > 9)
				printf("%d ", data->dst_map[y][x] - 1);
			else
				printf("0%d ", data->dst_map[y][x] - 1);
			x++;
		}
		y++;
		printf("\n");
	}
	printf("\n");
}

void	print_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	printf("\n=============THE MAP============\n");
	while (!(y >= data->player.y - MAX_RANGE))
		y++;
	while (y < MAX_TILES_Y && y < data->player.y + MAX_RANGE && y \
	>= data->player.y - MAX_RANGE)
	{
		if (data->map[y][x] != '\0')
			ft_putchar_fd('\n', 1);
		while (!(x >= data->player.x - MAX_RANGE))
			x++;
		while (x < MAX_TILES_X && x < data->player.x + MAX_RANGE \
		&& x >= data->player.x - MAX_RANGE)
		{
			ft_putchar_fd(data->map[y][x], 1);
			x++;
		}
		x = 0;
		y++;
	}
	printf("\n");
}

void	print_altmap(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	printf("\n==========THE ALT MAP==========\n");
	while (!(y >= data->player.y - MAX_RANGE))
		y++;
	while (y < MAX_TILES_Y && y < data->player.y + MAX_RANGE && y \
	>= data->player.y - MAX_RANGE)
	{
		if (data->base_map[y][x] != '\0')
			ft_putchar_fd('\n', 1);
		while (!(x >= data->player.x - MAX_RANGE))
			x++;
		while (x < MAX_TILES_X && x < data->player.x + MAX_RANGE \
		&& x >= data->player.x - MAX_RANGE)
		{
			ft_putchar_fd(data->base_map[y][x], 1);
			x++;
		}
		x = 0;
		y++;
	}
	printf("\n");
}
