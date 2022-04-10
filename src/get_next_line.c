/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:04:35 by akefeder          #+#    #+#             */
/*   Updated: 2022/04/09 17:10:49 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	prepa_tmp(char **tmp)
{
	if (!*tmp)
	{
		if (!(*tmp = (char *)malloc(sizeof(char))))
			return (ERROR);
		(*tmp)[0] = '\0';
	}
	return (OK);
}

int	insert_static(char **tmp, int fd)
{
	char		buf[BUFFER_SIZE + 1];
	char		*copy;
	ssize_t		nb_car_lu;

	nb_car_lu = 0;
	while ((nb_car_lu = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[nb_car_lu] = '\0';
		copy = *tmp;
		*tmp = ft_strjoin(copy, buf);
		free(copy);
		copy = NULL;
		if (ft_backslash_n(*tmp) == FIND)
			break ;
	}
	return (nb_car_lu);
}

int	insert_line(char **tmp, char **line)
{
	char	*copy;
	int		i;
	int		j;

	i = ft_strclen(*tmp, '\n');
	if (!(copy = (char *)malloc((i + 1) * sizeof(char))))
		return (ERROR);
	j = 0;
	while (j < i)
	{
		copy[j] = (*tmp)[j];
		j++;
	}
	copy[j] = '\0';
	*line = copy;
	if ((*tmp)[i] == '\n')
		i++;
	return (i);
}

int	epuration_tmp(char **tmp, int i)
{
	char	*copy;
	int		j;

	j = 0;
	if (!(copy = (char *)malloc((ft_strclen(*tmp, '\0') + 1)
		* sizeof(char))))
		return (ERROR);
	while ((*tmp)[i] != '\0')
	{
		copy[j] = (*tmp)[i];
		i++;
		j++;
	}
	copy[j] = '\0';
	free(*tmp);
	*tmp = NULL;
	*tmp = copy;
	return (OK);
}

int	get_next_line(int fd, char **line)
{
	static char		*tmp;
	int				i;
	int				nb_car_lu;
	int				flag;

	if (((flag = 0) == 0) && (line == 0 || BUFFER_SIZE == 0))
		return (ERROR);
	if (prepa_tmp(&tmp) == ERROR)
		return (ERROR);
	if ((nb_car_lu = insert_static(&tmp, fd)) == ERROR)
		return (ERROR);
	if (ft_backslash_n(tmp) == NOTFIND)
		flag = 1;
	if ((i = insert_line(&tmp, line)) == ERROR)
		return (ERROR);
	if (epuration_tmp(&tmp, i) == ERROR)
		return (ERROR);
	if (flag == 1)
	{
		free(tmp);
		tmp = NULL;
		return (END);
	}
	else
		return (CONTINUE);
}
