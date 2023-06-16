/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:07:51 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/06/15 21:41:07 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


size_t	iso_cords_x(size_t anchor, size_t x, size_t y)
{
	size_t x_out;
	(void)anchor;
	x_out = x * 0.5 * TILE_SIZE + y * -0.5 * TILE_SIZE - TILE_SIZE;
	return (x_out);
}

size_t	iso_cords_y(size_t x, size_t y)
{
	size_t	y_out;
	y_out = x * 0.25 * TILE_SIZE + y * 0.25 * TILE_SIZE + TILE_SIZE;
	return (y_out);
}

void	put_tile(mlx_t *mlx, t_tile *tiles, mlx_image_t *img)
{
	int	x;
	int	y;
	
	tiles->anchor = 0;
	x = iso_cords_x(tiles->anchor, tiles->nxt_x, tiles->nxt_y);
	y = iso_cords_y(tiles->nxt_x, tiles->nxt_y);
    if (mlx_image_to_window(mlx, img, x, y) == -1)
        ft_error();
	printf("TILE PLACED:\nx = %zu\ny = %zu\n", tiles->nxt_x, tiles->nxt_y);
	tiles->nxt_x += 1;
}

static void	parse_line(mlx_t *mlx, t_tile *tiles, char *line)
{
	size_t	i;

	i = 0;
	tiles->nxt_x =  (WIDTH / TILE_SIZE) - (tiles->count_x / 2);
	while (line[i])
	{
		if (line[i] == '1')
			put_tile(mlx, tiles, tiles->wall);
		else if (line[i] == '0')
			put_tile(mlx, tiles, tiles->floor);
		else if (line[i] == 'P')
			put_tile(mlx, tiles, tiles->player);
		else if (line[i] == 'C')
			put_tile(mlx, tiles, tiles->collectible);
		else if (line[i] == 'E')
			put_tile(mlx, tiles, tiles->door);
		else if (line[i] == '0')
			put_tile(mlx, tiles, tiles->floor);
		else if (line[i] == '0')
			put_tile(mlx, tiles, tiles->floor);
		i++;
	}
	tiles->nxt_x = 0;
	tiles->nxt_y += 1;	
	return ;
}

int	parse_main(mlx_t *mlx, t_tile *tiles)
{
	char	*line;
	int		fd;

    fd = 0;
	line = NULL;
	fd = open(MAP, O_RDONLY);
	if (fd < 0)
		return (EXIT_FAILURE);
	while (1)
	{
		line = get_next_line(fd);
		printf("fd=%d\nline=%s\n", fd, line); // tmp
		if (!line || line[0] == '\0')
			break ;
		else
		{
			tiles->count_x = ft_strlen(line);
			parse_line(mlx, tiles, line);
		}
		free(line);
		line = NULL;
	}
    fd = close(fd);
	return (EXIT_SUCCESS);
}
