/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 13:42:07 by ivanderw          #+#    #+#             */
/*   Updated: 2023/06/08 22:01:08 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	draw_player(t_game *m_game, int y_it, int x_it)
{
	if (m_game->player.f_dir == 'D')
		mlx_put_image_to_window(m_game->mlx, m_game->mlx_win,
			m_game->down_tile, 96 * x_it, 96 * y_it);
	else if (m_game->player.f_dir == 'U')
		mlx_put_image_to_window(m_game->mlx, m_game->mlx_win,
			m_game->up_tile, 96 * x_it, 96 * y_it);
	else if (m_game->player.f_dir == 'R')
		mlx_put_image_to_window(m_game->mlx, m_game->mlx_win,
			m_game->right_tile, 96 * x_it, 96 * y_it);
	else if (m_game->player.f_dir == 'L')
		mlx_put_image_to_window(m_game->mlx, m_game->mlx_win,
			m_game->left_tile, 96 * x_it, 96 * y_it);
	else
		ft_start_exit(m_game, "Map Error\n");
}

void	draw_element(t_game *m_game, int y_it, int x_it)
{
	if (m_game->map[y_it][x_it] == '1')
		mlx_put_image_to_window(m_game->mlx, m_game->mlx_win,
			m_game->wall_tile, 96 * x_it, 96 * y_it);
	if (m_game->map[y_it][x_it] == 'C')
		mlx_put_image_to_window(m_game->mlx, m_game->mlx_win,
			m_game->collectible_tile, 96 * x_it, 96 * y_it);
	if (m_game->map[y_it][x_it] == 'E')
		mlx_put_image_to_window(m_game->mlx, m_game->mlx_win,
			m_game->exit_tile, 96 * x_it, 96 * y_it);
	if (m_game->map[y_it][x_it] == 'X')
		mlx_put_image_to_window(m_game->mlx, m_game->mlx_win,
			m_game->enemy_tile, 96 * x_it, 96 * y_it);
	if (m_game->map[y_it][x_it] == 'P')
		draw_player(m_game, y_it, x_it);
}

void	draw_map(t_game *m_game)
{
	int	x_it;
	int	y_it;
	int	y_max;
	int	x_max;

	y_max = m_game->game_height;
	x_max = m_game->game_width;
	y_it = 0;
	while (y_it < y_max)
	{
		x_it = 0;
		while (x_it < x_max)
		{
			draw_element(m_game, y_it, x_it);
			x_it++;
		}
		y_it++;
	}	
}
