/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:14:47 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/07/11 13:21:58 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"



static void texture_grab(t_txt* textures)
{
    textures->floor[0] = mlx_load_png("./textures/floor0.png");
    textures->floor[1] = mlx_load_png("./textures/floor1.png");
    textures->floor[2] = mlx_load_png("./textures/floor2.png");
    textures->floor[3] = mlx_load_png("./textures/floor3.png");
    textures->floor[4] = mlx_load_png("./textures/floor4.png");
    textures->floor[5] = mlx_load_png("./textures/floor5.png");
    textures->floor[6] = mlx_load_png("./textures/floor6.png");
    textures->floor[7] = mlx_load_png("./textures/floor7.png");
    textures->wall = mlx_load_png("./textures/wall0.png");
    // textures->door = mlx_load_png(FILE_TEST);
    // textures->ennemy = mlx_load_png(FILE_TEST);
    // textures->collectible = mlx_load_png(FILE_TEST);
    textures->player[0] = mlx_load_png("./textures/player_u.png");
    textures->player[1] = mlx_load_png("./textures/player_r.png");
    textures->player[2] = mlx_load_png("./textures/player_d.png");
    textures->player[3] = mlx_load_png("./textures/player_l.png");
    if (!textures->floor[0] || !textures->floor[1] || !textures->floor[2] || !textures->floor[3]
        || !textures->floor[4] || !textures->floor[5] || !textures->floor[6] || !textures->floor[7]
        || !textures->wall || !textures->player[0] || !textures->player[1] || !textures->player[2]
        || !textures->player[3])
        ft_error();
}

void texture_convert(mlx_t* mlx, t_txt* textures, t_tile* tiles)
{
    tiles->floor[0] = mlx_texture_to_image(mlx, textures->floor[0]);
    tiles->floor[1] = mlx_texture_to_image(mlx, textures->floor[1]);
    tiles->floor[2] = mlx_texture_to_image(mlx, textures->floor[2]);
    tiles->floor[3] = mlx_texture_to_image(mlx, textures->floor[0]);
    tiles->floor[4] = mlx_texture_to_image(mlx, textures->floor[4]);
    tiles->floor[5] = mlx_texture_to_image(mlx, textures->floor[5]);
    tiles->floor[6] = mlx_texture_to_image(mlx, textures->floor[6]);
    tiles->floor[7] = mlx_texture_to_image(mlx, textures->floor[7]);
    tiles->wall = mlx_texture_to_image(mlx, textures->wall);
    tiles->player[0] = mlx_texture_to_image(mlx, textures->player[0]);
    tiles->player[1] = mlx_texture_to_image(mlx, textures->player[1]);
    tiles->player[2] = mlx_texture_to_image(mlx, textures->player[2]);
    tiles->player[3] = mlx_texture_to_image(mlx, textures->player[3]);

}

void texture_handler(mlx_t* mlx, t_txt* textures, t_tile* tiles)
{
    texture_grab(textures);
    texture_convert(mlx, textures, tiles);
    printf("Texture Handling DONE\n");

}
