/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:34:51 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/08/11 14:42:57 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	key_animation(t_data *data, int frame)
{
	int	i;

	i = -1;
	if (frame > NB_KEY_TX)
		exit(ERROR);
	while (++i < NB_KEY_TX)
		data->tiles->key[i]->enabled = false;
	data->tiles->key[frame]->enabled = true;
}

static void	portal_animation(t_data *data, int frame)
{
	int	i;

	i = -1;
	if (frame > NB_PORTAL_TX)
		exit(ERROR);
	while (++i < NB_PORTAL_TX)
		data->tiles->portal[i]->enabled = false;
	data->tiles->portal[frame]->enabled = true;
}

void	key_loop(t_data *data, int sec)
{
	if (mlx_get_time() <= (double)sec + 0.125)
		key_animation(data, 0);
	else if (mlx_get_time() <= (double)sec + 0.25)
		key_animation(data, 1);
	else if (mlx_get_time() <= (double)sec + 0.375)
		key_animation(data, 2);
	else if (mlx_get_time() <= (double)sec + 0.5)
		key_animation(data, 3);
	else if (mlx_get_time() <= (double)sec + 0.625)
		key_animation(data, 4);
	else if (mlx_get_time() <= (double)sec + 0.75)
		key_animation(data, 5);
	else if (mlx_get_time() <= (double)sec + 0.875)
		key_animation(data, 6);
	else
		key_animation(data, 7);
}

void	portal_loop(t_data *data, int sec)
{
	if (mlx_get_time() <= (double)sec + 0.111)
		portal_animation(data, 0);
	else if (mlx_get_time() <= (double)sec + 0.222)
		portal_animation(data, 1);
	else if (mlx_get_time() <= (double)sec + 0.333)
		portal_animation(data, 2);
	else if (mlx_get_time() <= (double)sec + 0.444)
		portal_animation(data, 3);
	else if (mlx_get_time() <= (double)sec + 0.555)
		portal_animation(data, 4);
	else if (mlx_get_time() <= (double)sec + 0.667)
		portal_animation(data, 5);
	else if (mlx_get_time() <= (double)sec + 0.778)
		portal_animation(data, 6);
	else if (mlx_get_time() <= (double)sec + 0.889)
		portal_animation(data, 7);
	else
		portal_animation(data, 8);
}
