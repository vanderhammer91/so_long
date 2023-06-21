/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:20:34 by ivanderw          #+#    #+#             */
/*   Updated: 2023/06/08 23:15:17 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	ft_moveplayer_right_i(t_game *newgame, int y_it, int x_it)
{
	if (newgame->map[y_it][x_it + 1] == '1')
		return (0);
	if (newgame->map[y_it][x_it + 1] == 'X')
		ft_start_exit(newgame, "YOU DIED!\n");
	if (newgame->map[y_it][x_it + 1] == 'E')
	{
		if (character_count(newgame, 'C') == 0)
			ft_start_exit(newgame, "YOU WIN!\n");
		else
			return (0);
	}
	newgame->map[y_it][x_it] = '0';
	newgame->map[y_it][x_it + 1] = 'P';
	newgame->player.f_dir = 'R';
	return (1);
}

int	ft_moveplayer_right(t_game *newgame)
{
	int	x_it;
	int	y_it;

	x_it = 0;
	y_it = 0;
	while (y_it < newgame->game_height)
	{
		x_it = 0;
		while (x_it < newgame->game_width)
		{
			if (newgame->map[y_it][x_it] == 'P')
				return (ft_moveplayer_right_i(newgame, y_it, x_it));
			x_it++;
		}
		y_it++;
	}	
	return (0);
}

int	ft_moveplayer_left_i(t_game *newgame, int y_it, int x_it)
{
	if (newgame->map[y_it][x_it - 1] == '1')
		return (0);
	if (newgame->map[y_it][x_it - 1] == 'X')
		ft_start_exit(newgame, "YOU DIED!\n");
	if (newgame->map[y_it][x_it - 1] == 'E')
	{
		if (character_count(newgame, 'C') == 0)
			ft_start_exit(newgame, "YOU WIN!\n");
		else
			return (0);
	}
	newgame->map[y_it][x_it] = '0';
	newgame->map[y_it][x_it - 1] = 'P';
	newgame->player.f_dir = 'L';
	return (1);
}

int	ft_moveplayer_left(t_game *newgame)
{
	int	x_it;
	int	y_it;

	x_it = 0;
	y_it = 0;
	while (y_it < newgame->game_height)
	{
		x_it = 0;
		while (x_it < newgame->game_width)
		{
			if (newgame->map[y_it][x_it] == 'P')
				return (ft_moveplayer_left_i(newgame, y_it, x_it));
			x_it++;
		}
		y_it++;
	}	
	return (0);
}
