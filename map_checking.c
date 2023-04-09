/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:22:27 by crepou            #+#    #+#             */
/*   Updated: 2023/04/08 19:15:16 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	walls_in_position(t_map *mp)
{
	if (check_top(mp) && check_bottom(mp) && check_left(mp) && check_right(mp))
		return (1);
	else
		return (0);
}

int	check_map(t_map *mp)
{
	if (walls_in_position(mp) && mp->map_info->exits == 1 && \
		mp->map_info->position == 1 && mp->map_info->collectibles > 0 \
			&& all_are_reachable(mp, \
				mp->map_info->player_x, mp->map_info->player_x))
		return (1);
	else
		return (0);
}
