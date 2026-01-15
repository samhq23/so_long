/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoque <shoque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 18:06:24 by shoque            #+#    #+#             */
/*   Updated: 2026/01/15 17:14:07 by shoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	check_one_cell(t_game *g, int x, int y)
{
	char	c;

	c = g->map[y][x];
	if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
		error_exit(g, "invalid character in map");
	if (c == 'C')
		g->c_total++;
	if (c == 'E')
		g->e_count++;
	if (c == 'P')
	{
		g->p_count++;
		g->px = x;
		g->py = y;
	}
}

void	check_chars_and_count(t_game *g)
{
	int	x;
	int	y;

	g->c_total = 0;
	g->e_count = 0;
	g->p_count = 0;
	y = 0;
	while (y < g->h)
	{
		x = 0;
		while (x < g->w)
		{
			check_one_cell(g, x, y);
			x++;
		}
		y++;
	}
	g->c_left = g->c_total;
	if (g->p_count != 1 || g->e_count != 1 || g->c_total < 1)
		error_exit(g, "need 1P 1E and at least 1C");
}
