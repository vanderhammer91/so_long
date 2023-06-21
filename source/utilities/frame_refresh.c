/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_refresh.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 20:05:15 by ivanderw          #+#    #+#             */
/*   Updated: 2023/06/09 14:14:55 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	splash_refresh(t_game *m_game)
{
	if (m_game->frame >= 8)
	{
		m_game->frame = 0;
		m_game->splash_state++;
		if (m_game->splash_state > 13)
			m_game->splash_state = 0;
	}
	m_game->splash_path = m_game->s_frame[m_game->splash_state];
	m_game->splash_tile = mlx_xpm_file_to_image(m_game->mlx,
			m_game->splash_path, &(m_game->tile_width), &(m_game->tile_height));
	mlx_put_image_to_window(m_game->mlx, m_game->mlx_win,
		m_game->splash_tile, 0, 0);
}

void	game_refresh(t_game *m_game)
{
	if (m_game->frame >= 8)
	{
		m_game->frame = 0;
		m_game->enemy_state++;
		m_game->collectible_state++;
		if ((m_game->exit_state > 0 && m_game->frame % 2 == 0)
			&& m_game->exit_state < 7)
		{
			m_game->exit_state++;
			m_game->exit_path = m_game->e_frame[m_game->exit_state];
			m_game->exit_tile = mlx_xpm_file_to_image(m_game->mlx,
					m_game->exit_path, &(m_game->tile_width),
					&(m_game->tile_height));
		}
		if (m_game->collectible_state > 15)
			m_game->collectible_state = 0;
		m_game->collectible_path = m_game->c_frame[m_game->collectible_state];
		m_game->collectible_tile = mlx_xpm_file_to_image(m_game->mlx,
				m_game->collectible_path, &(m_game->tile_width),
				&(m_game->tile_height));
		if (m_game->enemy_state % 2 == 0)
			iterate_enemy_location(m_game);
	}
	refresh_map(m_game);
}

int	frame_refresh(t_game *m_game)
{
	m_game->frame++;
	if (m_game->has_started == 0)
		splash_refresh(m_game);
	if (m_game->has_started == 1)
		game_refresh(m_game);
	if (m_game->has_started >= 2)
	{
		m_game->exit_frame_counter++;
		if (m_game->exit_frame_counter >= 25000)
		{
			mlx_destroy_window(m_game->mlx, m_game->mlx_win);
			free_array(m_game->map_copy, m_game->game_height);
			free_array(m_game->map, m_game->game_height);
			exit(1);
		}
	}
	return (0);
}
