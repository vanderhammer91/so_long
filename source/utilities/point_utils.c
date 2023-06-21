/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:25:46 by ivanderw          #+#    #+#             */
/*   Updated: 2023/06/08 20:38:27 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	set_point_data(int y_it, int x_it, t_point *m_point)
{
	m_point->x = x_it;
	m_point->y = y_it;
}

void	set_coordinates(t_game *m_game)
{
	int	x_it;
	int	y_it;

	y_it = 0;
	while (y_it < m_game->game_height)
	{
		x_it = 0;
		while (x_it < m_game->game_width)
		{
			if (m_game->map[y_it][x_it] == 'P')
				set_point_data(y_it, x_it, &m_game->player);
			if (m_game->map[y_it][x_it] == 'E')
			{
				m_game->exit.x = x_it;
				m_game->exit.y = y_it;
			}
			x_it++;
		}
		y_it++;
	}	
}
