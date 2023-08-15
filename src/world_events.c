/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 09:34:53 by yakary            #+#    #+#             */
/*   Updated: 2023/08/14 16:21:40 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// nb = zombie # what
static t_co	zombie_turn(int nb, int dir, t_data *data)
{
	t_co	diff;

	diff.x = 0;
	diff.y = 0;
	data->zombie_facing[nb] = dir;
	if (dir == UP)
		diff.y = -1;
	else if (dir == RIGHT)
		diff.x = +1;
	else if (dir == DOWN)
		diff.y = +1;
	else if (dir == LEFT)
		diff.x = -1;
	else
		ft_error("zombie looking in 4th dimension");
	return (diff);
}

static void	zombie_move(int nb, t_co zb, t_data *dt)
{
	t_co	dest;

	dest.x = 0;
	dest.y = 0;
	if (dt->dst_map[zb.y][zb.x] > dt->dst_map[zb.y + 1][zb.x] \
		&& dt->map[zb.y + 1][zb.x] != WALL && dt->map[zb.y + 1][zb.x] != PORTAL \
		&& dt->map[zb.y + 1][zb.x] != ZOMBIE)
		dest = zombie_turn(nb, DOWN, dt);
	else if (dt->dst_map[zb.y][zb.x] > dt->dst_map[zb.y][zb.x + 1] \
		&& dt->map[zb.y][zb.x + 1] != WALL && dt->map[zb.y][zb.x + 1] != PORTAL \
		&& dt->map[zb.y][zb.x + 1] != ZOMBIE)
		dest = zombie_turn(nb, RIGHT, dt);
	else if (dt->dst_map[zb.y][zb.x] > dt->dst_map[zb.y - 1][zb.x] \
		&& dt->map[zb.y - 1][zb.x] != WALL && dt->map[zb.y - 1][zb.x] != PORTAL \
		&& dt->map[zb.y - 1][zb.x] != ZOMBIE)
		dest = zombie_turn(nb, UP, dt);
	else if (dt->dst_map[zb.y][zb.x] > dt->dst_map[zb.y][zb.x - 1] \
		&& dt->map[zb.y][zb.x - 1] != WALL && dt->map[zb.y][zb.x - 1] != PORTAL \
			&& dt->map[zb.y][zb.x - 1] != ZOMBIE)
		dest = zombie_turn(nb, LEFT, dt);
	if (dt->map[zb.y + dest.y][zb.x + dest.x] != ZOMBIE \
		&& dt->map[dest.y][dest.x] != PORTAL)
		ft_move(zb, dest.x, dest.y, dt);
	if (where_is(0, PLAYER, dt->map).x == -1)
		ft_die();
}

// NB of zombies in map
static void	zombie_think(int nb, t_data *data)
{
	t_co	player;
	int		i;

	i = 0;
	player = where_is(0, PLAYER, data->map);
	while (i < nb)
	{
		data->zombie[i] = where_is(i, ZOMBIE, data->map);
		i++;
	}
	if (player.x < 1)
		ft_error("Player not found");
	flood_clean(data);
	flood_fill(data, player.x, player.y, 1);
	i = 0;
	while (i < nb && data->dst_map[data->zombie[i].y][data->zombie[i].x] != 0)
	{
		data->rdm_key *= data->rdm_key;
		if (ft_rand(3, data->zombie->x / data->zombie->y, data->mv_count) \
			< 2 && i < nb)
			zombie_move(i, data->zombie[i], data);
		i++;
	}
}

void	world_events(t_data *data)
{
	if (data->player_alive)
		zombie_think(char_count(ZOMBIE, data->map), data);
}
