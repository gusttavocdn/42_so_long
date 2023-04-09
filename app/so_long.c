/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaku <otaku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:47:55 by otaku             #+#    #+#             */
/*   Updated: 2023/04/08 20:41:07 by otaku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int main(int argc, char **argv)
{
	t_mlx mlx;

	if (argc != 2)
	{
		perror("This program accepts only 1 argument that must be a map.ber file");
		return (1);
	}

	ft_printf("%s", argv[1]);

	mlx.game_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.game_ptr, W_WIDTH, W_HEIGHT, "So Long");

	mlx_key_hook(mlx.win_ptr, handle_key_events, &mlx);
	mlx_loop(mlx.game_ptr);
	return (0);
}
