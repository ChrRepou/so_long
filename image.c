/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:09:40 by crepou            #+#    #+#             */
/*   Updated: 2023/04/09 18:09:06 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	**create_images(mlx_t *window)
{
	mlx_image_t	**img;

	img = (mlx_image_t **) malloc(sizeof(mlx_image_t *) * 8);
	if (!img)
		return (NULL);
	img[0] = create_collectible(window);
	img[1] = create_exit(window);
	img[2] = create_ground(window);
	img[3] = create_wall(window);
	img[4] = create_player(window);
	img[5] = create_enemy(window);
	img[6] = create_terrain(window);
	img[7] = NULL;
	if (!img[0] || !img[1] || !img[2] || !img[3] \
		|| !img[4] || !img[5] || !img[6])
		return (free_images(img, window), NULL);
	return (img);
}
