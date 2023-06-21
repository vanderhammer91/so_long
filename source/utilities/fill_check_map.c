/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_check_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 13:53:23 by ivanderw          #+#    #+#             */
/*   Updated: 2023/06/08 21:30:37 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	check_above(char **map, int j, int i, t_game m_game)
{
	if ((j - 1) >= 0 && (map[(j - 1)][i] == '0'
		|| map[(j - 1)][i] == 'C'
		|| map[(j - 1)][i] == 'E'))
	{
		fill_check_map(map, m_game, j - 1, i);
	}
}

void	check_below(char **map, int j, int i, t_game m_game)
{
	if ((j + 1) < m_game.game_height && (map[(j + 1)][i] == '0'
		|| map[(j + 1)][i] == 'C'
		|| map[(j + 1)][i] == 'E'))
	{
		fill_check_map(map, m_game, j + 1, i);
	}
}

void	check_left(char **map, int j, int i, t_game m_game)
{
	if ((i - 1) >= 0 && (map[j][(i - 1)] == '0'
		|| map[j][i - 1] == 'C'
		|| map[j][i - 1] == 'E'))
	{
		fill_check_map(map, m_game, j, i - 1);
	}
}

void	check_right(char **map, int j, int i, t_game m_game )
{
	if ((i + 1) < m_game.game_width && (map[j][(i + 1)] == '0'
		|| map[j][i + 1] == 'C'
		|| map[j][i + 1] == 'E'))
	{
		fill_check_map(map, m_game, j, i + 1);
	}
}

void	fill_check_map(char **map, t_game m_game, int y_coord, int x_coord)
{
	int		i;
	int		j;

	j = 1;
	while (j < m_game.game_height)
	{
		i = 1;
		while (i < m_game.game_width)
		{
			if (i == x_coord && j == y_coord)
			{
				map[j][i] = 'F';
				check_above(map, j, i, m_game);
				check_below(map, j, i, m_game);
				check_left(map, j, i, m_game);
				check_right(map, j, i, m_game);
			}		
			i++;
		}
		j++;
	}
}
