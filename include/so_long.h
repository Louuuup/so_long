/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:48:03 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/07/13 14:10:37 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft.h"
#include <fcntl.h>
#include <MLX42/MLX42.h>
#include <stdio.h>
#include "string.h"

//================Base Values================//
# define WIDTH 1920
# define HEIGHT 1080
# define TILE_SIZE 128
# define MAX_TILES_X 64
# define MAX_TILES_Y 64
# define MAX_RANGE 16
# define READ_BUFFER 256
# define RANDOM_SEED 916
//==================Aliases=================//

//==================Files===================//
# define FILE_TEST "./textures/128px/floor0.png"
# define MAP "./maps/labyrinth.ber"
//================Directions=================//
//					  0
//					3 + 1						
//        		      2

// '0' is 'U'
// '1' is 'R'
// '2' is 'D'
// '3' is 'L'
//==================Errors===================//

// 					=D


//==================Structs===================//

typedef	struct	coords
{
	int	x;
	int y;
}			t_co;

typedef struct textures
{
	mlx_texture_t	*test_cat;
	mlx_texture_t	*collectible;
	mlx_texture_t	*player[4];
	mlx_texture_t	*ennemy;
	mlx_texture_t	*floor[8];
	mlx_texture_t	*wall[6];
	mlx_texture_t	*door;

}			t_txt;

typedef struct images
{
	mlx_image_t	*floor[8];
	mlx_image_t	*wall[6];
	mlx_image_t	*player;
	mlx_image_t	*collectible;
	mlx_image_t	*ennemy;
	mlx_image_t	*door;
	mlx_image_t	*test_cat;

}			t_tile;

typedef	struct	data
{
	size_t				height;
	size_t				length;
	t_tile				*tiles_old;
	t_tile				*tiles;
	t_txt				*textures;
	mlx_t				*mlx;
	t_co				start;
	t_co				player;
	t_co				anchor;
	char				map[MAX_TILES_Y][MAX_TILES_X]; //CAREFUL: Y then X 
	int					player_base_depth;
	int					player_facing;
	unsigned long long	rdm_key;
	
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
void	put_tile(mlx_t *mlx, mlx_image_t *img, int x, int y);
t_data	*get_data(void); //Singleton
void    mv_up(void);
void    mv_down(void);
void    mv_left(void);
void    mv_right(void);
void	init_all(mlx_t	*mlx, t_txt *textures);
int		parse_tiles(char c, mlx_image_t *tile);
int		iso_x(int x, int y, int anchor);
int		iso_y(int x, int y, int anchor);
void	ft_swap(char *a, char *b);
void    rendering(t_data *data);
void	player_placement(t_data *data);
void    un_render(mlx_t *mlx, t_tile *tiles);
void    print_map(t_data *data);
void	put_floor(t_data	*data);
int		ft_rand(int range, int x, int y);
void	ft_free(void **ptr);
void    map_read(int fd, t_data *data);
void	texture_convert(mlx_t* mlx, t_txt* textures, t_tile* tiles);
void	re_render(t_data *data);
void	put_object(t_data	*data);
void	ft_error_mlx(void);
int		char_count(char x, char arr[][MAX_TILES_X]);
int		map_legal(t_data *data, char map[][MAX_TILES_X]);

#endif