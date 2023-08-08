/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:04:38 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/08/08 15:08:05 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_info_onscreen(mlx_t *mlx, int x, int y, char *info)
{
	mlx_put_string(mlx, info, x, y);
	ft_free((void *)info);
}

void	light_yagami(t_data *data)
{
	data->light = data->mv_count / 1 - data->key_found;
	if (data->light < 0)
		data->light = 0;
	if (data->light > NB_DARK_TX)
		data->light = NB_DARK_TX;
}

void	collect_key(t_data *data, int x, int y)
{
	data->map[y][x] = FLOOR;
	data->base_map[y][x] = FLOOR;
	data->key_found++;
}

void	put_info(t_data *data)
{
	char	*ptr;

	ptr = NULL;
	ptr = ft_itoa(data->player.x);
	ft_info_onscreen(data->mlx, 5, 15, ft_strjoin("X: ", ptr));
	ft_free(ptr);
	ptr = ft_itoa(data->player.y);
	ft_info_onscreen(data->mlx, 5, 30, ft_strjoin("Y: ", ptr));
	ft_free(ptr);
	ptr = ft_itoa(data->mv_count);
	ft_info_onscreen(data->mlx, 5, 45, ft_strjoin("MOVES: ", ptr));
	ft_free(ptr);
	ptr = ft_itoa(data->key_found);
	ft_info_onscreen(data->mlx, 5, 60, ft_strjoin("KEYS FOUND: ", ptr));
	ft_free(ptr);
	ptr = ft_itoa(data->key_count);
	ft_info_onscreen(data->mlx, 135, 60, ft_strjoin("/", ptr));
	ft_free(ptr);
}
