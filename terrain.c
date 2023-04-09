/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terrain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:46:23 by crepou            #+#    #+#             */
/*   Updated: 2023/04/09 21:18:22 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*create_ground(mlx_t *mlx)
{
	xpm_t			*ground_texture;
	mlx_image_t		*img;

	ground_texture = mlx_load_xpm42("./icons/tile.xpm42");
	if (!ground_texture)
		return (NULL);
	img = mlx_texture_to_image(mlx, &ground_texture->texture);
	mlx_delete_texture(&ground_texture->texture);
	if (!img)
		return (NULL);
	return (img);
}

mlx_image_t	*create_wall(mlx_t *mlx)
{
	xpm_t			*wall_texture;
	mlx_image_t		*img;

	wall_texture = mlx_load_xpm42("./icons/tree.xpm42");
	if (!wall_texture)
		return (NULL);
	img = mlx_texture_to_image(mlx, &wall_texture->texture);
	mlx_delete_texture(&wall_texture->texture);
	if (!img)
		return (NULL);
	return (img);
}

mlx_image_t	*create_terrain(mlx_t *mlx)
{
	xpm_t			*wall_texture;
	mlx_image_t		*img;

	wall_texture = mlx_load_xpm42("./icons/grounds.xpm42");
	if (!wall_texture)
		return (NULL);
	img = mlx_texture_to_image(mlx, &wall_texture->texture);
	mlx_delete_texture(&wall_texture->texture);
	if (!img)
		return (NULL);
	return (img);
}