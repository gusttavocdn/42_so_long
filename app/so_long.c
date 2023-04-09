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

char	**read_xpm_image(void)
{
	int		fd;
	char	*line;
	char	**data;

	fd = open("../assets/block.xpm", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (ft_strnstr(line, "static char", 50))
		{
			data = ft_split(line, ',');
			break ;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (data);
}

int	main(void)
{
	t_mlx	mlx;

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, W_WIDTH, W_HEIGHT, "So Long");
	read_xpm_image();
	mlx_key_hook(mlx.win_ptr, handle_key_events, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
