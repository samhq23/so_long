/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoque <shoque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 17:20:20 by shoque            #+#    #+#             */
/*   Updated: 2026/01/15 17:35:42 by shoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	cleanup_mlx(t_game *g)
{
	if (!g || !g->mlx)
		return ;
	if (g->wall.ptr)
		mlx_destroy_image(g->mlx, g->wall.ptr);
	if (g->floor.ptr)
		mlx_destroy_image(g->mlx, g->floor.ptr);
	if (g->player.ptr)
		mlx_destroy_image(g->mlx, g->player.ptr);
	if (g->exit.ptr)
		mlx_destroy_image(g->mlx, g->exit.ptr);
	if (g->collect.ptr)
		mlx_destroy_image(g->mlx, g->collect.ptr);
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	mlx_destroy_display(g->mlx);
	free(g->mlx);
	g->mlx = NULL;
}

void	error_exit(t_game *g, const char *msg)
{
	if (msg)
	{
		write(2, "Error\n", 6);
		write(2, msg, ft_strlen(msg));
		write(2, "\n", 1);
	}
	if (g)
	{
		cleanup_mlx(g);
		free_map(g->map);
		g->map = NULL;
	}
	exit(1);
}
