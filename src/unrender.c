/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unrender.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:14:33 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/08/08 14:23:26 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void un_render_assets(mlx_t *mlx, t_tile *tiles_old, int i)
{
    mlx_delete_image(mlx, tiles_old->player);
    i = -1;
	while (++i < NB_KEY_TX)
		mlx_delete_image(mlx, tiles_old->key[i]);
	i = -1;
	while (	++i < NB_ZOMBIE_TX)
		mlx_delete_image(mlx, tiles_old->zombie[i]);
	i = -1;
	while (	++i < NB_PORTAL_TX)
		mlx_delete_image(mlx, tiles_old->portal[i]);
	mlx_delete_image(mlx, tiles_old->portal_off);
}
    

void    un_render_tiles(mlx_t *mlx, t_tile *tiles_old, int i)
{
    i = -1;
	while (++i < NB_FLOOR_TX)
		mlx_delete_image(mlx, tiles_old->floor[i]);
	i = -1;
	while (++i < NB_WALL_TX)
		mlx_delete_image(mlx, tiles_old->wall[i]);
	mlx_delete_image(mlx, tiles_old->death_screen[0]);
	mlx_delete_image(mlx, tiles_old->death_screen[1]);
	mlx_delete_image(mlx, tiles_old->win_screen[0]);
	mlx_delete_image(mlx, tiles_old->win_screen[1]);
	mlx_delete_image(mlx, tiles_old->dark);
}


void    un_render(mlx_t *mlx, t_tile *tiles_old)
{
	int	i;

    i = -1;
	if	(tiles_old)
	{
		tiles_old->player->enabled = true;
        un_render_assets(mlx, tiles_old, i);
        un_render_tiles(mlx, tiles_old, i);
	}
}
