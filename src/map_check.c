/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoque <shoque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 17:21:04 by shoque            #+#    #+#             */
/*   Updated: 2026/01/15 18:33:47 by shoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	check_extension(t_game *g, char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len < 5 || ft_strncmp(path + (len - 4), ".ber", 4) != 0)
		error_exit(g, "map must have .ber extension");
}

static void	check_rectangle(t_game *g)
{
	int	i;

	i = 0;
	while (i < g->h)
	{
		if (g->map[i][0] == '\0')
			error_exit(g, "map has empty line");
		if ((int)ft_strlen(g->map[i]) != g->w)
			error_exit(g, "map must be rectangular");
		i++;
	}
}

static void	check_walls(t_game *g)
{
	int	x;
	int	y;

	x = 0;
	while (x < g->w)
	{
		if (g->map[0][x] != '1' || g->map[g->h - 1][x] != '1')
			error_exit(g, "map must be closed by walls");
		x++;
	}
	y = 0;
	while (y < g->h)
	{
		if (g->map[y][0] != '1' || g->map[y][g->w - 1] != '1')
			error_exit(g, "map must be closed by walls");
		y++;
	}
}

void	validate_map(t_game *g, char *path)
{
	check_extension(g, path);
	check_rectangle(g);
	check_walls(g);
	check_chars_and_count(g);
}
