/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:10:53 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/08/04 13:24:33 by ycyr-roy         ###   ########.fr       */
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

static void args_handler(t_data *data, int argc, char **argv)
{
	if (argc < 2)
		ft_error("Need to specify map.\n(maps/FILE_NAME)");
	else if (argc > 2)
		ft_error("Bro. Only one map at the time.\n(maps/FILE_NAME)");
	data->map_path = argv[1];
	
}
static void mv_keyhook(mlx_key_data_t keydata, void* param)
{	
	t_data *data;
	
	data = param;
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
	else if (keydata.key == MLX_KEY_ENTER && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT) && (!data->player_alive || get_data()->win))
		menu_press();
}

static void event_hook(void* param)
{
	t_data *data;
	
	data = param;
	int sec;

	sec = (int)mlx_get_time();
	key_loop(data, sec);
	if (data->key_count == data->key_found)
		portal_loop(data, sec);
}
int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	mlx_t *mlx;
	t_txt textures;
	t_data *data;
	data = get_data();
	
	mlx = mlx_init(WIDTH, HEIGHT, "Epic Game OMG ITS SO COOOL v0.04", true);
	if (!mlx)
		ft_error_mlx();
	init_all(mlx, &textures);
	args_handler(data, argc, argv);
	texture_handler(mlx, &textures, data->tiles);
	parse_main(mlx, data->tiles);
	map_legal(data, data->map);
    mlx_key_hook(mlx, mv_keyhook, (void *)data);
	mlx_loop_hook(mlx, event_hook, (void *)data);
  	mlx_loop(mlx);
	mlx_terminate(mlx);	
	return (EXIT_SUCCESS);
}
