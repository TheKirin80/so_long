/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:57:09 by akefeder          #+#    #+#             */
/*   Updated: 2022/03/19 15:41:22 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	gest_error_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->map != NULL)
	{
		while (map->map[i] != NULL)
		{
			free(map->map[i]);
			i++;
		}
		free(map->map);
	}
}

int	gest_error(t_map *map, int code)
{
	if (code == 1)
		ft_putstr_fd("Error : false parameters", 2);
	else if (code == 2)
	{
		gest_error_map(map);
		ft_putstr_fd("Error : map don't follow the rules", 2);
	}
	return (1);
}
