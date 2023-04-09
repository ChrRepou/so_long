/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:07:41 by crepou            #+#    #+#             */
/*   Updated: 2023/03/29 15:32:40 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	not_valid_arguments(void)
{
	ft_printf("Error\nThe arguments that you gave are invalid.\n");
}

void	not_valid_fd(void)
{
	ft_printf("Error\nThe file descriptor is not valid.\n");
}

char	*create_images_error(void)
{
	return (ft_strdup("Error\nThe images could not be created.\n"));
}
