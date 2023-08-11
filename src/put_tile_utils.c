/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_tile_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:22:03 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/08/11 14:59:55 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	iso_x(int x, int y, int anchor)
{
	int	x_out;

	x_out = (x * 0.5 * TILE_SIZE) + (y * -0.5 \
	* TILE_SIZE) - (TILE_SIZE / 2) + anchor;
	return (x_out);
}

int	iso_y(int x, int y, int anchor)
{
	int	y_out;

	y_out = (x * 0.25 * TILE_SIZE) + (y * 0.25 \
	* TILE_SIZE) + (TILE_SIZE / 2) + anchor;
	return (y_out);
}
