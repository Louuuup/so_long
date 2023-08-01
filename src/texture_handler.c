/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2523/06/14 14:14:47 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/08/01 15:46:56 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static mlx_texture_t *texture_inject(mlx_texture_t *texture, void *ptr)
{
	// printf("Loading %s...\n", ptr);
	texture = mlx_load_png(ptr);
    ft_free(ptr);
	if (!texture)
		ft_error_mlx();
	return (texture);
}

static void texture_grab(t_txt *textures)
{
    int     i;
    int	    fd;
    
    i = -1;
	fd = open("./textures/paths.txt", O_RDONLY);
	if (fd < 0)
		exit (ERROR);
    while (++i < NB_FLOOR_TX)
        textures->floor[i] = texture_inject(textures->floor[i], rm_nl(get_next_line(fd)));
    i = -1;
    while (++i < NB_WALL_TX)
        textures->wall[i] = texture_inject(textures->wall[i], rm_nl(get_next_line(fd)));
    i = -1;
    while (++i < NB_DARK_TX)
        textures->dark[i] = texture_inject(textures->dark[i], rm_nl(get_next_line(fd)));
    i = -1;
    while (++i < 2)
        textures->death_screen[i] = texture_inject(textures->death_screen[i], rm_nl(get_next_line(fd)));
    i = -1;
    while (++i < 2)
        textures->win_screen[i] = texture_inject(textures->win_screen[i], rm_nl(get_next_line(fd)));
    i = -1;
    while (++i < NB_KEY_TX)
        textures->key[i] = texture_inject(textures->key[i], rm_nl(get_next_line(fd)));
    i = -1;
    while (++i < NB_PORTAL_TX)
        textures->portal[i] = texture_inject(textures->portal[i], rm_nl(get_next_line(fd)));
    i = -1;
    while (++i < NB_PLAYER_TX)
        textures->player[i] = texture_inject(textures->player[i], rm_nl(get_next_line(fd)));
    i = -1;
    while (++i < NB_ZOMBIE_TX)
        textures->zombie[i] = texture_inject(textures->zombie[i], rm_nl(get_next_line(fd)));
}

void texture_convert(mlx_t* mlx, t_txt* textures, t_tile* tiles)
{
    int i;

    i = -1;
    while (++i < NB_FLOOR_TX)
        tiles->floor[i] = mlx_texture_to_image(mlx, textures->floor[i]);
    i = -1;
    while (++i < NB_WALL_TX)
        tiles->wall[i] = mlx_texture_to_image(mlx, textures->wall[i]);
    i = -1;
    tiles->player = mlx_texture_to_image(mlx, textures->player[get_data()->player_facing]);
    while (++i < NB_ZOMBIE_TX)
        tiles->zombie[i] = mlx_texture_to_image(mlx, textures->zombie[i]);
    i = -1;
    while (++i < NB_KEY_TX)
        tiles->key[i] = mlx_texture_to_image(mlx, textures->key[i]);
    i = -1;
    while (++i < NB_PORTAL_TX)
        tiles->portal[i] = mlx_texture_to_image(mlx, textures->portal[i]);
    tiles->dark = mlx_texture_to_image(mlx, textures->dark[get_data()->light]);
    tiles->death_screen[0] = mlx_texture_to_image(mlx, textures->death_screen[0]);
    tiles->death_screen[1] = mlx_texture_to_image(mlx, textures->death_screen[1]);
    tiles->win_screen[0] = mlx_texture_to_image(mlx, textures->win_screen[0]);
    tiles->win_screen[1] = mlx_texture_to_image(mlx, textures->win_screen[1]);
    tiles->death_screen[1]->enabled = false;
    tiles->win_screen[1]->enabled = false;
    
}

void texture_handler(mlx_t* mlx, t_txt* textures, t_tile* tiles)
{
    texture_grab(textures);
    texture_convert(mlx, textures, tiles);

}
