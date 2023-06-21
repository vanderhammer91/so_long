/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:47:51 by ivanderw          #+#    #+#             */
/*   Updated: 2023/06/08 22:02:39 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	is_clear_left(t_game *m_game, int y_cur, int x_cur)
{
	if (m_game->map[y_cur][x_cur - 1] == '0')
		return (1);
	return (0);
}

int	is_clear_right(t_game *m_game, int y_cur, int x_cur)
{
	if (m_game->map[y_cur][x_cur + 1] == '0')
		return (1);
	return (0);
}

int	is_clear_above(t_game *m_game, int y_cur, int x_cur)
{
	if (m_game->map[y_cur - 1][x_cur] == '0')
		return (1);
	return (0);
}

int	is_clear_below(t_game *m_game, int y_cur, int x_cur)
{
	if (m_game->map[y_cur + 1][x_cur] == '0')
		return (1);
	return (0);
}
