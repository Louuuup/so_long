/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialiser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:33:54 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/07/20 14:58:29 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_all(mlx_t	*mlx, t_txt *textures)
{ 
	t_data	*data;
	int i;

	i = 0;
	data = get_data();
	data->mlx = mlx;
	data->textures = textures;
	data->player_alive = 1;
    data->player_facing = 1;
	data->tiles = ft_calloc(1, sizeof(t_tile));
	if (!data->tiles)
	{
		printf("-----MALLOC ERROR-----\n");
		return ;
	}
	while (i < MAX_ZOMBIES)
	{
		data->zombie_facing[i] = -1;
		i++;
	}
	data->tiles_old = NULL;
	data->rdm_key = RANDOM_SEED;
	printf("Initialising DONE\n");
}
