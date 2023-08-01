/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:08:16 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/08/01 14:45:26 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// Replaces the first occurence of newline by '\n'
// (so the new line will finish there)
char	*rm_nl(char *str)
{
    int i;
	
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			{
				str[i] = '\0';
				return (str);
			}
		else if (str[i] == '\0')
			return (str);
		i++;
	}
	return (str);
}

void ft_error(char *str)
{
	ft_putstr_fd("ERROR >>> ", 2);	
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);	
	exit(EXIT_FAILURE);
}

void ft_error_mlx(void)
{
	ft_putstr_fd((char *)mlx_strerror(mlx_errno), 2);
	exit(EXIT_FAILURE);
}