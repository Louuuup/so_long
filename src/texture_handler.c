/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2523/06/14 14:14:47 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/08/15 11:46:40 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	texture_grab_utils(t_txt *textures, int fd)
{
	int	i;

	i = -1;
	while (++i < 2)
		textures->win_screen[i] = texture_inject(textures->win_screen[i], \
			rm_nl(get_next_line(fd)));
	i = -1;
	while (++i < NB_KEY_TX)
		textures->key[i] = texture_inject(textures->key[i], \
			rm_nl(get_next_line(fd)));
	i = -1;
	while (++i < NB_PORTAL_TX)
		textures->portal[i] = texture_inject(textures->portal[i], \
			rm_nl(get_next_line(fd)));
	textures->portal_off = texture_inject(textures->portal_off, \
		rm_nl(get_next_line(fd)));
	i = -1;
	while (++i < NB_PLAYER_TX)
		textures->player[i] = texture_inject(textures->player[i], \
			rm_nl(get_next_line(fd)));
	i = -1;
	while (++i < NB_ZOMBIE_TX)
		textures->zombie[i] = texture_inject(textures->zombie[i], \
			rm_nl(get_next_line(fd)));
}

static void	texture_grab(t_txt *textures)
{
	int	i;
	int	fd;

	i = -1;
	fd = open("./textures/paths", O_RDONLY);
	if (fd < 0)
		exit (ERROR);
	while (++i < NB_FLOOR_TX)
		textures->floor[i] = texture_inject(textures->floor[i], \
			rm_nl(get_next_line(fd)));
	i = -1;
	while (++i < NB_WALL_TX)
		textures->wall[i] = texture_inject(textures->wall[i], \
			rm_nl(get_next_line(fd)));
	i = -1;
	while (++i < NB_DARK_TX)
		textures->dark[i] = texture_inject(textures->dark[i], \
			rm_nl(get_next_line(fd)));
	i = -1;
	while (++i < 2)
		textures->death_screen[i] = texture_inject(textures->death_screen[i], \
			rm_nl(get_next_line(fd)));
	texture_grab_utils(textures, fd);
}

static void	texture_convert_utils(mlx_t *mlx, t_txt *textures, t_tile *tiles)
{
	int	i;

	i = -1;
	while (++i < NB_PORTAL_TX)
		tiles->portal[i] = texture_load(mlx, textures->portal[i]);
	tiles->portal_off = texture_load(mlx, textures->portal_off);
	tiles->dark = texture_load(mlx, textures->dark[get_data()->light]);
	tiles->death_screen[0] = texture_load(mlx, textures->death_screen[0]);
	tiles->death_screen[1] = texture_load(mlx, textures->death_screen[1]);
	tiles->win_screen[0] = texture_load(mlx, textures->win_screen[0]);
	tiles->win_screen[1] = texture_load(mlx, textures->win_screen[1]);
	tiles->death_screen[1]->enabled = false;
	tiles->win_screen[1]->enabled = false;
}

void	texture_convert(mlx_t *mlx, t_txt *textures, t_tile *tiles)
{
	int	i;

	i = -1;
	while (++i < NB_FLOOR_TX)
		tiles->floor[i] = texture_load(mlx, textures->floor[i]);
	i = -1;
	while (++i < NB_WALL_TX)
		tiles->wall[i] = texture_load(mlx, textures->wall[i]);
	i = -1;
	tiles->player = texture_load(mlx, \
		textures->player[get_data()->player_facing]);
	while (++i < NB_ZOMBIE_TX)
		tiles->zombie[i] = texture_load(mlx, textures->zombie[i]);
	i = -1;
	while (++i < NB_KEY_TX)
		tiles->key[i] = texture_load(mlx, textures->key[i]);
	texture_convert_utils(mlx, textures, tiles);
}

void	texture_handler(mlx_t *mlx, t_txt *textures, t_tile *tiles)
{
	texture_grab(textures);
	texture_convert(mlx, textures, tiles);
}
