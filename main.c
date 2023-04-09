/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:05:40 by crepou            #+#    #+#             */
/*   Updated: 2023/03/31 17:00:27 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	int		fd;
	char	*retval;

	if (argc != 2)
		return (not_valid_arguments(), -1);
	fd = open(argv[1], 0);
	if (fd < 0)
		return (not_valid_fd(), -1);
	retval = so_long(fd);
	if (ft_strncmp(retval, "Error", 5) == 0)
	{
		ft_printf(retval);
		return (-1);
	}
	ft_printf(retval);
	system("leaks solong");
	return (0);
}
