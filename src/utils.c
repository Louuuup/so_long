/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 18:02:03 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/07/18 17:30:55 by ycyr-roy         ###   ########.fr       */
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

void	ft_free(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return ;	
}

void   ft_swap(char *a, char *b)
{
    char tmp;

    tmp = *a;
    *a =  *b;
    *b = tmp;
}

void    print_map(t_data *data)
{
	int x;
	int y;

	x = 0;
	y = 0;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("YOU ARE AT:(%d,%d)\n", data->player.x, data->player.y);
	printf("\n============THE MAP============\n");
	while (!(y >= data->player.y - MAX_RANGE))
		y++;
	while (y < MAX_TILES_Y && y < data->player.y + MAX_RANGE && y >= data->player.y - MAX_RANGE)
	{
		if (data->map[y][x] != '\0')
			ft_putchar_fd('\n', 1);
		while (!(x >= data->player.x - MAX_RANGE))
			x++;
		while (x < MAX_TILES_X && x < data->player.x + MAX_RANGE && x >= data->player.x - MAX_RANGE)
		{ //add if statement if '/0', dont print?
			ft_putchar_fd(data->map[y][x], 1);
			x++;
		}
		x = 0;
		y++;
	}
	ft_putchar_fd('\n', 1);
	ft_putchar_fd('\n', 1);
}
void    print_flood(t_data *data)
{
	int x;
	int y;

	y = 0;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("YOU ARE AT:(%d,%d)\n", data->player.x, data->player.y);
	printf("\n============THE MAP============\n");
	while (y < MAX_TILES_X)
	{
		x = 0;
		while (x < MAX_TILES_X)
		{
			if (data->distance_map[y][x] == 0)
				printf("## ");
			else if (data->distance_map[y][x] - 1 > 9)
				printf("%d ", data->distance_map[y][x] - 1);
			else
				printf("0%d ", data->distance_map[y][x] - 1);
			x++;
		}
		y++;
		printf("\n");
	}

	ft_putchar_fd('\n', 1);
	ft_putchar_fd('\n', 1);
}

// TEST IF ACTUALLY USEFUL
// :o

