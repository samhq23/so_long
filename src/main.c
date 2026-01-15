/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoque <shoque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 17:22:16 by shoque            #+#    #+#             */
/*   Updated: 2026/01/10 18:54:22 by shoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	init_map(t_game *g, char *path)
{
	g->map = read_map(path, &g->h);
	if (!g->map || g->h == 0)
		error_exit(g, "failed to read map");
	g->w = map_width(g->map);
	if (g->w == 0)
		error_exit(g, "empty map");
	validate_map(g, path);
	check_reachable(g);
}

static void	init_mlx(t_game *g)
{
	g->mlx = mlx_init();
	if (!g->mlx)
		error_exit(g, "mlx_init failed");
	g->win = mlx_new_window(g->mlx, g->w * TILE, g->h * TILE, "so_long");
	if (!g->win)
		error_exit(g, "mlx_new_window failed");
	load_textures(g);
	draw_map(g);
}

int	main(int ac, char **av)
{
	t_game	g;

	ft_bzero(&g, sizeof(t_game));
	if (ac != 2)
		error_exit(&g, "usage: ./so_long map.ber");
	init_map(&g, av[1]);
	init_mlx(&g);
	mlx_key_hook(g.win, on_key, &g);
	mlx_hook(g.win, 17, 0, close_game, &g);
	mlx_loop(g.mlx);
	return (0);
}
