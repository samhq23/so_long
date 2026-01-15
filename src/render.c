/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoque <shoque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 17:21:39 by shoque            #+#    #+#             */
/*   Updated: 2026/01/10 18:08:34 by shoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	load_textures(t_game *g)
{
	g->wall.ptr = mlx_xpm_file_to_image(g->mlx, "textures/wall.xpm",
			&g->wall.w, &g->wall.h);
	g->floor.ptr = mlx_xpm_file_to_image(g->mlx, "textures/floor.xpm",
			&g->floor.w, &g->floor.h);
	g->player.ptr = mlx_xpm_file_to_image(g->mlx, "textures/player.xpm",
			&g->player.w, &g->player.h);
	g->exit.ptr = mlx_xpm_file_to_image(g->mlx, "textures/exit.xpm",
			&g->exit.w, &g->exit.h);
	g->collect.ptr = mlx_xpm_file_to_image(g->mlx, "textures/collect.xpm",
			&g->collect.w, &g->collect.h);
	if (!g->wall.ptr || !g->floor.ptr || !g->player.ptr
		|| !g->exit.ptr || !g->collect.ptr)
		error_exit(g, "failed to load textures");
}

static void	draw_tile(t_game *g, int x, int y)
{
	mlx_put_image_to_window(g->mlx, g->win,
		g->floor.ptr, x * TILE, y * TILE);
	if (g->map[y][x] == '1')
		mlx_put_image_to_window(g->mlx, g->win,
			g->wall.ptr, x * TILE, y * TILE);
	else if (g->map[y][x] == 'C')
		mlx_put_image_to_window(g->mlx, g->win,
			g->collect.ptr, x * TILE, y * TILE);
	else if (g->map[y][x] == 'E')
		mlx_put_image_to_window(g->mlx, g->win,
			g->exit.ptr, x * TILE, y * TILE);
	else if (g->map[y][x] == 'P')
		mlx_put_image_to_window(g->mlx, g->win,
			g->player.ptr, x * TILE, y * TILE);
}

void	draw_map(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (y < g->h)
	{
		x = 0;
		while (x < g->w)
		{
			draw_tile(g, x, y);
			x++;
		}
		y++;
	}
}
