/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 03:59:01 by akefeder          #+#    #+#             */
/*   Updated: 2022/04/16 16:12:13 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	destroy_img(t_file *file)
{
	if (file->bord)
		mlx_destroy_image(file->mlx, file->bord);
	if (file->fond)
		mlx_destroy_image(file->mlx, file->fond);
	if (file->play)
		mlx_destroy_image(file->mlx, file->play);
	if (file->exit)
		mlx_destroy_image(file->mlx, file->exit);
	if (file->col)
		mlx_destroy_image(file->mlx, file->col);
}

void	free_map(t_file *file)
{
	int i;
	
	i = 0;
	while (file->map->map[i]!=NULL)
	{
		free(file->map->map[i]);
		i++;
	}
	free(file->map->map);
}

int gest_close(t_file *file)
{
	destroy_img(file);
	if (file->win)
		mlx_destroy_window(file->mlx, file->win);
	file->win = NULL;
	if(file->mlx)
		mlx_destroy_display(file->mlx);
	if(file->mlx)
		free(file->mlx);
	free_map(file);
	exit(0);
} 