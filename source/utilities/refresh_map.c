/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:56:15 by ivanderw          #+#    #+#             */
/*   Updated: 2023/06/09 12:57:01 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	refresh_map(t_game *newgame)
{
	char	*temp;

	mlx_clear_window(newgame->mlx, newgame->mlx_win);
	draw_map(newgame);
	mlx_string_put(newgame->mlx, newgame->mlx_win, 5, 15,
		0x00FFFFFF, "number of steps: ");
	temp = ft_itoa(newgame->steps);
	mlx_string_put(newgame->mlx, newgame->mlx_win, 120, 15, 0x00FFFFFF, temp);
	free(temp);
}
