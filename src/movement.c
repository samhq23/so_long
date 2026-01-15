/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoque <shoque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 17:21:53 by shoque            #+#    #+#             */
/*   Updated: 2026/01/10 18:08:46 by shoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	print_moves(t_game *g)
{
	ft_printf("moves: %d\n", g->moves);
}

static void	leave_tile(t_game *g)
{
	if (g->on_exit)
		g->map[g->py][g->px] = 'E';
	else
		g->map[g->py][g->px] = '0';
}

void	try_move(t_game *g, int nx, int ny)
{
	if (nx < 0 || ny < 0 || nx >= g->w || ny >= g->h)
		return ;
	if (g->map[ny][nx] == '1')
		return ;
	if (g->map[ny][nx] == 'E' && g->c_left != 0)
		return ;
	if (g->map[ny][nx] == 'C')
		g->c_left--;
	if (g->map[ny][nx] == 'E' && g->c_left == 0)
	{
		g->moves++;
		print_moves(g);
		close_game(g);
		return ;
	}
	leave_tile(g);
	g->on_exit = (g->map[ny][nx] == 'E');
	g->px = nx;
	g->py = ny;
	g->map[g->py][g->px] = 'P';
	g->moves++;
	print_moves(g);
	draw_map(g);
}
