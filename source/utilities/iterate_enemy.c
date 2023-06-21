/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:32:43 by ivanderw          #+#    #+#             */
/*   Updated: 2023/06/09 14:11:51 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	iterate_enemy_right(t_game *m_game)
{
	if (m_game->map[m_game->enemy.y][m_game->enemy.x + 1] == 'P')
		ft_start_exit(m_game, "YOU DIED!\n");
	else if (is_clear_right(m_game, m_game->enemy.y, m_game->enemy.x))
	{
		m_game->map[m_game->enemy.y][m_game->enemy.x] = '0';
		m_game->map[m_game->enemy.y][m_game->enemy.x + 1] = 'X';
		m_game->enemy.x += 1;
	}		
	else if (is_clear_below(m_game, m_game->enemy.y, m_game->enemy.x))
		enemy_turn_right(m_game);
	else
		enemy_turn_left (m_game);
}

void	iterate_enemy_left(t_game *m_game)
{
	if (m_game->map[m_game->enemy.y][m_game->enemy.x - 1] == 'P')
		ft_start_exit(m_game, "YOU DIED!\n");
	else if (is_clear_left(m_game, m_game->enemy.y, m_game->enemy.x))
	{
		m_game->map[m_game->enemy.y][m_game->enemy.x] = '0';
		m_game->map[m_game->enemy.y][m_game->enemy.x - 1] = 'X';
		m_game->enemy.x -= 1;
	}	
	else if (is_clear_above(m_game, m_game->enemy.y, m_game->enemy.x)
		&& m_game->steps % 2 == 0)
		enemy_turn_right(m_game);
	else
		enemy_turn_left(m_game);
}

void	iterate_enemy_down(t_game *m_game)
{
	if (m_game->map[m_game->enemy.y + 1][m_game->enemy.x] == 'P')
		ft_start_exit(m_game, "YOU DIED!\n");
	else if (is_clear_below(m_game, m_game->enemy.y, m_game->enemy.x))
	{
		m_game->map[m_game->enemy.y][m_game->enemy.x] = '0';
		m_game->map[m_game->enemy.y + 1][m_game->enemy.x] = 'X';
		m_game->enemy.y += 1;
	}		
	else if (is_clear_left(m_game, m_game->enemy.y, m_game->enemy.x)
		&& m_game->steps % 2 == 0)
		enemy_turn_right(m_game);
	else
		enemy_turn_left (m_game);
}

void	iterate_enemy_up(t_game *m_game)
{
	if (m_game->map[m_game->enemy.y - 1][m_game->enemy.x] == 'P')
		ft_start_exit(m_game, "YOU DIED!\n");
	else if (is_clear_above(m_game, m_game->enemy.y, m_game->enemy.x))
	{
		m_game->map[m_game->enemy.y][m_game->enemy.x] = '0';
		m_game->map[m_game->enemy.y - 1][m_game->enemy.x] = 'X';
		m_game->enemy.y -= 1;
	}
	else if (is_clear_right(m_game, m_game->enemy.y, m_game->enemy.x))
		enemy_turn_right(m_game);
	else
		enemy_turn_left(m_game);
}

void	iterate_enemy_location(t_game *m_game)
{
	if (m_game->enemy.f_dir == 'R')
		iterate_enemy_right(m_game);
	else if (m_game->enemy.f_dir == 'D')
		iterate_enemy_down(m_game);
	else if (m_game->enemy.f_dir == 'L')
		iterate_enemy_left(m_game);
	else if (m_game->enemy.f_dir == 'U')
		iterate_enemy_up(m_game);
}
