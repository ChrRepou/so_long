/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:00:16 by crepou            #+#    #+#             */
/*   Updated: 2023/04/09 21:00:38 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_line_info	*create_line_info(void)
{
	t_line_info	*ln_info;

	ln_info = (t_line_info *)malloc(sizeof(t_line_info));
	if (!ln_info)
		return (NULL);
	ln_info->empty_space = 0;
	ln_info->walls = 0;
	ln_info->collectibles = 0;
	ln_info->exits = 0;
	ln_info->length = 0;
	ln_info->position = 0;
	ln_info->enemies = 0;
	return (ln_info);
}

t_line_info	*read_line(char	*line)
{
	t_line_info	*ln_info;

	ln_info = create_line_info();
	if (!ln_info)
		return (NULL);
	while (*line != '\n' && *line != '\0')
	{
		if (*line == '0')
			ln_info->empty_space++;
		else if (*line == '1')
			ln_info->walls++;
		else if (*line == 'C')
			ln_info->collectibles++;
		else if (*line == 'E')
			ln_info->exits++;
		else if (*line == 'P')
			ln_info->position++;
		else if (*line == 'B')
			ln_info->enemies++;
		else
			return (NULL);
		ln_info->length++;
		line++;
	}
	return (ln_info);
}

t_coordinates	**fill_lines_table(t_coordinates ***table, \
	char *curr_line, t_map *map, int line_no)
{
	int	i;

	i = 0;
	while (i < map->map_info->co_x)
	{
		(*table)[i] = (t_coordinates *)malloc(sizeof(t_coordinates));
		if (!table[i])
			return (NULL);
		(*table)[i]->val = *curr_line;
		if ((*table)[i]->val == 'P')
		{
			map->map_info->player_x = i;
			map->map_info->player_y = line_no;
		}
		else if ((*table)[i]->val == 'B')
		{
			map->map_info->enemy_x = i;
			map->map_info->enemy_y = line_no;
		}
		(*table)[i]->x = i;
		(*table)[i]->y = line_no;
		i++;
		curr_line++;
	}
	return ((*table));
}

t_coordinates	**create_line_table(int line_no, char *curr_line, t_map *map)
{
	t_coordinates	**line_table;

	line_table = (t_coordinates **)malloc(\
		sizeof(t_coordinates *) * map->map_info->co_x + 1);
	if (!line_table)
		return (NULL);
	if (!fill_lines_table(&line_table, curr_line, map, line_no))
		return (NULL);
	line_table[map->map_info->co_x] = NULL;
	return (line_table);
}

t_lines_table	*create_new_table_line(\
	t_coordinates **table_line, t_lines_table *head)
{
	t_lines_table	*new_table_line;
	t_lines_table	*tail;

	new_table_line = (t_lines_table *)malloc(sizeof(t_lines_table));
	if (!new_table_line)
		return (NULL);
	if (!table_line)
		return (NULL);
	new_table_line->points = table_line;
	new_table_line->next = NULL;
	if (head == NULL)
		return (new_table_line);
	tail = head;
	while (tail->next != NULL)
		tail = tail -> next;
	tail->next = new_table_line;
	return (head);
}
