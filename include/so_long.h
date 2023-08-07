/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:48:03 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/08/07 15:49:54 by ycyr-roy         ###   ########.fr       */
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
# define RANDOM_SEED 915
# define MAX_ZOMBIES 5
//==================TILES=================//
# define ZOMBIE 'Z'
# define PLAYER 'P'
# define WALL '1'
# define FLOOR '0'
# define KEY 'C'
# define PORTAL 'E'
//=================KEYWORDS==================//
# define NO 0
# define YES 1
//==============TEXTURES_COUNT===============//
# define NB_WALL_TX 25
# define NB_FLOOR_TX 8
# define NB_ZOMBIE_TX 4
# define NB_PLAYER_TX 4
# define NB_KEY_TX 8
# define NB_PORTAL_TX 9
# define NB_DARK_TX 15
//================Directions=================//
enum e_dir
{
	UP = 0,
	RIGHT = 1,
	DOWN = 2,
	LEFT = 3
};

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
	mlx_texture_t	*player[4];
	mlx_texture_t	*zombie[4];
	mlx_texture_t	*floor[8];
	mlx_texture_t	*wall[25];
	mlx_texture_t	*key[8];
	mlx_texture_t	*portal[9];
	mlx_texture_t	*portal_off;
	mlx_texture_t	*dark[15];
	mlx_texture_t	*death_screen[2];
	mlx_texture_t	*win_screen[2];
	

}			t_txt;

typedef struct images
{
	mlx_image_t	*player;
	mlx_image_t	*zombie[4];
	mlx_image_t	*floor[8];
	mlx_image_t	*portal[9];
	mlx_image_t	*portal_off;
	mlx_image_t	*wall[25];
	mlx_image_t	*key[8];
	mlx_image_t	*dark;
	mlx_image_t	*death_screen[2];
	mlx_image_t	*win_screen[2];

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
	char				base_map[MAX_TILES_Y][MAX_TILES_X]; //CAREFUL: Y then X 
	char				map[MAX_TILES_Y][MAX_TILES_X]; //CAREFUL: Y then X 
	int					distance_map[MAX_TILES_Y][MAX_TILES_X]; //CAREFUL: Y then X 
	int					player_base_depth;
	int					player_facing;
	int					zombie_facing[MAX_ZOMBIES]; //-1 if dosent exist.
	int					zombie_count;
	int					key_count;
	int					key_found;
	int					player_alive; //1 = alive || 0 = dead.
	int					win;        // = win || 0 = no win
	int				 	light; //0 = brightest || 15 = almost no light
	unsigned long long	rdm_key;
	unsigned int		mv_count;
	char 				*map_path;
	
}			t_data;
////TO FREE IN ALL CASES AT END OR EXIT :
// 

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
void	ft_error(char *str);
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
void    print_altmap(t_data *data);
void	put_floor(t_data	*data);
int		ft_rand(int range, int x, int y);
void	*ft_free(void *ptr);
void    map_read(int fd, t_data *data, int x, int y);
void	texture_convert(mlx_t* mlx, t_txt* textures, t_tile* tiles);
void	re_render(t_data *data);
void	put_object(t_data	*data);
void	ft_error_mlx(void);
int		map_legal(t_data *data, char map[][MAX_TILES_X]);
void    world_events(t_data *data);
/**
 * NOTE: Fills data.distance with distance of player + 1
*@param[in] data		t_data
*@param[in] x 			X position
*@param[in] y 			Y position
*@param[in] distance 	for recursive purposes. 1 by default
*@return		your mom
*/
void 	flood_fill(t_data *data, int x, int y, int distance);
t_co	where_is(int skip, char c, char map[][MAX_TILES_X]);
int		char_count(char c, char arr[][MAX_TILES_X]);
void    print_flood(t_data *data); // TMP
void    flood_clean(t_data *data);
void    ft_die(void);
void    menu_up(t_data *data);
void    menu_down(t_data *data);
void    menu_press(void);
void	collect_key(t_data *data, int x, int y);
void	ft_info_onscreen(mlx_t *mlx, int x, int y, char *info);
void	key_loop(t_data *data, int sec);
void	portal_loop(t_data *data, int sec);
char 	*rm_nl(char *str);
void    ft_win();
/**
 * NOTE: Moves player or zombie in specified direction, and cleans tile left behind.
*@param[in] src		t_data
*@param[in] x_m 	X modificator (if entity moving on x axis) 0 if none
*@param[in] y_m 	Y modificator (if entity moving on y axis) 0 if none
*@param[in] data 	t_data
*@return		your mom
*/
void	ft_move(t_co src, int x_m, int y_m, t_data *data);
/**
 * NOTE: Removes entities(zombie or players) from base_map. 
*@param[in] data 	t_data
*@return		your mom
*/
void	base_map_clean(t_data *data);


#endif