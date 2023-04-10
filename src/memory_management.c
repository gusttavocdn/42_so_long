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

void dealloc_map_matriz(t_map *map)
{
	size_t i;

	i = 0;
	while (i < map->rows)
		free(map->matriz[i++]);
	free(map->matriz);
}