/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:26:45 by ivanderw          #+#    #+#             */
/*   Updated: 2023/06/09 10:57:20 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	refresh_map_i(t_game *newgame)
{
	char	*temp;

	if (character_count(newgame, 'C') == 0 && newgame->exit_state < 7)
		newgame->exit_state++;
	newgame->steps++;
	mlx_clear_window(newgame->mlx, newgame->mlx_win);
	draw_map(newgame);
	mlx_string_put(newgame->mlx, newgame->mlx_win, 5, 15, 0x00FFFFFF,
		"number of steps: ");
	temp = ft_itoa(newgame->steps);
	mlx_string_put(newgame->mlx, newgame->mlx_win, 120, 15, 0x00FFFFFF, temp);
	free(temp);
}

void	start_game(t_game *newgame)
{
	mlx_clear_window(newgame->mlx, newgame->mlx_win);
	mlx_destroy_window(newgame->mlx, newgame->mlx_win);
	newgame->mlx_win = NULL;
	newgame->mlx_win = mlx_new_window(newgame->mlx, newgame->game_width * 96,
			newgame->game_height * 96, "So-long");
	mlx_key_hook(newgame->mlx_win, key_hook, newgame);
	draw_map(newgame);
	newgame->has_started = 1;
}

int	key_hook(int keycode, t_game *newgame)
{
	if (keycode == 53)
		ft_start_exit(newgame, "ESC");
	if (keycode == 36 && newgame->has_started == 0)
		start_game(newgame);
	if (newgame->has_started == 1)
	{
		if (keycode == 124 && ft_moveplayer_right(newgame))
			refresh_map_i(newgame);
		if (keycode == 123 && ft_moveplayer_left(newgame))
			refresh_map_i(newgame);
		if (keycode == 126 && ft_moveplayer_up(newgame))
			refresh_map_i(newgame);
		if (keycode == 125 && ft_moveplayer_down(newgame))
			refresh_map_i(newgame);
	}
	return (0);
}
