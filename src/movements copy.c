/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:08:31 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/06/20 14:16:08 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    mv_up(mlx_image_t *player)
{
    player->instances->x += 32;
    player->instances->y -= 16;
	printf("Char is now at (%d, %d)\n", player->instances->x, player->instances->y);
}

void    mv_down(mlx_image_t *player)
{
    player->instances->x -= 32;
    player->instances->y += 16;
	printf("Char is now at (%d, %d)\n", player->instances->x, player->instances->y);
    
}

void    mv_left(mlx_image_t *player)
{
    player->instances->x -= 32;
    player->instances->y -= 16;
	printf("Char is now at (%d, %d)\n", player->instances->x, player->instances->y);
}

void    mv_right(mlx_image_t *player)
{
    player->instances->x += 32;
    player->instances->y += 16;
	printf("Char is now at (%d, %d)\n", player->instances->x, player->instances->y);
}