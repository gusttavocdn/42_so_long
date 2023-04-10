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

static int is_map_surrounded_by_walls(t_map *map);

static int has_map_only_allowed_chars(t_map *map);

void validate_map(t_map *map)
{
	if (!is_map_surrounded_by_walls(map))
	{
		perror("MAP INVALID!!. Ensure that the map corners is formed by walls");
		exit(ERROR_STATUS);
	}

	if (!has_map_only_allowed_chars(map))
	{
		perror("MAP INVALID!! The map should be formed only by the '01CEP' chars");
		exit(ERROR_STATUS);
	}
}

static int is_map_surrounded_by_walls(t_map *map)
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

static int has_map_only_allowed_chars(t_map *map)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			if (!ft_includes_char(map->matriz[i][j], MAP_CHARS))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}