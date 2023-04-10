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
# define WALL_CHAR '1'
# define START_CHAR 'P'
# define EMPTY_CHAR '0'
# define COLLECTIBLE_CHAR 'C'
# define EXIT_CHAR 'E'
# define TRUE 1
# define FALSE 0
# define ERROR_STATUS 1
# define MAP_CHARS "01CEP"


typedef struct s_map
{
	char **matriz;
	size_t columns;
	size_t rows;
} t_map;

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

void read_map_file(char *filepath, t_map *map);

void validate_map(t_map *map);

#endif // SO_LONG_H
