/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:22:14 by crepou            #+#    #+#             */
/*   Updated: 2023/04/04 18:20:32 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_coordinates(t_coordinates **coordinates)
{
	int	i;

	if (!coordinates)
		return ;
	i = 0;
	while (coordinates[i])
	{
		free(coordinates[i]);
		i++;
	}
	free(coordinates);
}

void	free_lines_table(t_lines_table *lines)
{
	t_lines_table	*prev_line;

	prev_line = lines;
	while (lines)
	{
		if (!lines->points)
			break ;
		free_coordinates(lines->points);
		lines = lines->next;
		free(prev_line);
		prev_line = lines;
	}
}

void	free_images(mlx_image_t **images, mlx_t *window)
{
	int	i;

	i = 0;
	while (i < 6 && images[i] != NULL)
	{
		mlx_delete_image(window, images[i]);
		i++;
	}
	free(images);
}

void	free_all(t_system *system)
{
	if (!system)
		return ;
	if (!(system->map))
		return ;
	if (system->map->map_info)
		free(system->map->map_info);
	if (system->map->lines_table)
		free_lines_table(system->map->lines_table);
	if (system->images && system->window)
		free_images(system->images, system->window);
	free(system->map);
	if (system->window)
		mlx_terminate(system->window);
	free(system);
}
