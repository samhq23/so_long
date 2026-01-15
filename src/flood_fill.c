/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoque <shoque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 17:21:20 by shoque            #+#    #+#             */
/*   Updated: 2026/01/15 17:28:38 by shoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static char	**dup_map(t_game *g)
{
	char	**cpy;
	int		i;

	cpy = (char **)ft_calloc(g->h + 1, sizeof(char *));
	if (!cpy)
		return (NULL);
	i = 0;
	while (i < g->h)
	{
		cpy[i] = ft_strdup(g->map[i]);
		if (!cpy[i])
		{
			free_map(cpy);
			return (NULL);
		}
		i++;
	}
	return (cpy);
}

typedef struct s_reach
{
	int	exit_ok;
	int	c_reached;
}	t_reach;

static t_reach	reach_init(void)
{
	t_reach	r;

	r.exit_ok = 0;
	r.c_reached = 0;
	return (r);
}

static t_reach	reach_scan(t_game *g, char **m)
{
	t_reach	r;
	int		x;
	int		y;

	r = reach_init();
	y = 0;
	while (y < g->h)
	{
		x = 0;
		while (m[y][x])
		{
			if (g->map[y][x] == 'E' && m[y][x] == 'V')
				r.exit_ok = 1;
			if (g->map[y][x] == 'C' && m[y][x] == 'V')
				r.c_reached++;
			x++;
		}
		y++;
	}
	return (r);
}

void	check_reachable(t_game *g)
{
	char	**m;
	t_reach	r;

	m = dup_map(g);
	if (!m)
		error_exit(g, "malloc failed");
	fill_iter(m, g);
	r = reach_scan(g, m);
	free_map(m);
	if (!r.exit_ok || r.c_reached != g->c_total)
		error_exit(g, "map must have valid path to all C and E");
}
