/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:05:24 by crepou            #+#    #+#             */
/*   Updated: 2023/04/09 21:37:37 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(mlx_key_data_t keydata, t_system *system)
{
	int				x;
	int				y;
	t_coordinates	*elem;

	if (keydata.key == MLX_KEY_LEFT && \
		(keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		x = system->map->map_info->player_x;
		y = system->map->map_info->player_y;
		elem = elem_identify(system->map, x - 1, y);
		if (elem->val == '0')
			move_over_empty_space(system, 3, x, y);
		else if (elem->val == 'C')
			move_over_collectible(system, 3);
		else if (elem->val == 'E' && system->map->map_info->exit_enabled)
		{
			mlx_close_window(system->window);
			system->map->map_info->win = 0;
		}
		else if (elem->val == 'B')
		{
			system->map->map_info->win = 1;
			mlx_close_window(system->window);
		}
	}
}

void	move_right(mlx_key_data_t keydata, t_system *system)
{
	int				x;
	int				y;
	t_coordinates	*elem;

	if (keydata.key == MLX_KEY_RIGHT && \
		(keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		x = system->map->map_info->player_x;
		y = system->map->map_info->player_y;
		elem = elem_identify(system->map, (x + 1), y);
		if (elem->val == '0')
			move_over_empty_space(system, 2, x, y);
		else if (elem->val == 'C')
			move_over_collectible(system, 2);
		else if (elem->val == 'E' && system->map->map_info->exit_enabled)
		{
			mlx_close_window(system->window);
			system->map->map_info->win = 0;
		}
		else if (elem->val == 'B')
		{
			system->map->map_info->win = 1;
			mlx_close_window(system->window);
		}
	}
}

void	move_down(mlx_key_data_t keydata, t_system *system)
{
	int				x;
	int				y;
	t_coordinates	*elem;

	if (keydata.key == MLX_KEY_DOWN && \
		(keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		x = system->map->map_info->player_x;
		y = system->map->map_info->player_y;
		elem = elem_identify(system->map, x, y + 1);
		if (elem->val == '0')
			move_over_empty_space(system, 1, x, y);
		else if (elem->val == 'C')
			move_over_collectible(system, 1);
		else if (elem->val == 'E' && system->map->map_info->exit_enabled)
		{
			mlx_close_window(system->window);
			system->map->map_info->win = 0;
		}
		else if (elem->val == 'B')
		{
			system->map->map_info->win = 1;
			mlx_close_window(system->window);
		}
	}
}

void	move_up(mlx_key_data_t keydata, t_system *system)
{
	int				x;
	int				y;
	t_coordinates	*elem;

	if (keydata.key == MLX_KEY_UP && \
		(keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		x = system->map->map_info->player_x;
		y = system->map->map_info->player_y;
		elem = elem_identify(system->map, x, y - 1);
		if (elem->val == '0')
			move_over_empty_space(system, 0, x, y);
		else if (elem->val == 'C')
			move_over_collectible(system, 0);
		else if (elem->val == 'E' && system->map->map_info->exit_enabled)
		{
			mlx_close_window(system->window);
			system->map->map_info->win = 0;
		}
		else if (elem->val == 'B')
		{
			system->map->map_info->win = 1;
			mlx_close_window(system->window);
		}
	}
}

void	quit_window(mlx_key_data_t keydata, t_system *system)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(system->window);
	move_left(keydata, system);
	move_right(keydata, system);
	move_up(keydata, system);
	move_down(keydata, system);
	shot_fire(keydata, system);
}
