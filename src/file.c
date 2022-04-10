/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:34:09 by akefeder          #+#    #+#             */
/*   Updated: 2022/04/10 03:58:20 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	charg_file(t_file *file)
{
	file->mlx = mlx_init();
	file->win = mlx_new_window(file->mlx, file->map->len * SIZEPIC,
		file->map->maplen * SIZEPIC, "SO_LONG");
	file->nbr_coup = 0;
	
	return (OK);

}

void	affiche_img(int i, int j, char obj, t_file *file)
{
	void	*img;
	int		iw;
	int		ih;

	iw = SIZEPIC;
	ih = SIZEPIC;
	if (obj == '1')
		img = mlx_xpm_file_to_image(file->mlx, "./img/bord.xpm", &iw, &ih);
	if (obj == '0')
		img = mlx_xpm_file_to_image(file->mlx, "./img/fond.xpm", &iw, &ih);
	if (obj == 'C')
		img = mlx_xpm_file_to_image(file->mlx, "./img/Collectible.xpm", &iw, &ih);
	if (obj == 'E')
		img = mlx_xpm_file_to_image(file->mlx, "./img/exit.xpm", &iw, &ih);
	if (obj == 'P')
	{
		file->px = i;
		file->py = j;
		img = mlx_xpm_file_to_image(file->mlx, "./img/Perso.xpm", &iw, &ih);
	}
	mlx_put_image_to_window(file->mlx, file->win, img, j * ih, i * iw );
	free (img);
}

void	affiche_map(t_file *file)
{
	int	i;
	int j;

	i = 0;
	while (file->map->map[i] != NULL)
	{
		j = 0;
		while (file->map->map[i][j] != '\0')
		{
			//printf("%c", file->map->map[i][j]);
			affiche_img(i, j, file->map->map[i][j], file);
			j++;
		}
		//printf("\n");
		i++;
	}
}

void	reload(t_file *file, int keycode)
{
	printf("moove : %i; px = %i; py = %i\n", keycode, file->px, file->py);
	
	affiche_map(file);
}