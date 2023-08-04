/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:08:31 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/08/04 13:32:27 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    mv_right(void)
{
    t_data  *data;
    t_co    co;
    
    data = get_data();
    co = data->player;
	if (data->player_alive && !data->win)
    {
        // printf("(%d,%d)\n", co->x, co->y);
        data->player_facing = 1;
        if (data->map[co.y][co.x + 1] == ZOMBIE)
            ft_die();
        else if (data->map[co.y][co.x + 1] == KEY)
            collect_key(data, co.x + 1, co.y);
        else if (data->map[co.y][co.x + 1] == PORTAL && data->key_count == data->key_found)
            ft_win();
        else if (data->map[co.y][co.x + 1] != WALL)
		    ft_move(co, +1, 0, data);
        data->mv_count++;
		world_events(get_data());
       	if (data->player_alive && !data->win)
            re_render(data);
    }
}

void    mv_left(void)
{
    t_data  *data;
    t_co    co;
    
    data = get_data();
    co = data->player;
	if (data->player_alive && !data->win)
    {
        data->player_facing = 3;
        if (data->map[co.y][co.x - 1] == ZOMBIE)
            ft_die();
        else if (data->map[co.y][co.x - 1] == KEY)
            collect_key(data, co.x - 1, co.y);
        else if (data->map[co.y][co.x - 1] == PORTAL && data->key_count == data->key_found)
            ft_win();
        else if (data->map[co.y][co.x - 1] != WALL)
		    ft_move(co, -1, 0, data);
            // ft_swap(&data->map[co->y][co->x], &data->map[co->y][co->x - 1]);
        data->mv_count++;
       	world_events(get_data());
       	if (data->player_alive && !data->win)
		    re_render(data);
    }
}

void    mv_up(void)
{
    t_data  *data;
    t_co    co;
    
    data = get_data();
    co = data->player;
	if (data->player_alive && !data->win)
    {
        data->player_facing = 0;
        if (data->map[co.y - 1][co.x] == ZOMBIE)
            ft_die();
        else if (data->map[co.y - 1][co.x] == KEY)
            collect_key(data, co.x, co.y - 1);
        else if (data->map[co.y - 1][co.x] == PORTAL && data->key_count == data->key_found)
            ft_win();
        else if (data->map[co.y - 1][co.x] != WALL)
		    ft_move(co, 0, -1, data);
        data->mv_count++;
	    world_events(get_data());
       	if (data->player_alive && !data->win)
	        re_render(data);
    }
	else
		menu_up(data);
}

void    mv_down(void)
{
    t_data  *data;
    t_co    co;
    
        data = get_data();
        co = data->player;
	if (data->player_alive && !data->win)
    {
        // printf("(%d,%d)\n", co->x, co->y);
        data->player_facing = 2;
        if (data->map[co.y + 1][co.x] == ZOMBIE)
            ft_die();
        else if (data->map[co.y + 1][co.x] == KEY)
            collect_key(data, co.x, co.y + 1); 
        else if (data->map[co.y + 1][co.x] == PORTAL && data->key_count == data->key_found)
            ft_win();
        else if (data->map[co.y + 1][co.x] != WALL)
		    ft_move(co, 0, +1, data);
        data->mv_count++;
	    world_events(get_data());
       	if (data->player_alive && !data->win)
	        re_render(data);
    }
	else
		menu_down(data);
}

