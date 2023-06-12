/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:10:53 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/06/12 19:06:49 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <MLX42/MLX42.h>

int main(void)
{
    char *line;
    int fd;
    int i;

    i = 0;
    fd = 0;
	line = NULL;
	fd = open("./maps/map_test.txt", O_RDONLY);
	if (fd < 0)
		return (ERROR);
	while (i != -1)
	{
		line = get_next_line(fd);
		if (!line || line[0] == '\0')
			i = -1;
		free(line);
		line = NULL;
	}
    fd = close(fd);
}