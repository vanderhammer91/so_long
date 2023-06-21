/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:31:45 by ivanderw          #+#    #+#             */
/*   Updated: 2023/06/08 22:04:40 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	character_count(t_game *m_game, char c)
{
	int	i;
	int	j;
	int	count;

	j = 0;
	count = 0;
	while (j < m_game->game_height)
	{
		i = 0;
		while (i < m_game->game_width)
		{
			if (m_game->map[j][i] == c)
				count++;
			i++;
		}
		j++;
	}
	return (count);
}

int	check_map_border(t_game *m_game)
{
	int	i;
	int	j;

	j = 0 ;
	while (j < m_game->game_height)
	{
		i = 0;
		while (i < m_game->game_width)
		{
			if ((i == 0 || i == (m_game->game_width) - 1)
				&& (m_game->map[j][i] != '1'))
				return (0);
			if ((j == 0 || j == (m_game->game_height) - 1)
				&& (m_game->map[j][i] != '1'))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	check_invalid_chars(t_game *m_game)
{
	int	i;
	int	j;

	j = 0 ;
	while (j < m_game->game_height)
	{
		i = 0;
		while (i < m_game->game_width)
		{
			if (m_game->map[j][i] != '1'
					&& m_game->map[j][i] != '0'
					&& m_game->map[j][i] != 'C'
					&& m_game->map[j][i] != 'E'
					&& m_game->map[j][i] != 'P')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	map_is_rectangular(t_game *m_game)
{
	int	row_len;
	int	j;

	row_len = ft_strlen(m_game->map[0]);
	j = 1 ;
	while (j < m_game->game_height)
	{
		if (ft_strlen(m_game->map[j]) != (size_t)row_len)
			return (0);
		j++;
	}
	return (1);
}

int	perform_map_checks(t_game *m_game)
{
	if (!map_is_rectangular(m_game))
		ft_start_exit(m_game, "[Errorcode: map non rectangular check]\n");
	if (!check_invalid_chars(m_game))
		ft_start_exit(m_game, "[Errorcode: invalid character check]\n");
	if (character_count(m_game, 'P') != 1)
		ft_start_exit(m_game, "[Errorcode: Playercount check]\n");
	if (character_count(m_game, 'E') != 1)
		ft_start_exit(m_game, "[Errorcode: Exitcount check]\n");
	if (character_count(m_game, 'C') < 1)
		ft_start_exit(m_game, "[Errorcode: Collectible count check]\n");
	if (!check_map_border(m_game))
		ft_start_exit(m_game, "[Errorcode: Border check]\n");
	if (!check_flood_map(m_game->map_copy, *m_game))
		ft_start_exit(m_game, "[Errorcode: Pathfinding check]\n");
	return (1);
}
