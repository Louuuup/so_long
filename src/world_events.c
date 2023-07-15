/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakary <yakary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:33:48 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/07/15 01:24:43 by yakary           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


static void zombie_move(t_data *data)
{
    t_co co;

    co = where_is(0, PLAYER, data->map);
    printf("FOUND P IN (%d,%d)\n", co.x, co.y);
    flood_fill(data, co.x, co.y, 1);
    printf("Distance of %d between zombie and player\n", data->distance_map[co.y][co.x] - 1);
    
}

void    world_events(t_data *data)
{
    zombie_move(data);
}