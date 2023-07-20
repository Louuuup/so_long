/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:10:53 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/07/20 14:43:40 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*get_data(void)
{
	static t_data	*data;
	
	if (!data)
		data = ft_calloc(1, sizeof(t_data));

	return (data);
}

void ft_error(void)
{
	perror("ERROR:");
	exit(EXIT_FAILURE);
}

void ft_error_mlx(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void my_keyhook(mlx_key_data_t keydata, void* param)
{	
	(void)param;
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT) && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		mv_right();
	else if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT) && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		mv_left();
	else if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP) && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		mv_up();
	else if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN) && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		mv_down();
	else if (keydata.key == MLX_KEY_ESCAPE && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		exit(EXIT_SUCCESS);
	else if (keydata.key == MLX_KEY_DELETE && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
    	ft_die();
	else if (keydata.key == MLX_KEY_ENTER && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT) && !get_data()->player_alive)
		menu_press();
}
int main(void)
{
	mlx_t *mlx;
	t_txt textures;

	mlx = mlx_init(WIDTH, HEIGHT, "Epic Game OMG ITS SO COOOL v0.04", true);
	if (!mlx)
		ft_error();
	printf("Initialising...\n");
	init_all(mlx, &textures);
	printf("Texture Handling...\n");
	texture_handler(mlx, &textures, get_data()->tiles);
	printf("Parsing...\n");
	parse_main(mlx, get_data()->tiles);
	if (!map_legal(get_data(), get_data()->map))
	{
	printf("Launching Keyhook...\n");
	
    mlx_key_hook(mlx, my_keyhook, (void *)get_data()->tiles->player);
	printf("Launching Loop...\n");
    mlx_loop(mlx);
	mlx_terminate(mlx);	
	}
	return (0);
}
