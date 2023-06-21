/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:29:30 by ivanderw          #+#    #+#             */
/*   Updated: 2023/06/09 15:44:43 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_you_exit(t_game *m_game, char *error_msg)
{
	mlx_clear_window(m_game->mlx, m_game->mlx_win);
	ft_printf("%s", error_msg);
	zero_map(m_game);
	draw_map(m_game);
	if (ft_strncmp(error_msg, "YOU WIN", 7) == 0)
	{
		m_game->collectible_tile = mlx_xpm_file_to_image(m_game->mlx,
				"./images/you_win.xpm", &(m_game->tile_width),
				&(m_game->tile_height));
		mlx_put_image_to_window(m_game->mlx, m_game->mlx_win,
			m_game->collectible_tile, ((((m_game->game_width) * 96) / 2) - 152),
			((((m_game->game_height) * 96) / 2) - 38));
	}
	else
	{
		m_game->collectible_tile = mlx_xpm_file_to_image(m_game->mlx,
				"./images/game_over.xpm", &(m_game->tile_width),
				&(m_game->tile_height));
		mlx_put_image_to_window(m_game->mlx, m_game->mlx_win,
			m_game->collectible_tile, ((((m_game->game_width) * 96) / 2) - 300),
			((((m_game->game_height) * 96) / 2) - 75));
	}
}

void	ft_start_exit(t_game *m_game, char *error_msg)
{
	if (ft_strncmp(error_msg, "YOU", 3) == 0)
	{
		ft_you_exit(m_game, error_msg);
		m_game->has_started = 2;
		mlx_loop(m_game->mlx);
	}
	if (ft_strncmp(error_msg, "ESC", 3) != 0)
		ft_printf("Error\n%s", error_msg);
	free_array(m_game->map_copy, m_game->game_height);
	free_array(m_game->map, m_game->game_height);
	exit(1);
}
