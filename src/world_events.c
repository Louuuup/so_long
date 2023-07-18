/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 09:34:53 by yakary            #+#    #+#             */
/*   Updated: 2023/07/18 17:31:45 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// NB of zombies in map
static void zombie_move(int nb, t_data *data)
{
    t_co player;
    t_co zombie[nb];
    int i;

    i = 0;
    player = where_is(0, PLAYER, data->map);
    while(i < nb)
    {
		zombie[i] = where_is(0, ZOMBIE, data->map);
   		printf("FOUND ZOMBIE #%d (%d,%d)\n", i, zombie[i].x, zombie[i].y);
		i++;
    }
    printf("FOUND P IN (%d,%d)\n", player.x, player.y);
    if (player.x < 1)
        ft_error();
    flood_clean(data);
    flood_fill(data, player.x, player.y, 1);
	i = 0;
	while (i < nb)
    {
		printf("Distance of %d between zombie and player\n", data->distance_map[zombie[i].y][zombie[i].x] - 2);
		i++;
	}
	// print_flood(data);
}

void    world_events(t_data *data)
{
    zombie_move(char_count(ZOMBIE, data->map), data);
}