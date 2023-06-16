/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialiser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:33:54 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/06/15 18:27:46 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    tile_init(t_tile *tiles)
{
	tiles->count_x = 0;
	tiles->count_y = 0;
	tiles->nxt_x = 0;
	tiles->nxt_y = 0;
}