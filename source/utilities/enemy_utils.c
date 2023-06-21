/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:49:44 by ivanderw          #+#    #+#             */
/*   Updated: 2023/06/08 21:31:14 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	set_enemy_coords(t_game *m_game, int y_set, int x_set)
{
	m_game->enemy.y = y_set;
	m_game->enemy.x = x_set;
}

void	set_enemy_state(t_game *m_game)
{
	if (is_clear_above(m_game, m_game->exit.y, m_game->exit.x))
		set_enemy_coords(m_game, (m_game->exit.y - 1), m_game->exit.x);
	else if (is_clear_below(m_game, m_game->exit.y, m_game->exit.x))
		set_enemy_coords(m_game, (m_game->exit.y + 1), m_game->exit.x);
	else if (is_clear_left(m_game, m_game->exit.y, m_game->exit.x))
		set_enemy_coords(m_game, m_game->exit.y, (m_game->exit.x - 1));
	else if (is_clear_right(m_game, m_game->exit.y, m_game->exit.x))
		set_enemy_coords(m_game, m_game->exit.y, (m_game->exit.x + 1));
	else
		ft_start_exit(m_game, "Tile check around exit.\n");
	m_game->map[m_game->enemy.y][m_game->enemy.x] = 'X';
}

void	enemy_turn_right(t_game *m_game)
{
	if (m_game->enemy.f_dir == 'R')
		m_game->enemy.f_dir = 'D';
	else if (m_game->enemy.f_dir == 'D')
		m_game->enemy.f_dir = 'L';
	else if (m_game->enemy.f_dir == 'L')
		m_game->enemy.f_dir = 'U';
	else if (m_game->enemy.f_dir == 'U')
		m_game->enemy.f_dir = 'R';
	else
		ft_printf("enemy turn right error!\n");
}

void	enemy_turn_left(t_game *m_game)
{
	if (m_game->enemy.f_dir == 'R')
		m_game->enemy.f_dir = 'U';
	else if (m_game->enemy.f_dir == 'U')
		m_game->enemy.f_dir = 'L';
	else if (m_game->enemy.f_dir == 'L')
		m_game->enemy.f_dir = 'D';
	else if (m_game->enemy.f_dir == 'D')
		m_game->enemy.f_dir = 'R';
	else
		ft_printf("enemy turn left error!\n");
}
