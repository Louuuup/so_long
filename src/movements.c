/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:08:31 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/06/29 17:20:57 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    mv_up(void)
{
    size_t  i;
    t_tile *tiles;
    tiles = get_data()->tiles;
    i = 0;
    while (tiles->floor->instances[i].enabled)
    {
        tiles->floor->instances[i].x -= TILE_SIZE / 2;
        tiles->wall->instances[i].x -= TILE_SIZE / 2;
        tiles->wall->instances[i].y += TILE_SIZE / 4;
        tiles->floor->instances[i].y += TILE_SIZE / 4;
        tiles->player->instances->z -= get_data()->length;
        i++;
    }
}

void    mv_down(void)
{
    size_t  i;
    t_tile *tiles;
    tiles = get_data()->tiles;
    i = 0;
    while (tiles->floor->instances[i].enabled)
    {
        tiles->floor->instances[i].x += TILE_SIZE / 2;
        tiles->wall->instances[i].x += TILE_SIZE / 2;
        tiles->wall->instances[i].y -= TILE_SIZE / 4;
        tiles->floor->instances[i].y -= TILE_SIZE / 4;
        tiles->player->instances->z += get_data()->length;
        i++;
    }
}

void    mv_left(void)
{
    size_t  i;
    t_tile *tiles;
    tiles = get_data()->tiles;
    i = 0;
    while (tiles->floor->instances[i].enabled)
    {
        tiles->floor->instances[i].x += TILE_SIZE / 2;
        tiles->wall->instances[i].x += TILE_SIZE / 2;
        tiles->wall->instances[i].y += TILE_SIZE / 4;
        tiles->floor->instances[i].y += TILE_SIZE / 4;
        tiles->player->instances->z++;
        i++;
    }
}

void    mv_right(void)
{
    size_t  i;
    t_tile *tiles;
    tiles = get_data()->tiles;
    i = 0;
    while (tiles->floor->instances[i].enabled)
    {
        tiles->floor->instances[i].x -= TILE_SIZE / 2;
        tiles->wall->instances[i].x -= TILE_SIZE / 2;
        tiles->wall->instances[i].y -= TILE_SIZE / 4;
        tiles->floor->instances[i].y -= TILE_SIZE / 4;
        tiles->player->instances->z++;
        i++;
    }
}