/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:01:28 by crepou            #+#    #+#             */
/*   Updated: 2023/04/04 18:26:14 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_top(t_map *map)
{
	int		length;
	int		i;
	char	value;

	length = map->map_info->co_x;
	i = 0;
	while (i < length)
	{
		value = map->lines_table->points[i]->val;
		if (value != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_bottom(t_map *map)
{
	int				length;
	int				i;
	char			value;
	t_lines_table	*tail;

	length = map->map_info->co_x;
	tail = map->lines_table;
	while (tail->next)
		tail = tail->next;
	i = 0;
	while (i < length)
	{
		value = tail->points[i]->val;
		if (value != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_left(t_map *map)
{
	char			value;
	t_lines_table	*head;
	t_coordinates	**line;

	head = map->lines_table;
	while (head != NULL)
	{
		line = head->points;
		value = line[0]->val;
		if (value != '1')
			return (0);
		head = head->next;
	}
	return (1);
}

int	check_right(t_map *map)
{
	char			value;
	t_lines_table	*head;
	t_coordinates	**line;
	int				length;

	head = map->lines_table;
	length = map->map_info->co_x;
	while (head != NULL)
	{
		line = head->points;
		value = line[length - 1]->val;
		if (value != '1')
			return (0);
		head = head->next;
	}
	return (1);
}
