/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoque <shoque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 17:16:56 by shoque            #+#    #+#             */
/*   Updated: 2026/01/15 17:54:48 by shoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft.h"
# include "ft_printf.h"

# define TILE 32

# define KEY_ESC 65307
# define KEY_W   119
# define KEY_A   97
# define KEY_S   115
# define KEY_D   100

typedef struct s_img
{
	void	*ptr;
	int		w;
	int		h;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		w;
	int		total_c;
	int		h;
	int		px;
	int		py;
	int		on_exit;
	int		c_total;
	int		c_left;
	int		e_count;
	int		p_count;
	int		moves;
	t_img	wall;
	t_img	floor;
	t_img	player;
	t_img	exit;
	t_img	collect;
}	t_game;

char	**read_map(const char *path, int *out_h);
int		map_width(char **map);

void	validate_map(t_game *g, char *path);
void	check_chars_and_count(t_game *g);

void	check_reachable(t_game *g);
void	fill_iter(char **m, t_game *g);

void	load_textures(t_game *g);
void	draw_map(t_game *g);

void	try_move(t_game *g, int nx, int ny);
int		on_key(int key, void *param);
int		close_game(void *param);

void	free_map(char **map);
void	error_exit(t_game *g, const char *msg);

#endif