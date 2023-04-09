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

int ft_includes(const char *str, const char *chars);

void read_map_file(char *filepath, t_map *map)
{
	size_t i;
	int fd;
	char *line;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
	{
		perror("There was an error open map file");
		exit(ERROR_STATUS);
	}
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		map->matriz[i++] = line;
		line = get_next_line(fd);
	}
	map->rows = i;
	map->columns = ft_strlen(map->matriz[i - 1]);
	close(fd);
}

void validate_map(t_map *map)
{
	if (!is_map_surronded_by_walls(map))
	{
		perror("The map is invalid. Ensure that the map has the correct format");
		exit(ERROR_STATUS);
	}
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

int has_map_only_allowed_chars(t_map *map)
{
	size_t rows;
	size_t i;
	char *row_content;

	i = 0;
	rows = map->rows;
	while (i < rows)
	{
		row_content = map->matriz[i];
		ft_includes(MAP_CHARS, row_content);

		i++;
	}

	return (TRUE);
}