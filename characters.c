/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   characters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:32:06 by crepou            #+#    #+#             */
/*   Updated: 2023/04/04 18:01:33 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*create_player(mlx_t *mlx)
{
	xpm_t			*player_texture;
	mlx_image_t		*img;

	player_texture = mlx_load_xpm42("./icons/player_good.xpm42");
	if (!player_texture)
		return (NULL);
	img = mlx_texture_to_image(mlx, &player_texture->texture);
	mlx_delete_texture(&player_texture->texture);
	if (!img)
		return (NULL);
	return (img);
}

mlx_image_t	*create_enemy(mlx_t *mlx)
{
	xpm_t		*enemy_texture;
	mlx_image_t	*img;

	enemy_texture = mlx_load_xpm42("./icons/bad.xpm42");
	if (!enemy_texture)
		return (NULL);
	img = mlx_texture_to_image(mlx, &enemy_texture->texture);
	mlx_delete_texture(&enemy_texture->texture);
	if (!img)
		return (NULL);
	return (img);
}
