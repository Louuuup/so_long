/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:37:31 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/07/11 17:41:49 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_to_old(t_data *data)
{
	
	data->tiles_old = NULL;
}

void    un_render(mlx_t *mlx, t_tile *tiles_old)
{
	int	i;

	i = 0;
	if	(tiles_old)
	{
  		mlx_delete_image(mlx, tiles_old->player[1]);
		mlx_delete_image(mlx, tiles_old->wall);
		while (i < 8)
		{
			mlx_delete_image(mlx, tiles_old->floor[i]);
			i++;
		}
		ft_free((void *)&tiles_old);
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
		return ;
	}
	texture_convert(data->mlx, data->textures, data->tiles);
	rendering(data);
}

void    rendering(t_data *data)
{
	player_placement(data);
    put_floor(data);
	put_object(data);
	print_map(data);
	data->tiles_old = data->tiles;
}