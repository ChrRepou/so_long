/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_to_enum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:56:23 by crepou            #+#    #+#             */
/*   Updated: 2023/03/24 12:05:32 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_type	get_enum_from_char(char c)
{
	t_type	type;

	if (c == 'C')
		type = C;
	else if (c == 'E')
		type = E;
	else if (c == '0')
		type = G;
	else if (c == '1')
		type = W;
	else if (c == 'P')
		type = P;
	else
		type = B;
	return (type);
}
