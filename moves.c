/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 15:03:11 by crepou            #+#    #+#             */
/*   Updated: 2023/04/09 21:42:07 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_over_empty_space(t_system *system, int type, int x, int y)
{
	update_elem_value(&(system->map), '0', x, y);
	if (type == 0)
	{
		system->map->map_info->player_y -= 1;
		update_elem_value(&(system->map), 'P', x, y - 1);
		system->images[4]->instances[0].y = (y - 1) * 69;
	}
	else if (type == 1)
	{
		system->map->map_info->player_y += 1;
		update_elem_value(&(system->map), 'P', x, y + 1);
		system->images[4]->instances[0].y = (y + 1) * 69;
	}
	else if (type == 2)
	{
		system->map->map_info->player_x += 1;
		update_elem_value(&(system->map), 'P', x + 1, y);
		system->images[4]->instances[0].x = (x + 1) * 69;
	}
	else
	{
		system->map->map_info->player_x -= 1;
		update_elem_value(&(system->map), 'P', x - 1, y);
		system->images[4]->instances[0].x = (x - 1) * 69;
	}
}

void	move_over_collectible(t_system *system, int type)
{
	t_coordinates	*elem;
	int				x;
	int				y;
	char			*score_str;
	char			*score;

	move_over_empty_space(system, type, system->map->map_info->player_x, \
		system->map->map_info->player_y);
	x = system->map->map_info->player_x;
	y = system->map->map_info->player_y;
	elem = elem_identify(system->map, x, y);
	system->images[0]->instances[elem->instance_index - 1].enabled = 0;
	system->map->map_info->score++;
	mlx_delete_image(system->window, system->map->map_info->score_img);
	score = ft_itoa(system->map->map_info->score);
	score_str = ft_strjoin("score: ", score);
	system->map->map_info->score_img = \
		mlx_put_string(system->window, score_str, 5, \
		system->map->map_info->co_y * 66 - 43);
	free(score);
	free(score_str);
	if (system->map->map_info->score == system->map->map_info->collectibles)
		system->map->map_info->exit_enabled = 1;
}
