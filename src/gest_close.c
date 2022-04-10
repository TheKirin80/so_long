/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 03:59:01 by akefeder          #+#    #+#             */
/*   Updated: 2022/04/10 04:02:26 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int gest_close(int keycode, t_file *file)
{
	printf("%i\n", keycode);
	mlx_destroy_window(file->mlx, file->win);
	return(0);
}