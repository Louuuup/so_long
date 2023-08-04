/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 09:34:53 by yakary            #+#    #+#             */
/*   Updated: 2023/08/04 16:15:10 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// nb = zombie # what
static t_co zombie_turn(int nb, int dir, t_data *data)
{
    t_co diff;

    diff.x = 0;
    diff.y = 0;
    data->zombie_facing[nb] = dir;
    if (dir == UP)
    {
        diff.y = -1;
        printf("zombie #%d looking UP!!\n", nb);
    }
    else if (dir == RIGHT)
    {
        diff.x = +1;
        printf("zombie #%d looking RIGHT!!\n", nb);
    }
    else if (dir == DOWN)
    {
        diff.y = +1;
        printf("zombie #%d looking DOWN!!\n", nb);
    }
    else if (dir == LEFT)
    {
        diff.x = -1;
        printf("zombie #%d looking LEFT!!\n", nb);
    }
    return (diff);
}

static void zombie_move(int nb, t_co zombie, t_data *data)
{
    t_co dest;

    if (data->distance_map[zombie.y][zombie.x] > data->distance_map[zombie.y + 1][zombie.x] && data->map[zombie.y + 1][zombie.x] != WALL && data->map[zombie.y + 1][zombie.x] != PORTAL)
    {
        dest = zombie_turn(nb, DOWN, data);
    }
    else if (data->distance_map[zombie.y][zombie.x] > data->distance_map[zombie.y][zombie.x + 1] && data->map[zombie.y][zombie.x + 1] != WALL && data->map[zombie.y][zombie.x + 1] != PORTAL)
    {
        dest = zombie_turn(nb, RIGHT, data);
    }
    else if (data->distance_map[zombie.y][zombie.x] > data->distance_map[zombie.y - 1][zombie.x] && data->map[zombie.y - 1][zombie.x] != WALL && data->map[zombie.y - 1][zombie.x] != PORTAL)
	{
        dest = zombie_turn(nb, UP, data);
    }
    else if (data->distance_map[zombie.y][zombie.x] > data->distance_map[zombie.y][zombie.x - 1] && data->map[zombie.y][zombie.x - 1] != WALL && data->map[zombie.y][zombie.x - 1] != PORTAL)
	{
        dest = zombie_turn(nb, LEFT, data);
	}
    if (data->map[dest.y][dest.x] != ZOMBIE && data->map[dest.y][dest.x] != PORTAL)
	    ft_move(zombie, dest.x, dest.y, data);
	if (where_is(0, PLAYER, data->map).x == -1)
		{
			printf("PLAYER was killed by ZOMBIE\n");
			ft_die();
		}
	// ft_swap(&data->map[zombie.y][zombie.x], &data->map[dest.y][dest.x]);
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
		zombie[i] = where_is(i, ZOMBIE, data->map);
		i++;
    }
    // printf("FOUND P IN (%d,%d)\n", player.x, player.y);
    if (player.x < 1)
        ft_error("Player not found");
    flood_clean(data);
    flood_fill(data, player.x, player.y, 1);
	i = 0;
	while (i < nb && data->distance_map[zombie[i].y][zombie[i].x] != 0)
    {
		data->rdm_key *= data->rdm_key;
		if (ft_rand(3, zombie->x / zombie->y, data->mv_count) < 2 && i < nb)
        	zombie_move(i, zombie[i], data);
		// printf("Distance of %d between zombie and player\n", data->distance_map[zombie[i].y][zombie[i].x] - 2);
		i++;
	}
	// print_flood(data);
}

void    world_events(t_data *data)
{
    // printf("nb of ZOMBIES: %d\n", char_count(ZOMBIE, data->map));
	if (data->player_alive)
 	   zombie_think(char_count(ZOMBIE, data->map), data);    










}