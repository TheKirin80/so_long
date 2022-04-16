/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 00:59:47 by akefeder          #+#    #+#             */
/*   Updated: 2022/04/16 16:23:05 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	left_moove(t_file *file)
{
	if (file->map->map[file->px][file->py - 1] != '1')
	{
		if (file->map->map[file->px][file->py - 1] == 'C')
			(file->map->c)--;
		if (file->map->map[file->px][file->py - 1] == 'E' && file->map->c == 0)
		{
			file->nbr_coup = file->nbr_coup + 1;
			gest_close(file);
		}
		else if (file->map->map[file->px][file->py - 1] != 'E')
		{
			file->map->map[file->px][file->py] = '0';
			file->map->map[file->px][file->py - 1] = 'P';
			file->py = file->py - 1;
			file->nbr_coup = file->nbr_coup + 1;
		}
	}
}

void	right_moove(t_file *file)
{
	if (file->map->map[file->px][file->py + 1] != '1')
	{
		if (file->map->map[file->px][file->py + 1] == 'C')
			(file->map->c)--;
		if (file->map->map[file->px][file->py + 1] == 'E' && file->map->c == 0) 
		{
			file->nbr_coup = file->nbr_coup + 1;
			gest_close(file);
		}
		else if (file->map->map[file->px][file->py + 1] != 'E')
		{
			file->map->map[file->px][file->py] = '0';
			file->map->map[file->px][file->py + 1] = 'P';
			file->py = file->py + 1;
			file->nbr_coup = file->nbr_coup + 1;
		}
	}
}

void	down_moove(t_file *file)
{
	if (file->map->map[file->px + 1][file->py] != '1')
	{
		if (file->map->map[file->px + 1][file->py] == 'C')
			(file->map->c)--;
		if (file->map->map[file->px + 1][file->py] == 'E' && file->map->c == 0) 
		{
			file->nbr_coup = file->nbr_coup + 1;
			gest_close(file);
		}
		else if (file->map->map[file->px + 1][file->py] != 'E')
		{
			file->map->map[file->px][file->py] = '0';
			file->map->map[file->px + 1][file->py] = 'P';
			file->px = file->px + 1;
			file->nbr_coup = file->nbr_coup + 1;
		}
	}	
}

void	up_moove(t_file *file)
{
	if (file->map->map[file->px - 1][file->py] != '1')
	{
		if (file->map->map[file->px - 1][file->py] == 'C')
			(file->map->c)--;
		if (file->map->map[file->px - 1][file->py] == 'E' && file->map->c == 0) 
		{
			file->nbr_coup = file->nbr_coup + 1;
			gest_close(file);
		}
		else if (file->map->map[file->px - 1][file->py] != 'E')
		{
			file->map->map[file->px][file->py] = '0';
			file->map->map[file->px - 1][file->py] = 'P';
			file->px = file->px - 1;
			file->nbr_coup = file->nbr_coup + 1;
		}
	}	
}

int	gest_moove(int keycode, t_file *file)
{
	file->keycode = keycode;
	if (keycode == KEY_A)
		left_moove(file);
	if (keycode == KEY_D)
		right_moove(file);
	if (keycode == KEY_W)
		up_moove(file);
	if (keycode == KEY_S)
		down_moove(file);
	if	(keycode == KEY_ECHAP)
		gest_close(file);
	else
		affiche_map(file);
	return (0);
}