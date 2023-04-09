/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:33:02 by crepou            #+#    #+#             */
/*   Updated: 2023/04/09 21:21:42 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_t	*create_window(int width, int height)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(width, height, "So long game", 1);
	if (!mlx)
		return (NULL);
	return (mlx);
}

void	set_image_to_window(\
	mlx_t *window, mlx_image_t *image, int depth, t_coordinates elem)
{
	mlx_image_to_window(window, image, elem.x * 69, elem.y * 66);
	image->instances->z += depth;
}

mlx_t	*draw_element(t_coordinates *elem, mlx_t *window, mlx_image_t **images)
{
	mlx_image_t	*img;
	t_type		type;

	img = NULL;
	type = get_enum_from_char((*elem).val);
	if ((*elem).val == 'P' || (*elem).val == 'C' \
		|| (*elem).val == 'B' || (*elem).val == 'E')
	{
		img = images[2];
		set_image_to_window(window, img, 1, (*elem));
	}
	if ((*elem).val == '1')
		set_image_to_window(window, images[6], 0, (*elem));
	img = images[type];
	if ((*elem).val == 'C')
		set_image_to_window(window, img, 1, (*elem));
	else if ((*elem).val != 'P')
		set_image_to_window(window, img, 0, (*elem));
	(*elem).instance_index = img->count;
	return (window);
}

mlx_t	*draw_map_on_window(mlx_t	*window, \
	t_map	*map, mlx_image_t	**images)
{
	t_lines_table	*lines_table;
	t_coordinates	**line;
	int				i;

	lines_table = map->lines_table;
	line = lines_table->points;
	while (lines_table != NULL)
	{
		i = 0;
		line = lines_table->points;
		while (i < map->map_info->co_x)
		{
			draw_element(&(*line[i]), window, images);
			i++;
		}
		lines_table = lines_table->next;
	}
	mlx_image_to_window(window, images[4], \
		map->map_info->player_x * 69, map->map_info->player_y * 66);
	mlx_image_to_window(window, images[5], \
		map->map_info->enemy_x * 69, map->map_info->enemy_y * 66);
	map->map_info->score_img = mlx_put_string(window, "score: 0", \
		5, map->map_info->co_y * 66 - 43);
	return (window);
}
