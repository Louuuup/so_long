/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:26:41 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/08/11 14:55:37 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_win(void)
{
	t_data	*data;

	printf("\nYOU WON!\n");
	data = get_data();
	if (data->player_alive)
	{
		data->win = 1;
		re_render(data);
	}
}
