/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:33:57 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/06/12 15:33:28 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42/MLX42.h>
#include "libft.h"
#include "so_long.h"
#include <stdio.h>
#include <string.h>

static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void my_keyhook(mlx_key_data_t keydata, void* param)
{
	
	mlx_image_t* img;
	
	img = param;
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		puts("Right");
		img->instances[0].x += 32;
	}
	// If we RELEASE the 'K' key, print "World".
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		puts("Left");
		img->instances[0].x -= 32;
	}
	else if (keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		puts("Up");
		img->instances[0].y -= 32;
	}
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		puts("Down");
		img->instances[0].y += 32;
	}
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		return ;
}


// static void ft_hook(void* param)
// {
// 	const mlx_t* mlx = param;
// 	mlx_key_data_t keydata;
// 	keydata.action = 0;

// 	my_keyhook(keydata, param);
// 	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
// }

int main(void)
{
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
	if (!mlx)
		ft_error();
	mlx_texture_t* tx_cat = mlx_load_png("../so_long_sources/kitty.png");
	if (!tx_cat)
        ft_error();
	mlx_image_t* img = mlx_texture_to_image(mlx, tx_cat);
	if (!img)
        ft_error();	
	// mlx_image_t* img = mlx_new_image(mlx, 32, 32);
	// if (!img)
	// 	ft_error();
	// memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));
  	if (mlx_image_to_window(mlx, img, 32, 32) < 0)
        ft_error();
    mlx_key_hook(mlx, my_keyhook, (void *)img);
    // mlx_loop_hook(mlx, ft_hook, mlx);
    mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
