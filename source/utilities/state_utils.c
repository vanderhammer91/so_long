/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:33:48 by ivanderw          #+#    #+#             */
/*   Updated: 2023/06/09 15:34:09 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	set_m_game_state(t_game *m_game, char **argv)
{
	m_game->wall_path = "./images/wall_tile.xpm";
	m_game->collectible_path = "./images/collectible_frames/col_01.xpm";
	m_game->exit_path = "./images/e_frames/e_frame00.xpm";
	m_game->down_path = "./images/down_tile.xpm";
	m_game->up_path = "./images/up_tile.xpm";
	m_game->left_path = "./images/left_tile.xpm";
	m_game->right_path = "./images/right_tile.xpm";
	m_game->enemy_path = "./images/enemy_tile.xpm";
	m_game->map_copy = NULL;
	m_game->map = NULL;
	m_game->steps = 0;
	m_game->collectible_state = 0;
	m_game->has_started = 0;
	m_game->player.f_dir = 'D';
	m_game->tile_width = 0;
	m_game->tile_height = 0;
	m_game->enemy_state = 0;
	m_game->enemy.f_dir = 'R';
	m_game->exit_state = 0;
	m_game->exit_frame_counter = 0;
	m_game->game_height = get_map_height_from_argv(argv[1]);
	m_game->splash_state = 0;
}

void	set_tile_states(t_game *m_game)
{
	m_game->wall_tile = mlx_xpm_file_to_image(m_game->mlx,
			m_game->wall_path, &(m_game->tile_width),
			&(m_game->tile_height));
	m_game->collectible_tile = mlx_xpm_file_to_image(m_game->mlx,
			m_game->collectible_path, &(m_game->tile_width),
			&(m_game->tile_height));
	m_game->exit_tile = mlx_xpm_file_to_image(m_game->mlx,
			m_game->exit_path, &(m_game->tile_width),
			&(m_game->tile_height));
	m_game->left_tile = mlx_xpm_file_to_image(m_game->mlx,
			m_game->left_path, &(m_game->tile_width),
			&(m_game->tile_height));
	m_game->right_tile = mlx_xpm_file_to_image(m_game->mlx,
			m_game->right_path, &(m_game->tile_width),
			&(m_game->tile_height));
	m_game->up_tile = mlx_xpm_file_to_image(m_game->mlx,
			m_game->up_path, &(m_game->tile_width),
			&(m_game->tile_height));
	m_game->down_tile = mlx_xpm_file_to_image(m_game->mlx,
			m_game->down_path, &(m_game->tile_width),
			&(m_game->tile_height));
	m_game->enemy_tile = mlx_xpm_file_to_image(m_game->mlx,
			m_game->enemy_path, &(m_game->tile_width),
			&(m_game->tile_height));
}
