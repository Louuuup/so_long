/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 18:02:03 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/07/13 14:39:16 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		char_count(char x, char arr[][MAX_TILES_X])
{
	int i;
	int j;
	int	count;

	count = 0;
	i = 0;
	j = 0;
	while (j < MAX_TILES_Y)
	{
		while (i < MAX_TILES_X)
		{
			if (arr[j][i] == x)
				count++;
			i++;
		}
		i = 0;
		j++;
	}
	return (count);
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

// TEST IF ACTUALLY USEFUL
// :o

