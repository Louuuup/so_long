/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:37:31 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/08/08 14:52:37 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
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
	// print_map(data);
	player_placement(data);
    put_floor(data);
	put_object(data);
	if (data->player_alive && !data->win)
		mlx_image_to_window(data->mlx, data->tiles->dark, 0, 0);
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
	data->tiles_old = data->tiles;
	put_info(data);
}
