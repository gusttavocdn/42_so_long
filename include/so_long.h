/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaku <otaku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:02:06 by otaku             #+#    #+#             */
/*   Updated: 2023/04/08 20:32:06 by otaku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include "../libft/libft.h"
# include "mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define W_WIDTH 900
# define W_HEIGHT 600
# define BLOCK_ASSET "../assets/block.xpm"

typedef struct s_img
{
	void *img_ptr;
	int w;
	int h;
} t_img;


typedef struct s_mlx
{
	void *game_ptr;
	void *win_ptr;
} t_mlx;

int handle_key_events(int key_code, t_mlx *mlx);

#endif // SO_LONG_H
