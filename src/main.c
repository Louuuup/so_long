/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:10:53 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/06/29 14:13:05 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_data	*get_data(void)
{
	static t_data	*data;
	
	if (!data)
		data = ft_calloc(1, sizeof(t_data));

	return (data);
}

void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void my_keyhook(mlx_key_data_t keydata, void* param)
{
	
	mlx_image_t* img;
	img = param;
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		mv_right();
	else if (keydata.key == MLX_KEY_P && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		depth_hander();
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		mv_left();
	else if (keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		mv_up();
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		mv_down();
	else if (keydata.key == MLX_KEY_ESCAPE && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		exit(EXIT_SUCCESS);
}

int main(void)
{
	mlx_t *mlx;
	t_tile tiles;
	t_txt textures;

	mlx = mlx_init(WIDTH, HEIGHT, "Epic Game OMG ITS SO COOOL v0.04", true);
	if (!mlx)
		ft_error();
	init_all(mlx, &tiles, &textures);
	printf("init_all done\n");
	texture_handler(mlx, &textures, &tiles);
	printf("texture_handler done\n");
	parse_main(mlx, &tiles);
	printf("parse_main done\n");
    mlx_key_hook(mlx, my_keyhook, (void *)tiles.player);
	printf("mlx_key_hook done\n");
    mlx_loop(mlx);
	printf("mlx_loop done\n");
	mlx_terminate(mlx);
	mlx_delete_image(mlx, tiles.player);
	return (0);
}