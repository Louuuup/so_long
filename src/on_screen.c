/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:04:38 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/07/25 16:41:08 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    key_animation(t_data *data, int frame)
{
    int	i;

    i = -1;
	if (frame > 8)
		exit(ERROR);
	while (++i < 8)
  		data->tiles->key[i]->enabled = false;
    data->tiles->key[frame]->enabled = true;
	data->key_count = char_count(KEY, data->map);
}

void	collect_key(t_data *data, int x, int y)
{
	data->map[y][x] = FLOOR;
	data->key_count--;
}

void	ft_info_onscreen(mlx_t *mlx, int x, int y, char *info)
{
    mlx_put_string(mlx, info, x, y);
	ft_free((void *)info);
}