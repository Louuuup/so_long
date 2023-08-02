/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 18:02:03 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/08/02 15:48:28 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		char_count(char c, char arr[][MAX_TILES_X])
{
	int	count;
	t_co	co;

	co.x = 0;
	co.y = 0;
	count = 0;
	while (co.y < MAX_TILES_Y)
	{
		while (co.x < MAX_TILES_X)
		{
			if (arr[co.y][co.x] == c)
				count++;
			co.x++;
		}
		co.x = 0;
		co.y++;
	}
	return (count);
}

t_co	where_is(int skip, char c, char map[][MAX_TILES_X])
{
	int	count;
	t_co	co;

	co.x = 0;
	co.y = 0;
	count = 0;
	while (co.y < MAX_TILES_Y)
	{
		while (co.x < MAX_TILES_X)
		{
			if (map[co.y][co.x] == c)
			{
				if (skip > count)
					count++;
				else
					return (co);	
			}
			co.x++;
		}
		co.x = 0;
		co.y++;
	}
	co.x = -1;
	co.y = -1;
	return (co);
}

void	*ft_free(void *ptr)
{
	if (ptr != NULL)
		free(ptr);
	return (ptr);	
}

void   ft_swap(char *a, char *b)
{
    char tmp;

    tmp = *a;
    *a =  *b;
    *b = tmp;
}

void	ft_move(t_co src, int x_m, int y_m, t_data *data)
{
	t_co dst;

	dst.x = src.x + x_m; 
	dst.y = src.y + y_m; 
	data->map[dst.y][dst.x] = data->map[src.y][src.x];
	if (data->base_map[src.y][src.x] != PLAYER)
		data->map[src.y][src.x] = data->base_map[src.y][src.x];
}