/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialiser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:33:54 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/06/28 18:51:08 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_all(mlx_t	*mlx, t_tile	*tiles, t_txt *textures)
{
	t_data	*data;

	data = get_data();
	data->mlx = mlx;
	data->textures = textures;
	data->tiles = tiles;
}