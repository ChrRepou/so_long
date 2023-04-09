/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:20:04 by crepou            #+#    #+#             */
/*   Updated: 2023/04/09 22:20:34 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_coordinates	*next_wall(int x, int y, t_system *system)
{
	int				i;
	t_lines_table	*lines_table;

	i = 0;
	lines_table = system->map->lines_table;
	while (i < y)
	{
		lines_table = lines_table->next;
		i++;
	}
	i = x;
	while (i < system->map->map_info->co_x)
	{
		if (lines_table->points[i]->val == '1')
			return (lines_table->points[i]);
		i++;
	}
	return (lines_table->points[i]);
}

void	delete_enemy(t_system *system)
{
	int				i;
	int				j;
	t_coordinates	**line;
	t_lines_table	*table;

	i = 0;
	table = system->map->lines_table;
	while (i < system->map->map_info->co_y)
	{
		line = table->points;
		j = 0;
		while (j < system->map->map_info->co_x)
		{
			if (line[j]->val == 'B')
			{
				line[j]->val = '0';
				mlx_delete_image(system->window, system->images[5]);
			}
			j++;
		}
		table = table->next;
		i++;
	}
}

void	fire_graphic(t_system *system)
{
	if (system->images[7] && system->images[7]->instances != NULL)
	{
		if (system->map->map_info->fire_x < system->map->map_info->fire_stop)
		{
		system->map->map_info->fire_x += 0.25;
		system->images[7]->instances->x += 17;
			if ((system->images[7]->instances->x >= \
				system->map->map_info->enemy_x * 69 \
				&& system->images[7]->instances->x \
				< (system->map->map_info->enemy_x + 1) * 69) && \
				system->map->map_info->player_y == \
				system->map->map_info->enemy_y)
				delete_enemy(system);
		}
		else
		{
			mlx_delete_image(system->window, system->images[7]);
			system->images[7] = NULL;
		}
	}
}

void	shot_fire(mlx_key_data_t keydata, t_system *system)
{
	if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
	{
		if (!system->images[7])
		{
			system->map->map_info->fire_stop = (float)next_wall(\
				system->map->map_info->player_x, \
				system->map->map_info->player_y, system)->x;
			system->images[7] = create_fire(system->window);
			system->map->map_info->fire_x = system->map->map_info->player_x;
			mlx_image_to_window(system->window, system->images[7], \
				system->map->map_info->player_x * 69, \
				system->map->map_info->player_y * 66 + 16);
		}
	}
}
