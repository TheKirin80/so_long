/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:28:43 by akefeder          #+#    #+#             */
/*   Updated: 2022/03/15 20:12:47 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# define ERROR -1
# define OK 0
# define END 0
# define NOTFIND 0
# define FIND 1
# define CONTINUE 1

typedef struct s_map	t_map;
struct s_map
{
	char	**map;
	int		p;
	int		e;
	int		c;
};

typedef struct s_lect	t_lect;
struct	s_lect
{
	int		fd;
	char	*tmp;
};

char	*ft_strjoin(char *s1, char *s2);
int		ft_backslash_n(char *str);
int		get_next_line(int fd, char **line);
int		ft_strclen(char *str, char c);
char	*ft_strdup(char *s);


#endif