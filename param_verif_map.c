/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_verif_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:25:08 by akefeder          #+#    #+#             */
/*   Updated: 2022/03/19 15:39:46 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verif_square(t_map *map)
{
	int	i;

	if (map->len < 3)
		return (ERROR);
	if (map->maplen < 3)
		return (ERROR);
	i = 1;
	while (map->map[i] != NULL)
	{
		if (ft_strlen(map->map[i]) != map->len)
			return (ERROR);
		i++;
	}
	return (OK);
}

int	verif_haut_bas(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[0][i] != '\0')
	{
		if (map->map[0][i] != '1')
			return (ERROR);
		i++;
	}
	i = 0;
	while (map->map[map->maplen - 1][i] != '\0')
	{
		if (map->map[map->maplen - 1][i] != '1')
			return (ERROR);
		i++;
	}
	return (OK);
}

int	verif_gauche_droite(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i] != NULL)
	{
		if (map->map[i][0] != '1')
			return (ERROR);
		i++;
	}
	i = 0;
	while (map->map[i] != NULL)
	{
		if (map->map[i][map->len - 1] != '1')
			return (ERROR);
		i++;
	}
	return (OK);
}

int	verif_carac(t_map *map, char c)
{
	if (c == '1' || c == '0')
		return (OK);
	if (c == 'P')
	{
		map->p = map->p + 1;
		return (OK);
	}
	if (c == 'E')
	{
		map->e = map->e + 1;
		return (OK);
	}
	if (c == 'C')
	{
		map->c = map->c + 1;
		return (OK);
	}
	return (ERROR);
}

int	verif_composant(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i] != NULL)
	{
		j = 0;
		while (map->map[i][j] != '\0')
		{
			if (verif_carac(map, map->map[i][j]) == ERROR)
				return (ERROR);
			j++;
		}
		i++;
	}
	if (map->p != 1 || map->c == 0 || map->e == 0)
		return (ERROR);
	return (OK);
}
