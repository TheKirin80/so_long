/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:47:53 by akefeder          #+#    #+#             */
/*   Updated: 2022/04/20 02:35:53 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	prepa_map(t_map *map)
{
	map->map = NULL;
	map->p = 0;
	map->e = 0;
	map->c = 0;
	map->len = 0;
	map->maplen = 0;
}

void	add_map_help(t_map *map, char *line, char **save)
{
	int	i;

	i = 0;
	while (map->map[i] != NULL)
	{
		save[i] = map->map[i];
		i++;
	}
	save[i] = line;
	save[i + 1] = NULL;
}

int	add_map(t_map *map, char *line)
{
	char	**save;
	int		len;

	len = ft_maplen(map->map);
	save = malloc((len + 2) * sizeof(char *));
	if (save == NULL)
	{
		free(line);
		return (ERROR);
	}
	if (len == 0)
	{
		save[0] = line;
		save[1] = NULL;
	}
	else
		add_map_help(map, line, save);
	free(map->map);
	map->map = save;
	return (OK);
}

int	rempli_map_help(int *fd, char *av)
{
	*fd = open(av, O_RDONLY);
	if (*fd == -1)
		return (ERROR);
	return (OK);
}

int	rempli_map(char *av, t_map *map)
{
	int		fd;
	char	*line;
	int		ret;

	if (rempli_map_help(&fd, av) == ERROR)
		return (ERROR);
	line = NULL;
	ret = get_next_line(fd, &line);
	while (ret > 0)
	{
		if (add_map(map, line) == ERROR)
			return (ERROR);
		line = NULL;
		ret = get_next_line(fd, &line);
	}
	if (ret == -1)
	{
		free(line);
		return (ERROR);
	}
	else
		if (add_map(map, line) == ERROR)
			return (ERROR);
	line = NULL;
	return (OK);
}
