/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:28:58 by akefeder          #+#    #+#             */
/*   Updated: 2022/04/22 00:42:44 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	test_ext(char *av, char *ext, int i)
{
	int	j;

	j = 0;
	while (ext[j] != '\0')
	{
		if (ext[j] != av[i])
			return (ERROR);
		j++;
		i++;
	}
	return (OK);
}

int	test_fich(char *av)
{
	int	len;

	len = ft_strlen(av);
	if (len <= 4)
		return (ERROR);
	if (test_ext(av, ".ber", len - 4) == ERROR)
		return (ERROR);
	return (OK);
}

int	main(int ac, char **av)
{
	t_map	map;
	t_file	file;

	file = (t_file){0};
	prepa_map(&map);
	if (ac != 2 || test_fich(av[1]) == ERROR)
		return (gest_error(&map, 1, &file));
	if (rempli_map(av[1], &map) == ERROR || verif_map(&map))
		return (gest_error(&map, 2, &file));
	file.map = &map;
	if (charg_file(&file) == ERROR)
		return (gest_error(&map, 3, &file));
	affiche_map(&file);
	mlx_hook(file.win, KeyPress, KeyPressMask, gest_moove, &file);
	mlx_hook(file.win, ClientMessage, LeaveWindowMask, gest_close, &file);
	mlx_loop(file.mlx);
	return (0);
}
