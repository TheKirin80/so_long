/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:28:43 by akefeder          #+#    #+#             */
/*   Updated: 2022/03/19 13:58:16 by akefeder         ###   ########.fr       */
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
	int		len;
	int		maplen;
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
int		ft_maplen(char **s);
int		ft_strlen(char *s);
void	ft_putstr_fd(char *s, int fd);
int		verif_composant(t_map *map);
int		verif_carac(t_map *map, char c);
int		verif_gauche_droite(t_map *map);
int		verif_haut_bas(t_map *map);
int		verif_square(t_map *map);
void	prepa_map(t_map *map);
int		add_map(t_map *map, char *line);
int		rempli_map(char *av, t_map *map);
int		verif_map(t_map *map);
int		gest_error(t_map *map, int code);

#endif