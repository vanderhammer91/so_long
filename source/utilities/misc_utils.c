/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:35:30 by ivanderw          #+#    #+#             */
/*   Updated: 2023/06/09 15:47:40 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <so_long.h>

int	check_flood_map(char **map_copy, t_game m_game)
{
	int	my_y;
	int	my_x;

	fill_check_map(m_game.map_copy, m_game, m_game.player.y, m_game.player.x);
	my_y = m_game.exit.y;
	my_x = m_game.exit.x;
	if ((map_copy[my_y][my_x] != 'F'))
		return (0);
	return (1);
}

void	free_array(char **my_array, int array_height)
{
	int	i;

	i = 0;
	if (!my_array)
		return ;
	while (i < array_height)
	{
		free(my_array[i]);
		i++;
	}
	free(my_array);
}

void	zero_map(t_game *m_game)
{
	int	x_it;
	int	y_it;

	x_it = 0;
	y_it = 0;
	while (y_it < m_game->game_height)
	{
		x_it = 0;
		while (x_it < m_game->game_width)
		{
			m_game->map[y_it][x_it] = '0';
			x_it++;
		}
		y_it++;
	}
}
