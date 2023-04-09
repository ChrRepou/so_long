/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:28:01 by crepou            #+#    #+#             */
/*   Updated: 2023/04/05 15:27:32 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*create_collectible(mlx_t *mlx)
{
	xpm_t		*collectible_texture;
	mlx_image_t	*img;

	collectible_texture = mlx_load_xpm42("./icons/gem.xpm42");
	if (!collectible_texture)
		return (NULL);
	img = mlx_texture_to_image(mlx, &collectible_texture->texture);
	mlx_delete_texture(&collectible_texture->texture);
	if (!img)
		return (NULL);
	return (img);
}

mlx_image_t	*create_exit(mlx_t *mlx)
{
	xpm_t		*exit_texture;
	mlx_image_t	*img;

	exit_texture = mlx_load_xpm42("./icons/door.xpm42");
	if (!exit_texture)
		return (NULL);
	img = mlx_texture_to_image(mlx, &exit_texture->texture);
	mlx_delete_texture(&exit_texture->texture);
	if (!img)
		return (NULL);
	return (img);
}

void	update_elem_value(t_map	**map, char updated_value, int x, int y)
{
	t_lines_table	*line;
	t_coordinates	**elem;
	int				i;

	line = (*map)->lines_table;
	i = 0;
	while (i < y)
	{
		line = line->next;
		i++;
	}
	elem = line->points;
	elem[x]->val = updated_value;
}

mlx_image_t	*create_fire(mlx_t *mlx)
{
	xpm_t		*fire_texture;
	mlx_image_t	*img;

	fire_texture = mlx_load_xpm42("./icons/fire.xpm42");
	if (!fire_texture)
		return (NULL);
	img = mlx_texture_to_image(mlx, &fire_texture->texture);
	mlx_delete_texture(&fire_texture->texture);
	if (!img)
		return (NULL);
	return (img);
}
