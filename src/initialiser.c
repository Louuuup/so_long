/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialiser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:33:54 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/07/11 17:04:24 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_all(mlx_t	*mlx, t_txt *textures)
{ 
	t_data	*data;

	data = get_data();
	data->mlx = mlx;
	data->textures = textures;
	data->tiles = ft_calloc(1, sizeof(t_tile));
	if (!data->tiles)
	{
		printf("-----MALLOC ERROR-----\n");
		return ;
	}
	data->tiles_old = NULL;
	data->rdm_key = RANDOM_SEED;
	printf("Initialising DONE\n");
}
