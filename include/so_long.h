/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:48:03 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/06/15 21:22:11 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft.h"
#include <fcntl.h>
#include <MLX42/MLX42.h>
#include <stdio.h>

# define WIDTH 1920
# define HEIGHT 1080
# define TILE_SIZE 64
# define FILE_TEST "./textures/floor0.png"
# define MAP "./maps/m_medium.txt"

typedef struct textures
{
	mlx_texture_t	*test_cat;
	mlx_texture_t	*collectible;
	mlx_texture_t	*player;
	mlx_texture_t	*ennemy;
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*door;

}			t_txt;

typedef struct images
{
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*player;
	mlx_image_t	*collectible;
	mlx_image_t	*ennemy;
	mlx_image_t	*door;
	mlx_image_t	*test_cat;
	size_t		count_x;
	size_t		count_y;
	size_t		anchor;
	size_t		nxt_x; //double initialised
	size_t		nxt_y;

}			t_tile;

/**
 * NOTE: Looks in files to convert and transform .png textures into usable tiles. 
*@param[in] mlx			main mlx struct
*@param[in] textures 	strct of avaliable textures.
*@param[in] tiles		strct that stores all tiles.
*@return 				your mom
*/
void	texture_handler(mlx_t* mlx, t_txt* textures, t_tile* tiles);
/**
 * NOTE: Displays a tile to specific coordinates.
*@param[in] mlx main mlx struct
*@param[in] img image data for a specific tile
*@param[in] x	X position
*@param[in] y	Y position
*@return		your mom
*/
void	tile_display(mlx_t* mlx, mlx_image_t* img, int x, int y);
void	ft_error(void);
int		parse_main(mlx_t *mlx, t_tile *tiles);
void    tile_init(t_tile *tiles);

#endif