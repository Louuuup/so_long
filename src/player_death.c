/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_death.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:26:16 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/07/18 19:23:53 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_die(void)
{
    t_data  *data;
    
    data = get_data();
    data->player_alive = 0;
    data->tiles_old->player->enabled = false;
    data->tiles->death_screen[1]->enabled = true;
}

void    menu_up(t_data *data)
{
    data->tiles->death_screen[1]->enabled = true;
    if (data->tiles->death_screen[2]->enabled)
        data->tiles->death_screen[2]->enabled = false;
}

void    menu_down(t_data *data)
{
    data->tiles->death_screen[2]->enabled = true;
    if (data->tiles->death_screen[1]->enabled)
       	 data->tiles->death_screen[1]->enabled = false;

}

void    menu_press(void)
{
    // if (data->tiles->death_screen[1]->enabled)
	// {
		
	// }
    if (get_data()->tiles->death_screen[2]->enabled)
		exit(EXIT_SUCCESS);

}