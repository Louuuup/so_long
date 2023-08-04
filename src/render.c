/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:37:31 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/08/04 15:42:03 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    un_render(mlx_t *mlx, t_tile *tiles_old)
{
	int	i;

	if	(tiles_old)
	{
		tiles_old->player->enabled = true;
  		mlx_delete_image(mlx, tiles_old->player);
		i = -1;
		while (++i < NB_WALL_TX)
			mlx_delete_image(mlx, tiles_old->wall[i]);
		i = -1;
		while (++i < NB_FLOOR_TX)
			mlx_delete_image(mlx, tiles_old->floor[i]);
		i = -1;
		while (++i < NB_KEY_TX)
			mlx_delete_image(mlx, tiles_old->key[i]);
		i = -1;
		while (	++i < NB_ZOMBIE_TX)
			mlx_delete_image(mlx, tiles_old->zombie[i]);
		mlx_delete_image(mlx, tiles_old->death_screen[0]);
		mlx_delete_image(mlx, tiles_old->death_screen[1]);
		mlx_delete_image(mlx, tiles_old->win_screen[0]);
		i = -1;
		while (	++i < NB_PORTAL_TX)
			mlx_delete_image(mlx, tiles_old->portal[i]);
		mlx_delete_image(mlx, tiles_old->win_screen[1]);
		mlx_delete_image(mlx, tiles_old->portal_off);
		mlx_delete_image(mlx, tiles_old->dark);
	}
}

void	re_render(t_data *data)
{
	
	if (data->tiles_old)
	{
		un_render(data->mlx, data->tiles_old);
		ft_free(data->tiles_old);
	}
	data->tiles = ft_calloc(1, sizeof(t_tile));
	if (!data->tiles)
		ft_error("allocation error.");
	texture_convert(data->mlx, data->textures, data->tiles);
	rendering(data);
}

void    rendering(t_data *data)
{
	int i;

	i = -1;
	print_map(data);
	print_altmap(data);
	player_placement(data);
    put_floor(data);
	put_object(data);
	// if (data->player_alive && !data->win)
	// 	mlx_image_to_window(data->mlx, data->tiles->dark, 0, 0);
	if (!data->player_alive)
	{
		mlx_image_to_window(data->mlx, data->tiles->death_screen[0], 0, 0);
		mlx_image_to_window(data->mlx, data->tiles->death_screen[1], 0, 0);
	}
	if (data->win)
	{
		mlx_image_to_window(data->mlx, data->tiles->win_screen[0], 0, 0);
		mlx_image_to_window(data->mlx, data->tiles->win_screen[1], 0, 0);
	}
	ft_info_onscreen(data->mlx, 5, 15, ft_strjoin("X: ", ft_itoa(data->player.x)));
	ft_info_onscreen(data->mlx, 5, 30, ft_strjoin("Y: ", ft_itoa(data->player.y)));
	ft_info_onscreen(data->mlx, 5, 45, ft_strjoin("MOVES: ", ft_itoa(data->mv_count)));
	ft_info_onscreen(data->mlx, 5, 60, ft_strjoin("KEYS FOUND: ", ft_itoa(data->key_found)));
	ft_info_onscreen(data->mlx, 135, 60, ft_strjoin("/", ft_itoa(data->key_count)));
	data->tiles_old = data->tiles;
}
