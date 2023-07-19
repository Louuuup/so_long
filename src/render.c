/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:37:31 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/07/19 14:28:13 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    un_render(mlx_t *mlx, t_tile *tiles_old)
{
	int	i;

	i = 0;
	if	(tiles_old)
	{
  		mlx_delete_image(mlx, tiles_old->player);
		while (i < 25)
		{
			mlx_delete_image(mlx, tiles_old->wall[i]);
			i++;
		}
		i = 0;
		while (i < 8)
		{
			mlx_delete_image(mlx, tiles_old->floor[i]);
			i++;
		}
		mlx_delete_image(mlx, tiles_old->death_screen[0]);
		mlx_delete_image(mlx, tiles_old->death_screen[1]);
		mlx_delete_image(mlx, tiles_old->death_screen[2]);
		mlx_delete_image(mlx, tiles_old->dark);
		ft_free((void *)tiles_old);
	}
}

void	re_render(t_data *data)
{
	
	if (data->tiles_old)
   		un_render(data->mlx, data->tiles_old);
	data->tiles = ft_calloc(1, sizeof(t_tile));
	if (!data->tiles)
	{
		printf("-----MALLOC ERROR-----\n");
		;
	}
	texture_convert(data->mlx, data->textures, data->tiles);
	rendering(data);
}

void    rendering(t_data *data)
{
	char *ptr;

	ptr = NULL;
	printf("FT: player_placement()...\n");
	player_placement(data);
	printf("FT: put_floor()...\n");
    put_floor(data);
	printf("FT: put_object()...\n");
	put_object(data);
	mlx_image_to_window(data->mlx, data->tiles->dark, 0, 0);
	mlx_image_to_window(data->mlx, data->tiles->death_screen[0], 0, 0);
	mlx_image_to_window(data->mlx, data->tiles->death_screen[1], 0, 0);
	mlx_image_to_window(data->mlx, data->tiles->death_screen[2], 0, 0);
	ptr = ft_strjoin("X: ", ft_itoa(data->player.x));
    mlx_put_string(data->mlx, ptr, 5, 5);
	ptr = ft_free((void *)ptr);
	ptr = ft_strjoin("Y: ", ft_itoa(data->player.y));
    mlx_put_string(data->mlx, ptr, 5, 25);
	ptr = ft_free((void *)ptr);
	ptr = ft_strjoin("MOVES: ", ft_itoa(data->mv_count));
    mlx_put_string(data->mlx, ptr, 5, 50);
	ptr = ft_free((void *)ptr);
	data->tiles_old = data->tiles;
}