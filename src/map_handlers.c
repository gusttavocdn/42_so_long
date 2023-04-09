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

int is_map_surronded_by_walls(t_map *map);

int read_map_file(char *filepath, t_map *map)
{
	size_t i;
	int fd;
	char *line;

	fd = open(filepath, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line != NULL)
	{
		map->matriz[i] = line;
		line = get_next_line(fd);
		i++;
	}
	map->rows = i;
	map->columns = ft_strlen(map->matriz[i - 1]);
	close(fd);
	if (!is_map_surronded_by_walls(map))
		return (FALSE);
	return (TRUE);
}

int is_map_surronded_by_walls(t_map *map)
{
	size_t last_row;
	size_t first_row;
	size_t current_row_first_column;
	size_t current_row_last_column;
	size_t i;

	first_row = 0;
	last_row = map->rows - 1;
	current_row_first_column = 0;
	current_row_last_column = map->columns - 1;
	if (!ft_strfull(map->matriz[first_row], WALL_CHAR) ||
	    !ft_strfull(map->matriz[last_row], WALL_CHAR))
		return (FALSE);

	i = 1;
	while (i < last_row)
	{
		if (map->matriz[i][current_row_first_column] != WALL_CHAR ||
		    map->matriz[i][current_row_last_column] != WALL_CHAR)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
