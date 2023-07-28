/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2523/06/14 14:14:47 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/07/28 16:54:35 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



static void texture_grab(t_txt* textures)
{
    // int i;
    // i = -1;
    // int		fd;
	
    // fd = 0;
	// fd = open("./textures/paths.txt", O_RDONLY);
	// if (fd < 0)
	// 	exit (ERROR);
    // while (++i < 8)
    //     printf("%s", get_next_line(fd));
    textures->floor[0] = mlx_load_png("./textures/floor0.png");
    textures->floor[1] = mlx_load_png("./textures/floor1.png");
    textures->floor[2] = mlx_load_png("./textures/floor2.png");
    textures->floor[3] = mlx_load_png("./textures/floor3.png");
    textures->floor[4] = mlx_load_png("./textures/floor4.png");
    textures->floor[5] = mlx_load_png("./textures/floor5.png");
    textures->floor[6] = mlx_load_png("./textures/floor6.png");
    textures->floor[7] = mlx_load_png("./textures/floor7.png");
    textures->wall[0] = mlx_load_png("./textures/wall0.png");
    textures->wall[1] = mlx_load_png("./textures/wall1.png");
    textures->wall[2] = mlx_load_png("./textures/wall2.png");
    textures->wall[3] = mlx_load_png("./textures/wall3.png");
    textures->wall[4] = mlx_load_png("./textures/wall4.png");
    textures->wall[5] = mlx_load_png("./textures/wall5.png");
    textures->wall[6] = mlx_load_png("./textures/wall6.png");
    textures->wall[7] = mlx_load_png("./textures/wall7.png");
    textures->wall[8] = mlx_load_png("./textures/wall8.png");
    textures->wall[9] = mlx_load_png("./textures/wall9.png");
    textures->wall[10] = mlx_load_png("./textures/wall10.png");
    textures->wall[11] = mlx_load_png("./textures/wall11.png");
    textures->wall[12] = mlx_load_png("./textures/wall12.png");
    textures->wall[13] = mlx_load_png("./textures/wall13.png");
    textures->wall[14] = mlx_load_png("./textures/wall14.png");
    textures->wall[15] = mlx_load_png("./textures/wall15.png");
    textures->wall[16] = mlx_load_png("./textures/wall16.png");
    textures->wall[17] = mlx_load_png("./textures/wall17.png");
    textures->wall[18] = mlx_load_png("./textures/wall18.png");
    textures->wall[19] = mlx_load_png("./textures/wall19.png");
    textures->wall[20] = mlx_load_png("./textures/wall20.png");
    textures->wall[21] = mlx_load_png("./textures/wall21.png");
    textures->wall[22] = mlx_load_png("./textures/wall22.png");
    textures->wall[23] = mlx_load_png("./textures/wall23.png");
    textures->wall[24] = mlx_load_png("./textures/wall24.png");
    textures->dark[0] = mlx_load_png("./textures/shadow0.png");
    textures->dark[1] = mlx_load_png("./textures/shadow1.png");
    textures->dark[2] = mlx_load_png("./textures/shadow2.png");
    textures->dark[3] = mlx_load_png("./textures/shadow3.png");
    textures->dark[4] = mlx_load_png("./textures/shadow4.png");
    textures->dark[5] = mlx_load_png("./textures/shadow5.png");
    textures->dark[6] = mlx_load_png("./textures/shadow6.png");
    textures->dark[7] = mlx_load_png("./textures/shadow7.png");
    textures->dark[8] = mlx_load_png("./textures/shadow8.png");
    textures->dark[9] = mlx_load_png("./textures/shadow9.png");
    textures->dark[10] = mlx_load_png("./textures/shadow10.png");
    textures->dark[11] = mlx_load_png("./textures/shadow11.png");
    textures->dark[12] = mlx_load_png("./textures/shadow12.png");
    textures->dark[13] = mlx_load_png("./textures/shadow13.png");
    textures->dark[14] = mlx_load_png("./textures/shadow14.png");
    textures->death_screen[0] = mlx_load_png("./textures/death0.png");
    textures->death_screen[1] = mlx_load_png("./textures/death1.png");
    // textures->door = mlx_load_png(FILE_TEST);
    // textures->ennemy = mlx_load_png(FILE_TEST);
    textures->key[0] = mlx_load_png("./textures/key0.png");
    textures->key[1] = mlx_load_png("./textures/key1.png");
    textures->key[2] = mlx_load_png("./textures/key2.png");
    textures->key[3] = mlx_load_png("./textures/key3.png");
    textures->key[4] = mlx_load_png("./textures/key4.png");
    textures->key[5] = mlx_load_png("./textures/key5.png");
    textures->key[6] = mlx_load_png("./textures/key6.png");
    textures->key[7] = mlx_load_png("./textures/key7.png");
    textures->portal[0] = mlx_load_png("./textures/portal0.png");
    textures->portal[1] = mlx_load_png("./textures/portal1.png");
    textures->portal[2] = mlx_load_png("./textures/portal2.png");
    textures->portal[3] = mlx_load_png("./textures/portal3.png");
    textures->portal[4] = mlx_load_png("./textures/portal4.png");
    textures->portal[5] = mlx_load_png("./textures/portal5.png");
    textures->portal[6] = mlx_load_png("./textures/portal6.png");
    textures->portal[7] = mlx_load_png("./textures/portal7.png");
    textures->portal[8] = mlx_load_png("./textures/portal8.png");
    textures->player[0] = mlx_load_png("./textures/player_u.png");
    textures->player[1] = mlx_load_png("./textures/player_r.png");
    textures->player[2] = mlx_load_png("./textures/player_d.png");
    textures->player[3] = mlx_load_png("./textures/player_l.png");
    textures->zombie[0] = mlx_load_png("./textures/zombie_u.png");
    textures->zombie[1] = mlx_load_png("./textures/zombie_r.png");
    textures->zombie[2] = mlx_load_png("./textures/zombie_d.png");
    textures->zombie[3] = mlx_load_png("./textures/zombie_l.png");
    
    if (!textures->floor[0] || !textures->floor[1] || !textures->floor[2] || !textures->floor[3]
        || !textures->floor[4] || !textures->floor[5] || !textures->floor[6] || !textures->floor[7]
        || !textures->wall[0] || !textures->wall[1] || !textures->wall[2] || !textures->wall[3]
        || !textures->wall[4] || !textures->wall[5] || !textures->player[0] || !textures->player[1]
        || !textures->player[2] || !textures->player[3] || !textures->dark[0])
        ft_error_mlx();
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
    tiles->death_screen[1]->enabled = false;
    
}

void texture_handler(mlx_t* mlx, t_txt* textures, t_tile* tiles)
{
    texture_grab(textures);
    texture_convert(mlx, textures, tiles);
    printf("Texture Handling DONE\n");

}
