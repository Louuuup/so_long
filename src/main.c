/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:10:53 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/06/15 21:02:12 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int main(void)
{
	mlx_t *mlx;
	t_tile tiles;
	t_txt textures;
	
	mlx = mlx_init(WIDTH, HEIGHT, "Epic Game OMG ITS SO COOOL v0.03", true);
	if (!mlx)
		ft_error();
	tile_init(&tiles);
	texture_handler(mlx, &textures, &tiles);
	parse_main(mlx, &tiles);
    mlx_loop(mlx);
	mlx_terminate(mlx);
}