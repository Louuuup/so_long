/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:42:22 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/08/11 17:07:39 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_texture_t	*texture_inject(mlx_texture_t *texture, void *ptr)
{
	texture = mlx_load_png(ptr);
	ft_free(ptr);
	if (!texture)
		ft_error_mlx();
	return (texture);
}

mlx_image_t	*texture_load(mlx_t *mlx, mlx_texture_t *texture)
{
	mlx_image_t	*tmp;

	tmp = mlx_texture_to_image(mlx, texture);
	if (!tmp)
		ft_error_mlx();
	return (tmp);
}
