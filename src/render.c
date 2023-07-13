/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:37:31 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/07/13 14:26:31 by ycyr-roy         ###   ########.fr       */
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
		while (i < 6)
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
	printf("FT: player_placement()...\n");
	player_placement(data);
	printf("FT: put_floor()...\n");
    put_floor(data);
	printf("FT: put_object()...\n");
	put_object(data);
	print_map(data);
	data->tiles_old = data->tiles;
}