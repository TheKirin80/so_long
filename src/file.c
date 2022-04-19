/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:34:09 by akefeder          #+#    #+#             */
/*   Updated: 2022/04/19 01:49:18 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_img(t_file *file)
{
	int		iw;
	int		ih;

	iw = SIZEPIC;
	ih = SIZEPIC;
	file->bord = mlx_xpm_file_to_image(file->mlx, "./img/bord.xpm", &iw, &ih);
	file->fond = mlx_xpm_file_to_image(file->mlx, "./img/fond.xpm", &iw, &ih);
	file->col = mlx_xpm_file_to_image(file->mlx, "./img/col.xpm", &iw, &ih);
	file->exit = mlx_xpm_file_to_image(file->mlx, "./img/exit.xpm", &iw, &ih);
	file->play = mlx_xpm_file_to_image(file->mlx, "./img/play.xpm", &iw, &ih);
}

int	charg_file(t_file *file)
{
	file->mlx = mlx_init();
	file->win = mlx_new_window(file->mlx, file->map->len * SIZEPIC,
			file->map->maplen * SIZEPIC, "SO_LONG");
	file->nbr_coup = 0;
	load_img(file);
	return (OK);
}

void	affiche_img(int i, int j, char obj, t_file *file)
{
	int		iw;
	int		ih;

	iw = SIZEPIC;
	ih = SIZEPIC;
	if (obj == '1')
		mlx_put_image_to_window(file->mlx, file->win, file->bord,
			j * ih, i * iw);
	if (obj == '0')
		mlx_put_image_to_window(file->mlx, file->win, file->fond,
			j * ih, i * iw);
	if (obj == 'C')
		mlx_put_image_to_window(file->mlx, file->win, file->col,
			j * ih, i * iw);
	if (obj == 'E')
		mlx_put_image_to_window(file->mlx, file->win, file->exit,
			j * ih, i * iw);
	if (obj == 'P')
	{
		file->px = i;
		file->py = j;
		mlx_put_image_to_window(file->mlx, file->win, file->play,
			j * ih, i * iw);
	}
}

void	affiche_map(t_file *file)
{
	int	i;
	int	j;

	i = 0;
	while (file->map->map[i] != NULL)
	{
		j = 0;
		while (file->map->map[i][j] != '\0')
		{
			affiche_img(i, j, file->map->map[i][j], file);
			j++;
		}
		i++;
	}
}
