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

static void count_map_rows_and_columns(char *filepath, t_map *map);

static void create_map_matriz(char *filepath, t_map *map);

void read_map_file(char *filepath, t_map *map)
{

	if (!ft_strnstr(filepath, ".ber", ft_strlen(filepath)))
	{
		perror("The map file must be a .ber file");
		exit(ERROR_STATUS);
	}
	count_map_rows_and_columns(filepath, map);
	create_map_matriz(filepath, map);
}

static void count_map_rows_and_columns(char *filepath, t_map *map)
{
	int fd;
	size_t i;
	char *line;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
	{
		perror("There was an error open map file");
		exit(ERROR_STATUS);
	}
	i = 0;
	line = get_next_line(fd);
	map->columns = ft_strlen(line) - 1;
	while (line != NULL)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	map->rows = i;
	close(fd);
}

static void create_map_matriz(char *filepath, t_map *map)
{
	int fd;
	size_t i;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
	{
		perror("There was an error open map file");
		exit(ERROR_STATUS);
	}
	i = 0;
	map->matriz = (char **) ft_calloc(map->rows + 1, sizeof(char *));
	map->matriz[i] = get_next_line(fd);
	while (map->matriz[i] != NULL)
	{
		i++;
		map->matriz[i] = get_next_line(fd);
	}
	close(fd);
}
