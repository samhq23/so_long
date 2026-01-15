/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoque <shoque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 17:53:36 by shoque            #+#    #+#             */
/*   Updated: 2026/01/15 17:24:16 by shoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

typedef struct s_pt
{
	int	x;
	int	y;
}	t_pt;

typedef struct s_ff
{
	char	**m;
	t_pt	*st;
	int		top;
	int		cap;
	int		w;
	int		h;
}	t_ff;

static t_pt	pt(int x, int y)
{
	t_pt	p;

	p.x = x;
	p.y = y;
	return (p);
}

static void	push(t_ff *f, t_pt p)
{
	if (f->top >= f->cap)
		return ;
	f->st[f->top++] = p;
}

static void	visit(t_ff *f, t_pt p)
{
	char	c;

	if (p.x < 0 || p.y < 0 || p.x >= f->w || p.y >= f->h)
		return ;
	c = f->m[p.y][p.x];
	if (c == '1' || c == 'V' || c == '\0')
		return ;
	if (c != '0' && c != 'C' && c != 'E' && c != 'P')
		return ;
	f->m[p.y][p.x] = 'V';
	push(f, pt(p.x + 1, p.y));
	push(f, pt(p.x - 1, p.y));
	push(f, pt(p.x, p.y + 1));
	push(f, pt(p.x, p.y - 1));
}

void	fill_iter(char **m, t_game *g)
{
	t_ff	f;
	t_pt	p;

	f.m = m;
	f.w = g->w;
	f.h = g->h;
	f.top = 0;
	f.cap = g->w * g->h;
	f.st = malloc(sizeof(t_pt) * f.cap);
	if (!f.st)
		error_exit(g, "malloc failed");
	push(&f, pt(g->px, g->py));
	while (f.top > 0)
	{
		p = f.st[--f.top];
		visit(&f, p);
	}
	free(f.st);
}
