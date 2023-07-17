/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2523/06/14 14:14:47 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/07/17 13:59:43 by ycyr-roy         ###   ########.fr       */
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
    textures->wall[0] = mlx_load_png("./textures/wall0.png");
    textures->wall[1] = mlx_load_png("./textures/wall1.png");
    textures->wall[2] = mlx_load_png("./textures/wall2.png");
    textures->wall[3] = mlx_load_png("./textures/wall3.png");
    textures->wall[4] = mlx_load_png("./textures/wall4.png");
    textures->wall[5] = mlx_load_png("./textures/wall5.png");
    textures->wall[6] = mlx_load_png("./textures/wall6.png");
    textures->wall[7] = mlx_load_png("./textures/wall7.png");
    textures->wall[8] = mlx_load_png("./textures/wall8.png");
    textures->wall[9] = mlx_load_png("./textures/wall9.png");
    textures->wall[10] = mlx_load_png("./textures/wall10.png");
    textures->wall[11] = mlx_load_png("./textures/wall11.png");
    textures->wall[12] = mlx_load_png("./textures/wall12.png");
    textures->wall[13] = mlx_load_png("./textures/wall13.png");
    textures->wall[14] = mlx_load_png("./textures/wall14.png");
    textures->wall[15] = mlx_load_png("./textures/wall15.png");
    textures->wall[16] = mlx_load_png("./textures/wall16.png");
    textures->wall[17] = mlx_load_png("./textures/wall17.png");
    textures->wall[18] = mlx_load_png("./textures/wall18.png");
    textures->wall[19] = mlx_load_png("./textures/wall19.png");
    textures->wall[20] = mlx_load_png("./textures/wall20.png");
    textures->wall[21] = mlx_load_png("./textures/wall21.png");
    textures->wall[22] = mlx_load_png("./textures/wall22.png");
    textures->wall[23] = mlx_load_png("./textures/wall23.png");
    textures->wall[24] = mlx_load_png("./textures/wall24.png");
    textures->dark = mlx_load_png("./textures/dark.png");
    // textures->door = mlx_load_png(FILE_TEST);
    // textures->ennemy = mlx_load_png(FILE_TEST);
    // textures->collectible = mlx_load_png(FILE_TEST);
    textures->player[0] = mlx_load_png("./textures/player_u.png");
    textures->player[1] = mlx_load_png("./textures/player_r.png");
    textures->player[2] = mlx_load_png("./textures/player_d.png");
    textures->player[3] = mlx_load_png("./textures/player_l.png");
    textures->zombie[0] = mlx_load_png("./textures/zombie_u.png");
    textures->zombie[1] = mlx_load_png("./textures/zombie_r.png");
    textures->zombie[2] = mlx_load_png("./textures/zombie_d.png");
    textures->zombie[3] = mlx_load_png("./textures/zombie_l.png");
    
    if (!textures->floor[0] || !textures->floor[1] || !textures->floor[2] || !textures->floor[3]
        || !textures->floor[4] || !textures->floor[5] || !textures->floor[6] || !textures->floor[7]
        || !textures->wall[0] || !textures->wall[1] || !textures->wall[2] || !textures->wall[3]
        || !textures->wall[4] || !textures->wall[5] || !textures->player[0] || !textures->player[1]
        || !textures->player[2] || !textures->player[3] || !textures->dark)
        ft_error_mlx();
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
    tiles->wall[0] = mlx_texture_to_image(mlx, textures->wall[0]);
    tiles->wall[1] = mlx_texture_to_image(mlx, textures->wall[1]);
    tiles->wall[2] = mlx_texture_to_image(mlx, textures->wall[2]);
    tiles->wall[3] = mlx_texture_to_image(mlx, textures->wall[3]);
    tiles->wall[4] = mlx_texture_to_image(mlx, textures->wall[4]);
    tiles->wall[5] = mlx_texture_to_image(mlx, textures->wall[5]);
    tiles->wall[6] = mlx_texture_to_image(mlx, textures->wall[6]);
    tiles->wall[7] = mlx_texture_to_image(mlx, textures->wall[7]);
    tiles->wall[8] = mlx_texture_to_image(mlx, textures->wall[8]);
    tiles->wall[9] = mlx_texture_to_image(mlx, textures->wall[9]);
    tiles->wall[10] = mlx_texture_to_image(mlx, textures->wall[10]);
    tiles->wall[11] = mlx_texture_to_image(mlx, textures->wall[11]);
    tiles->wall[12] = mlx_texture_to_image(mlx, textures->wall[12]);
    tiles->wall[13] = mlx_texture_to_image(mlx, textures->wall[13]);
    tiles->wall[14] = mlx_texture_to_image(mlx, textures->wall[14]);
    tiles->wall[15] = mlx_texture_to_image(mlx, textures->wall[15]);
    tiles->wall[16] = mlx_texture_to_image(mlx, textures->wall[16]);
    tiles->wall[17] = mlx_texture_to_image(mlx, textures->wall[17]);
    tiles->wall[18] = mlx_texture_to_image(mlx, textures->wall[18]);
    tiles->wall[19] = mlx_texture_to_image(mlx, textures->wall[19]);
    tiles->wall[20] = mlx_texture_to_image(mlx, textures->wall[20]);
    tiles->wall[21] = mlx_texture_to_image(mlx, textures->wall[21]);
    tiles->wall[22] = mlx_texture_to_image(mlx, textures->wall[22]);
    tiles->wall[23] = mlx_texture_to_image(mlx, textures->wall[23]);
    tiles->wall[24] = mlx_texture_to_image(mlx, textures->wall[24]);
    tiles->player = mlx_texture_to_image(mlx, textures->player[get_data()->player_facing]);
    tiles->zombie[0] = mlx_texture_to_image(mlx, textures->zombie[0]);
    tiles->zombie[1] = mlx_texture_to_image(mlx, textures->zombie[1]);
    tiles->zombie[2] = mlx_texture_to_image(mlx, textures->zombie[2]);
    tiles->zombie[3] = mlx_texture_to_image(mlx, textures->zombie[3]);
    tiles->dark = mlx_texture_to_image(mlx, textures->dark);
}

void texture_handler(mlx_t* mlx, t_txt* textures, t_tile* tiles)
{
    texture_grab(textures);
    texture_convert(mlx, textures, tiles);
    printf("Texture Handling DONE\n");

}
