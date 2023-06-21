/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 13:26:41 by ivanderw          #+#    #+#             */
/*   Updated: 2023/06/08 21:09:49 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	get_map_height_from_argv(char *str)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (1);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

int	get_map_height_from_arr(char **m_map)
{
	int	i;

	i = 0;
	while (m_map[i])
		i++;
	return (i);
}

void	print_map(t_game *m_game)
{
	int	i;
	int	j;
	int	height;
	int	width;

	height = m_game->game_height;
	width = m_game->game_width;
	i = 0;
	j = 0;
	while (j < height)
	{
		i = 0;
		while (i < width)
		{
			ft_putchar(m_game->map[j][i]);
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}

int	set_map(char **argv, t_game *game)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (0);
	}
	line = get_next_line(fd);
	i = 0;
	while (line != NULL)
	{
		game->map[i] = ft_strjoin("", line);
		if (!game->map[i])
			return (1);
		free(line);
		line = get_next_line(fd);
			i++;
	}
	close(fd);
	return (1);
}

int	copy_map(t_game *game, char **map_copy)
{
	int	i;

	i = 0;
	while (i < game->game_height)
	{
		map_copy[i] = ft_strdup(game->map[i]);
		if (!map_copy[i])
			return (0);
		i++;
	}
	return (1);
}
