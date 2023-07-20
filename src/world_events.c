/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakary <yakary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 09:34:53 by yakary            #+#    #+#             */
/*   Updated: 2023/07/20 00:21:15 by yakary           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
static void zombie_turn(t_co zombie, int nb, int dir, t_data *data)
{
    data->tiles->zombie[dir]->instances[0].enabled
static void zombie_move(int nb, t_co zombie, t_data *data)
{
    t_co dest;
	
	dest.x = zombie.x;
	dest.y = zombie.y;
    if (data->distance_map[zombie.y][zombie.x] > data->distance_map[zombie.y + 1][zombie.x] && data->map[zombie.y + 1][zombie.x] != WALL)
    {
		dest.y++;
        
    }
    else if (data->distance_map[zombie.y][zombie.x] > data->distance_map[zombie.y][zombie.x + 1] && data->map[zombie.y][zombie.x + 1] != WALL)
    {
    	dest.x++;
    }
    else if (data->distance_map[zombie.y][zombie.x] > data->distance_map[zombie.y - 1][zombie.x] && data->map[zombie.y - 1][zombie.x] != WALL)
	{
    	dest.y--;
    }
    else if (data->distance_map[zombie.y][zombie.x] > data->distance_map[zombie.y][zombie.x - 1] && data->map[zombie.y][zombie.x - 1] != WALL)
	{
    	dest.x--;
	}
    if (data->map[dest.y][dest.x] == PLAYER)
		return (ft_die());
	ft_swap(&data->map[zombie.y][zombie.x], &data->map[dest.y][dest.x]);
}

// NB of zombies in map
static void zombie_think(int nb, t_data *data)
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
		data->rdm_key *= data->rdm_key;
		if (ft_rand(3, zombie->x / zombie->y, data->mv_count) < 2)
        	zombie_move(nb, zombie[i], data);
		printf("Distance of %d between zombie and player\n", data->distance_map[zombie[i].y][zombie[i].x] - 2);
		i++;
	}
	// print_flood(data);
}

void    world_events(t_data *data)
{
	if (data->player_alive)
 	   zombie_think(char_count(ZOMBIE, data->map), data);
}