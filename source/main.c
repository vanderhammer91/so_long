/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:36:40 by ivanderw          #+#    #+#             */
/*   Updated: 2023/06/09 15:32:09 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	map_sets_and_frame_sets(t_game *m_game, char **argv)
{
	m_game->map = malloc (sizeof(char *) * m_game->game_height);
	m_game->map_copy = malloc (sizeof(char *) * m_game->game_height);
	if (!m_game->map_copy || !m_game->map)
	{
		free(m_game->map);
		free(m_game->map_copy);
		return (1);
	}
	if (!set_map(argv, m_game))
	{
		free_array(m_game->map, m_game->game_height);
		free(m_game->map_copy);
		return (1);
	}	
	m_game->game_width = ft_strlen(m_game->map[1]) - 1;
	set_c_frames(m_game);
	set_s_frames(m_game);
	set_e_frames(m_game);
	return (0);
}

int	on_x_press(t_game *m_game)
{
	free_array(m_game->map_copy, m_game->game_height);
	free_array(m_game->map, m_game->game_height);
	exit(0);
}

int	main(int argc, char **argv)
{
	static t_game	m_game;

	if (argc != 2)
		return (1);
	set_m_game_state(&m_game, argv);
	if (map_sets_and_frame_sets(&m_game, argv))
		return (1);
	if (!copy_map(&m_game, m_game.map_copy))
		ft_start_exit(&m_game, "[Errorcode: Copy map failed]\n");
	m_game.mlx = mlx_init();
	set_tile_states(&m_game);
	m_game.mlx_win = mlx_new_window(m_game.mlx, 1220, 692, "So-long");
	set_coordinates(&m_game);
	if (!perform_map_checks(&m_game))
		ft_start_exit(&m_game, "Unknown Error\n");
	set_enemy_state(&m_game);
	mlx_key_hook(m_game.mlx_win, key_hook, &m_game);
	mlx_loop_hook(m_game.mlx, frame_refresh, &m_game);
	mlx_hook(m_game.mlx_win, 17, 0, on_x_press, &m_game);
	mlx_loop(m_game.mlx);
	free_array(m_game.map_copy, m_game.game_height);
	free_array(m_game.map, m_game.game_height);
	return (0);
}
