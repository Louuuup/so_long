/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_death.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:26:16 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/08/02 17:52:46 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_die(void)
{
    t_data  *data;
    
	printf("\n\n\nplayer died\n");
    data = get_data();
    if (data->player_alive)
    {
        data->player_alive = 0;
        data->tiles_old->player->enabled = false;
        data->tiles->death_screen[0]->enabled = true;
	    re_render(data);
    }
}

void    menu_up(t_data *data)
{
    if (!data->player_alive)
    {
        data->tiles->death_screen[0]->enabled = true;
        if (data->tiles->death_screen[1]->enabled)
        	data->tiles->death_screen[1]->enabled = false;
    }
	else if (data->win)
    {
        data->tiles->win_screen[0]->enabled = true;
        if (data->tiles->win_screen[1]->enabled)
        	data->tiles->win_screen[1]->enabled = false;
    }
}

void    menu_down(t_data *data)
{
    if (!data->player_alive)
    {
        data->tiles->death_screen[1]->enabled = true;
        if (data->tiles->death_screen[0]->enabled)
            data->tiles->death_screen[0]->enabled = false;
    }
    else if (data->win)
    {
            data->tiles->win_screen[1]->enabled = true;
        if (data->tiles->win_screen[0]->enabled)
            data->tiles->win_screen[0]->enabled = false; 
    }
}

void    menu_press(void)
{
    t_data *data;

    data = get_data();
    if ((!data->player_alive && data->tiles->death_screen[0]->enabled) || (data->win && data->tiles->win_screen[0]->enabled))
    {
		data->player_alive = 1;
        data->tiles->player->enabled = true;
        data->tiles->death_screen[0]->enabled = false;
        data->tiles->win_screen[0]->enabled = false;
        data->key_found = 0;
		data->mv_count = 0;
		data->win = 0;
        parse_main(data->mlx, data->tiles);
    }
    else if (data->tiles->death_screen[1]->enabled || data->tiles->win_screen[1]->enabled)
		exit(EXIT_SUCCESS);

}