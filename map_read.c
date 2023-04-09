/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:32:19 by crepou            #+#    #+#             */
/*   Updated: 2023/04/09 21:16:22 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map_info	*create_map_info(void)
{
	t_map_info	*map_info;

	map_info = (t_map_info *)malloc(sizeof(t_map_info));
	map_info->co_x = 0;
	map_info->co_y = 0;
	map_info->collectibles = 0;
	map_info->empty_space = 0;
	map_info->exits = 0;
	map_info->position = 0;
	map_info->walls = 0;
	map_info->player_x = 0;
	map_info->player_y = 0;
	map_info->score = 0;
	map_info->exit_enabled = 0;
	map_info->enemy_x = 0;
	map_info->enemy_y = 0;
	map_info->enemies = 0;
	map_info->win = 0;
	map_info->fire = -1;
	map_info->fire_x = 0;
	map_info->fire_y = 0;
	return (map_info);
}

t_map	*create_map(void)
{
	t_map		*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->lines_table = NULL;
	map->map_info = create_map_info();
	return (map);
}

int	update_map(t_map **map, t_line_info *curr_ln_info, \
	char *curr_ln, int ln_no)
{
	t_coordinates	**coordinates;

	(*map)->map_info->co_x = curr_ln_info->length;
	(*map)->map_info->collectibles += curr_ln_info->collectibles;
	(*map)->map_info->empty_space += curr_ln_info->empty_space;
	(*map)->map_info->exits += curr_ln_info->exits;
	(*map)->map_info->position += curr_ln_info->position;
	(*map)->map_info->walls += curr_ln_info->walls;
	(*map)->map_info->enemies += curr_ln_info->enemies;
	(*map)->map_info->co_y = ln_no;
	coordinates = create_line_table(ln_no, curr_ln, (*map));
	if (!coordinates)
		return (1);
	if (ln_no == 0)
		(*map)->lines_table = create_new_table_line(\
			coordinates, NULL);
	else
		(*map)->lines_table = create_new_table_line(\
			coordinates, (*map)->lines_table);
	if (!(*map)->lines_table)
		return (1);
	return (0);
}

int	get_first_line(t_map **map, char **curr_line, int fd)
{
	(*map) = create_map();
	if (!(*map))
		return (0);
	(*curr_line) = get_next_line(fd);
	if (!(*curr_line))
		return (0);
	return (1);
}

t_map	*read_map(int fd)
{
	t_line_info	*curr_line_info;
	char		*curr_line;
	t_map		*map;
	int			ln_flag;
	int			line_no;

	if (!get_first_line(&map, &curr_line, fd))
		return (NULL);
	ln_flag = 0;
	line_no = 0;
	while (curr_line != NULL)
	{
		curr_line_info = read_line(curr_line);
		if (!curr_line_info || \
			(curr_line_info->length != map->map_info->co_x && ln_flag == 1) \
				|| update_map(&map, curr_line_info, curr_line, line_no))
			return (NULL);
		free(curr_line);
		free(curr_line_info);
		curr_line = get_next_line(fd);
		map->map_info->co_y++;
		ln_flag = 1;
		line_no++;
	}
	return (map);
}
