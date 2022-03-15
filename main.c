/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:28:58 by akefeder          #+#    #+#             */
/*   Updated: 2022/03/15 18:10:39 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	rempli_map(char *av, t_map *map)
{
	int		fd;
	char	*line;
    int		ret;

	fd = open(av, O_RDONLY);
	line = NULL;
	while ((ret = get_next_line(fd, &line) > 0))
	{
		i++;
		add_map(map, line);
		line = NULL;
	}
}
int main(int ac, char **av)
{
	t_map	map;
	if (ac > 2)
	{
		ft_putstr("Error");
		return (1);
	}
	if (rempli_map(av[1], &map) == 1)
	{
		gest_error(&map);
		return(1);
	}
}
