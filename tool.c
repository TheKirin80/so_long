/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:54:58 by akefeder          #+#    #+#             */
/*   Updated: 2022/03/18 17:09:09 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr_fd(char *s, int fd)
{
	int		len;

	if (s != NULL && fd >= 0)
	{
		len = ft_strlen(s);
		write(fd, s, len);
	}
}

int	ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_maplen(char **s)
{
	int		i;

	i = 0;
	if (s == NULL)
		return (i);
	while (s[i] != NULL)
		i++;
	return (i);
}

