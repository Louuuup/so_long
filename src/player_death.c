/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_death.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:26:16 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/07/20 13:35:20 by ycyr-roy         ###   ########.fr       */
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
        data->tiles->death_screen[1]->enabled = true;
    }
}

void    menu_up(t_data *data)
{
    data->tiles->death_screen[1]->enabled = true;
    if (data->tiles->death_screen[2]->enabled)
        data->tiles->death_screen[2]->enabled = false;
}

void    menu_down(t_data *data)
{
    data->tiles_old->player->enabled = true;
    data->tiles->death_screen[2]->enabled = true;
    if (data->tiles->death_screen[1]->enabled)
       	 data->tiles->death_screen[1]->enabled = false;

}

void    menu_press(void)
{
    t_data *data;

    data = get_data();
    if (data->tiles->death_screen[1]->enabled)
    {
		data->player_alive = 1;
        data->tiles->player->enabled = true;
        data->tiles->death_screen[1]->enabled = false;
        parse_main(data->mlx, data->tiles);
		data->mv_count = 0;
    }
    else if (data->tiles->death_screen[2]->enabled)
		exit(EXIT_SUCCESS);

}