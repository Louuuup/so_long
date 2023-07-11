/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:08:31 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/07/11 17:50:30 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void    mv_up(void)
// {
//     size_t  i;
//     t_tile *tiles;
//     tiles = get_data()->tiles;
//     i = 0;
// 	printf("Player at z=%d\n", tiles->player->instances->z);
//     while (tiles->floor->instances[i].enabled)
//     {
//         tiles->floor->instances[i].x -= TILE_SIZE / 2;
//         tiles->wall->instances[i].x -= TILE_SIZE / 2;
//         tiles->wall->instances[i].y += TILE_SIZE / 4;
//         tiles->floor->instances[i].y += TILE_SIZE / 4;
//         i++;
//     }
//     get_data()->start[1]--;
//     tiles->player->instances->z = depth_hander();
// }

// void    mv_down(void)
// {
//     size_t  i;
//     t_tile *tiles;
//     tiles = get_data()->tiles;
//     i = 0;
// 	printf("Player at z=%d\n", tiles->player->instances->z);
//     while (tiles->floor->instances[i].enabled)
//     {
//         tiles->floor->instances[i].x += TILE_SIZE / 2;
//         tiles->wall->instances[i].x += TILE_SIZE / 2;
//         tiles->wall->instances[i].y -= TILE_SIZE / 4;
//         tiles->floor->instances[i].y -= TILE_SIZE / 4;
//         i++;
//     }
//     get_data()->start[1]++;
//     tiles->player->instances->z = depth_hander();
// }

// void    mv_left(void)
// {
//     size_t  i;
//     t_tile *tiles;
//     tiles = get_data()->tiles;
//     i = 0;
// 	printf("Player at z=%d\n", tiles->player->instances->z);
//     while (tiles->floor->instances[i].enabled)
//     {
//         tiles->floor->instances[i].x += TILE_SIZE / 2;
//         tiles->wall->instances[i].x += TILE_SIZE / 2;
//         tiles->wall->instances[i].y += TILE_SIZE / 4;
//         tiles->floor->instances[i].y += TILE_SIZE / 4;
//         i++;
//     }
//     tiles->player->instances->z = depth_hander();
// }

// void    mv_right(void)
// {
//     size_t  i;
//     t_tile *tiles;
//     tiles = get_data()->tiles;
//     i = 0;
// 	printf("Player at z=%d\n", tiles->player->instances->z);
//     while (tiles->floor->instances[i].enabled)
//     {
//         tiles->floor->instances[i].x -= TILE_SIZE / 2;
//         tiles->wall->instances[i].x -= TILE_SIZE / 2;
//         tiles->wall->instances[i].y -= TILE_SIZE / 4;
//         tiles->floor->instances[i].y -= TILE_SIZE / 4;
//         i++;
//     }
//     tiles->player->instances->z = depth_hander();
// }


void    mv_right(void)
{
    t_data  *data;
    t_co    *co;
    
    data = get_data();
    co = &data->player;
	printf("(%d,%d)", co->x, co->y);
    if (data->map[co->y][co->x + 1] == '0')
    {
        ft_swap(&data->map[co->y][co->x], &data->map[co->y][co->x + 1]);
        re_render(data);
    }
}

void    mv_left(void)
{
    t_data  *data;
    t_co    *co;
    
    data = get_data();
    co = &data->player;
	printf("(%d,%d)", co->x, co->y);
    if (data->map[co->y][co->x - 1] == '0')
    {
        ft_swap(&data->map[co->y][co->x], &data->map[co->y][co->x - 1]);
        re_render(data);
    }
}

void    mv_up(void)
{
    t_data  *data;
    t_co    *co;
    
    data = get_data();
    co = &data->player;
	printf("(%d,%d)", co->x, co->y);
    if (data->map[co->y - 1][co->x] == '0')
    {
        ft_swap(&data->map[co->y][co->x], &data->map[co->y - 1][co->x]);
        re_render(data);
    }
}

void    mv_down(void)
{
    t_data  *data;
    t_co    *co;
    
    data = get_data();
    co = &data->player;
	printf("(%d,%d)", co->x, co->y);
    if (data->map[co->y + 1][co->x] == '0')
    {
        ft_swap(&data->map[co->y][co->x], &data->map[co->y + 1][co->x]);
        re_render(data);
    }
}

