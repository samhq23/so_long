/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoque <shoque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 17:20:41 by shoque            #+#    #+#             */
/*   Updated: 2026/01/15 18:43:02 by shoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static char	*join_and_free(char *s1, char *s2)
{
	char	*res;

	if (!s1)
		return (ft_strdup(s2));
	res = ft_strjoin(s1, s2);
	free(s1);
	return (res);
}

static char	*read_file(int fd)
{
	char	buf[1024];
	int		r;
	char	*all;

	all = NULL;
	while (1)
	{
		r = read(fd, buf, 1023);
		if (r <= 0)
			break ;
		buf[r] = '\0';
		all = join_and_free(all, buf);
		if (!all)
			return (NULL);
	}
	if (r < 0)
	{
		free(all);
		return (NULL);
	}
	return (all);
}

static int	has_blank_line(const char *s)
{
	int	i;

	i = 0;
	if (!s || !s[0])
		return (1);
	while (s[i])
	{
		if (s[i] == '\n' && s[i + 1] == '\n')
			return (1);
		i++;
	}
	if (i > 0 && s[i - 1] == '\n')
		return (1);
	return (0);
}

static char	**split_map_or_null(char *all, int *out_h)
{
	char	**map;

	if (!all || has_blank_line(all))
		return (NULL);
	map = ft_split(all, '\n');
	if (!map)
		return (NULL);
	*out_h = 0;
	while (map[*out_h])
		(*out_h)++;
	if (*out_h == 0)
	{
		free_map(map);
		return (NULL);
	}
	return (map);
}

char	**read_map(const char *path, int *out_h)
{
	int		fd;
	char	*all;
	char	**map;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	all = read_file(fd);
	close(fd);
	if (!all)
		return (NULL);
	map = split_map_or_null(all, out_h);
	free(all);
	return (map);
}

int	map_width(char **map)
{
	if (!map || !map[0])
		return (0);
	return (ft_strlen(map[0]));
}
