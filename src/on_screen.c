/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:04:38 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/07/28 16:35:17 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	light_yagami(t_data *data)
{
	data->light = data->mv_count / 5 - data->key_found;
	if (data->light < 0)
		data->light = 0;
	if (data->light > NB_DARK_TX)
		data->light = NB_DARK_TX;
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