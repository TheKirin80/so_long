/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:28:43 by akefeder          #+#    #+#             */
/*   Updated: 2022/04/18 22:09:56 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# define ERROR -1
# define OK 0
# define END 0
# define NOTFIND 0
# define FIND 1
# define CONTINUE 1
# define SIZEPIC 36
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define KEY_ECHAP 65307

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

typedef struct s_file	t_file;
struct s_file
{
	void	*mlx;
	void	*win;
	t_map	*map; 
	int		px;
	int		py;
	int		nbr_coup;
	int		keycode;
	void	*bord;
	void	*fond;
	void	*col;
	void	*exit;
	void	*play;
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
int		charg_file(t_file *file);
void	affiche_map(t_file *file);
void	reload(t_file *file, int keycode);
int		gest_moove(int keycode, t_file *file);
int		gest_close(t_file *file);
void	ft_putnbr(int i);
void	affichage(t_file *file, int i);
#endif