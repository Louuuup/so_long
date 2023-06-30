/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:48:03 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/06/29 17:27:54 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft.h"
#include <fcntl.h>
#include <MLX42/MLX42.h>
#include <stdio.h>

//================Base Values================//
# define WIDTH 1920
# define HEIGHT 1080
# define TILE_SIZE 128
# define MAX_TILES_X 32
# define MAX_TILES_Y 32
//==================Files===================//
# define FILE_TEST "./textures/128px/floor0.png"
# define MAP "./maps/m_medium.ber"
//================Directions=================//
//					  0
//					3 + 1						
//        		      2
//==================Errors===================//

// 					=D


//==================Structs===================//
typedef struct textures
{
	mlx_texture_t	*test_cat;
	mlx_texture_t	*collectible;
	mlx_texture_t	*player_u;
	mlx_texture_t	*player_d;
	mlx_texture_t	*player_l;
	mlx_texture_t	*player_r;
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
	int			anchor_x;
	int			anchor_y;

}			t_tile;

typedef	struct	data
{
	size_t	height;
	size_t	length;
	t_tile	*tiles;
	t_txt	*textures;
	mlx_t	*mlx;
	int		start[2];
	char	line[MAX_TILES_Y][MAX_TILES_X]; //CAREFUL: Y then X 
}			t_data;

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
void	parse_main(mlx_t *mlx, t_tile *tiles);
int		put_tile(mlx_t *mlx, mlx_image_t *img, int x, int y);
t_data	*get_data(void); //Singleton
void    depth_hander(void);
void    mv_up(void);
void    mv_down(void);
void    mv_left(void);
void    mv_right(void);
void	init_all(mlx_t	*mlx, t_tile	*tiles, t_txt *textures);
int		parse_tiles(char c, mlx_image_t *tile);
int		iso_x(int x, int y, int anchor);
int		iso_y(int x, int y, int anchor);

#endif