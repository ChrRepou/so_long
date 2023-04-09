/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:50:41 by crepou            #+#    #+#             */
/*   Updated: 2023/03/29 16:25:51 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*window_creation_error(t_system *system)
{
	free_all(system);
	return (ft_strdup("Error\nThe window could not be created!\n"));
}

char	*draw_window_error(void)
{
	return (ft_strdup("Error\nThe map could not be drawed!\n"));
}

char	*system_struct_error(void)
{
	return (ft_strdup("Error\nThe t_system could not be created!\n"));
}
