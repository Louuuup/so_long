/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:14:47 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/06/15 19:12:18 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"



static void texture_grab(t_txt* textures)
{
    textures->floor = mlx_load_png(FILE_TEST);
    if (!textures->floor)
        ft_error();
    textures->wall = mlx_load_png("./textures/test.png");
    if (!textures->wall)
        ft_error();
    textures->door = mlx_load_png(FILE_TEST);
    if (!textures->door)
        ft_error();
    textures->ennemy = mlx_load_png(FILE_TEST);
    if (!textures->ennemy)
        ft_error();
    textures->collectible = mlx_load_png(FILE_TEST);
    if (!textures->collectible)
        ft_error();
    textures->player = mlx_load_png(FILE_TEST);
    if (!textures->player)
        ft_error();
}

static void texture_convert(mlx_t* mlx, t_txt* textures, t_tile* tiles)
{
    tiles->floor = mlx_texture_to_image(mlx, textures->floor);
    tiles->wall = mlx_texture_to_image(mlx, textures->wall);
    tiles->door = mlx_texture_to_image(mlx, textures->door);
    tiles->collectible = mlx_texture_to_image(mlx, textures->collectible);
    tiles->ennemy = mlx_texture_to_image(mlx, textures->ennemy);
    tiles->player = mlx_texture_to_image(mlx, textures->player);

}
// Unused for now
void tile_display(mlx_t* mlx, mlx_image_t* img, int x, int y)
{
    if (mlx_image_to_window(mlx, img, x, y))
        ft_error();
}

void texture_handler(mlx_t* mlx, t_txt* textures, t_tile* tiles)
{
   texture_grab(textures);
   texture_convert(mlx, textures, tiles);
}
