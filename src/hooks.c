/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoque <shoque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 17:22:05 by shoque            #+#    #+#             */
/*   Updated: 2026/01/10 18:08:56 by shoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	close_game(void *param)
{
	error_exit((t_game *)param, NULL);
	return (0);
}

int	on_key(int key, void *param)
{
	t_game	*g;

	g = (t_game *)param;
	if (key == KEY_ESC)
		close_game(g);
	else if (key == KEY_W)
		try_move(g, g->px, g->py - 1);
	else if (key == KEY_S)
		try_move(g, g->px, g->py + 1);
	else if (key == KEY_A)
		try_move(g, g->px - 1, g->py);
	else if (key == KEY_D)
		try_move(g, g->px + 1, g->py);
	return (0);
}
