/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:08:31 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/07/17 14:14:30 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    mv_right(void)
{
    t_data  *data;
    t_co    *co;
    
    data = get_data();
    co = &data->player;
	printf("(%d,%d)", co->x, co->y);
    data->player_facing = 1;
    if (data->map[co->y][co->x + 1] != WALL && data->map[co->y][co->x + 1] != ZOMBIE)
        ft_swap(&data->map[co->y][co->x], &data->map[co->y][co->x + 1]);
    world_events(get_data());
    re_render(data);
}

void    mv_left(void)
{
    t_data  *data;
    t_co    *co;
    
    data = get_data();
    co = &data->player;
	printf("(%d,%d)", co->x, co->y);
    data->player_facing = 3;
    if (data->map[co->y][co->x - 1] != WALL && data->map[co->y][co->x - 1] != ZOMBIE)
        ft_swap(&data->map[co->y][co->x], &data->map[co->y][co->x - 1]);
    world_events(get_data());
    re_render(data);
}

void    mv_up(void)
{
    t_data  *data;
    t_co    *co;
    
    data = get_data();
    co = &data->player;
	printf("(%d,%d)", co->x, co->y);
    data->player_facing = 0;
    if (data->map[co->y - 1][co->x] != WALL && data->map[co->y - 1][co->x] != ZOMBIE)

        ft_swap(&data->map[co->y][co->x], &data->map[co->y - 1][co->x]);
    world_events(get_data());
    re_render(data);
}

void    mv_down(void)
{
    t_data  *data;
    t_co    *co;
    
    data = get_data();
    co = &data->player;
	printf("(%d,%d)", co->x, co->y);
    data->player_facing = 2;
    if (data->map[co->y + 1][co->x] != WALL && data->map[co->y + 1][co->x] != ZOMBIE)

        ft_swap(&data->map[co->y][co->x], &data->map[co->y + 1][co->x]);
    world_events(get_data());
    re_render(data);
}

