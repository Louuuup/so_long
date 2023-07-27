/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:04:38 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/07/27 16:08:14 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void    key_animation(t_data *data, int frame)
{
    int	i;

    i = -1;
	if (frame > NB_KEY_TX)
		exit(ERROR);
	while (++i < NB_KEY_TX)
  		data->tiles->key[i]->enabled = false;
    data->tiles->key[frame]->enabled = true;
	data->key_count = char_count(KEY, data->map);
}

void	light_yagami(t_data *data)
{
	data->light = data->mv_count / 5 - data->key_found;
	if (data->light < 0)
		data->light = 0;
	if (data->light > NB_DARK_TX)
		data->light = NB_DARK_TX;
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


void	collect_key(t_data *data, int x, int y)
{
	data->map[y][x] = FLOOR;
	data->key_count--;
	data->key_found++;
}

void	ft_info_onscreen(mlx_t *mlx, int x, int y, char *info)
{
    mlx_put_string(mlx, info, x, y);
	ft_free((void *)info);
}