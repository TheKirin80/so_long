/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:47:53 by akefeder          #+#    #+#             */
/*   Updated: 2022/03/15 20:08:00 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	add_map(t_map *map, char *line)
{
	char	**save;
	int		len;
	int		i;

	len = ft_maplen(map->map);
	save = malloc((len + 1) * sizeof(char *));
	if (save == NULL)
		return (ERROR);
	if (len == 0)
		*save = line;
	else
	{
		i = 0;
		while (map[i] != NULL)
		{
			save[i] = map[i];
			i++;
		}
		save[i] = line;
	}
	free(map->map);
	map = save;
	return (OK);
}

int	rempli_map(char *av, t_map *map)
{
	int		fd;
	char	*line;
    int		ret;

	fd = open(av, O_RDONLY);
	line = NULL;
	while ((ret = get_next_line(fd, &line) > 0))
	{
		if (add_map(map, line) == ERROR)
			return(ERROR);
		line = NULL;
	}
}

