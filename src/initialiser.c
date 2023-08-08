/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialiser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:33:54 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/08/08 15:08:36 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_all(mlx_t	*mlx, t_txt *textures)
{
	t_data	*data;
	int		i;

	i = 0;
	data = get_data();
	data->mlx = mlx;
	data->key_found = 0;
	data->textures = textures;
	data->player_alive = 1;
	data->player_facing = 1;
	data->tiles = ft_calloc(1, sizeof(t_tile));
	if (!data->tiles)
		ft_error("allocation error");
	while (i < MAX_ZOMBIES)
	{
		data->zombie_facing[i] = -1;
		i++;
	}
	data->tiles_old = NULL;
	data->rdm_key = RANDOM_SEED;
	printf("Initialising DONE\n");
}

void	ult_free(t_data *data)
{
	un_render(data->mlx, data->tiles);
	un_render(data->mlx, data->tiles_old);
	ft_free(data->textures);
	ft_free(data->map_path);
	ft_free(data->tiles);
	ft_free(data->tiles_old);
	ft_free(data);
}
