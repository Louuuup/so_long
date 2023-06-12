/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:54:16 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/06/12 18:45:01 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define ERROR -1
# define NO_ERROR 0

// Stash: Only actual line
// Buffer: all infos read for "BUFFER_SIZE" bytes.
// b_proxy: Tmp string for buffer.
// proxy: temp to free old stashs.
// rd_out: number of bytes read with read();
// stash_size: Total lengh of actual stash string.
// nl_byte: position of '\n' in Buffer.
// error: 0 if no error, other if something went wrong
typedef struct datas
{
	char	*stash;
	char	buffer[BUFFER_SIZE + 1];
	char	b_pxy[BUFFER_SIZE + 1];
	char	*proxy;
	int		rd_out;
	int		nl_idx;
	int		stash_size;
	int		error;
}			t_data;

char	*get_next_line(int fd);

#endif