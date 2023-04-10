/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaku <otaku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:47:55 by otaku             #+#    #+#             */
/*   Updated: 2023/04/10 02:13:11 by otaku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int is_map_surrounded_by_walls(t_map *map);

static int has_map_all_and_only_map_chars(t_map *map);

static int is_map_rectangular(t_map *map);

void validate_map(t_map *map)
{
	if (!is_map_surrounded_by_walls(map) || !is_map_rectangular(map))
	{
		perror("MAP INVALID!! The map should be \
		rectangular and surrounded by walls");
		exit(ERROR_STATUS);
	}
	if (!has_map_all_and_only_map_chars(map))
	{
		perror("MAP INVALID! The map has invalid \
		chars or doesn't have all necessary chars");
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
	if (!ft_strfull(map->matriz[first_row], WALL_CHAR)
		|| !ft_strfull(map->matriz[last_row], WALL_CHAR))
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

static int has_map_all_and_only_map_chars(t_map *map)
{
	size_t i;
	size_t j;
	size_t k;
	char map_chars[6];

	i = 0;
	k = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			if (!ft_includes_char(map->matriz[i][j], MAP_CHARS))
				return (FALSE);
			if (!ft_includes_char(map->matriz[i][j], map_chars))
				map_chars[k++] = map->matriz[i][j];
			j++;
		}
		i++;
	}
	map_chars[k] = '\0';
	return (ft_strlen(map_chars) == ft_strlen(MAP_CHARS));
}

static int is_map_rectangular(t_map *map)
{
	size_t i;
	size_t line_len;

	i = 0;
	while (i < map->rows)
	{
		if (i == map->rows - 1)
			line_len = ft_strlen(map->matriz[i]);
		else
			line_len = ft_strlen(map->matriz[i]) - 1;
		if (line_len != map->columns)
			return (FALSE);
		i++;
	}
	if (i != map->rows)
		return (FALSE);
	return (TRUE);
}