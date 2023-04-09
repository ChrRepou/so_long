/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:01:55 by crepou            #+#    #+#             */
/*   Updated: 2023/04/09 15:56:43 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*fill_system(t_system **system, int fd)
{
	(*system)->map = read_map(fd);
	if ((*system)->map == NULL || !check_map((*system)->map))
		return (not_valid_map((*system)));
	(*system)->window = create_window((*system)->map->map_info->co_x * 69, \
		(*system)->map->map_info->co_y * 66);
	if ((*system)->window == NULL)
		return (window_creation_error((*system)));
	(*system)->images = create_images((*system)->window);
	if (!(*system)->images)
		return (free_all((*system)), create_images_error());
	return (NULL);
}

char	*so_long(int fd)
{
	t_system	*system;
	int			win;
	char		*message;

	system = (t_system *)malloc(sizeof(t_system));
	if (system == NULL)
		return (system_struct_error());
	message = fill_system(&system, fd);
	if (message != NULL)
		return (message);
	system->window = draw_map_on_window(system->window, system->map, \
		system->images);
	if (system->window == NULL)
		return (free_all(system), draw_window_error());
	mlx_key_hook(system->window, (mlx_keyfunc)quit_window, system);
	mlx_loop_hook(system->window, (void *)fire_graphic, system);
	mlx_loop(system->window);
	win = system->map->map_info->win;
	if (!system->map->map_info->exit_enabled)
		win = 1;
	free_all(system);
	if (!win)
		return (ft_strdup("You win!!!!"));
	return (ft_strdup("You lost!! :("));
}
