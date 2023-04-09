/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_events.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaku <otaku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:29:21 by otaku             #+#    #+#             */
/*   Updated: 2023/04/07 17:16:07 by otaku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void ft_end_program(t_mlx *mlx);

static void ft_end_program(t_mlx *mlx)
{
	mlx_loop_end(mlx->game_ptr);
	mlx_destroy_window(mlx->game_ptr, mlx->win_ptr);
	exit(0);
}

int handle_key_events(int key_code, t_mlx *mlx)
{
	if (key_code == XK_Escape)
		ft_end_program(mlx);
	return (0);
}
