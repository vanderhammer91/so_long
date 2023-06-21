/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_setting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 10:50:49 by ivanderw          #+#    #+#             */
/*   Updated: 2023/06/08 16:49:57 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	set_c_frames(t_game *m_game)
{
	m_game->c_frame[0] = "./images/collectible_frames/col_01.xpm";
	m_game->c_frame[1] = "./images/collectible_frames/col_02.xpm";
	m_game->c_frame[2] = "./images/collectible_frames/col_03.xpm";
	m_game->c_frame[3] = "./images/collectible_frames/col_04.xpm";
	m_game->c_frame[4] = "./images/collectible_frames/col_05.xpm";
	m_game->c_frame[5] = "./images/collectible_frames/col_06.xpm";
	m_game->c_frame[6] = "./images/collectible_frames/col_07.xpm";
	m_game->c_frame[7] = "./images/collectible_frames/col_08.xpm";
	m_game->c_frame[8] = "./images/collectible_frames/col_09.xpm";
	m_game->c_frame[9] = "./images/collectible_frames/col_10.xpm";
	m_game->c_frame[10] = "./images/collectible_frames/col_11.xpm";
	m_game->c_frame[11] = "./images/collectible_frames/col_12.xpm";
	m_game->c_frame[12] = "./images/collectible_frames/col_13.xpm";
	m_game->c_frame[13] = "./images/collectible_frames/col_14.xpm";
	m_game->c_frame[14] = "./images/collectible_frames/col_15.xpm";
	m_game->c_frame[15] = "./images/collectible_frames/col_16.xpm";
}

void	set_s_frames(t_game *m_game)
{
	m_game->s_frame[0] = "./images/splash_screen/frame_1.xpm";
	m_game->s_frame[1] = "./images/splash_screen/frame_2.xpm";
	m_game->s_frame[2] = "./images/splash_screen/frame_3.xpm";
	m_game->s_frame[3] = "./images/splash_screen/frame_4.xpm";
	m_game->s_frame[4] = "./images/splash_screen/frame_5.xpm";
	m_game->s_frame[5] = "./images/splash_screen/frame_6.xpm";
	m_game->s_frame[6] = "./images/splash_screen/frame_7.xpm";
	m_game->s_frame[7] = "./images/splash_screen/frame_8.xpm";
	m_game->s_frame[8] = "./images/splash_screen/frame_9.xpm";
	m_game->s_frame[9] = "./images/splash_screen/frame_10.xpm";
	m_game->s_frame[10] = "./images/splash_screen/frame_11.xpm";
	m_game->s_frame[11] = "./images/splash_screen/frame_12.xpm";
	m_game->s_frame[12] = "./images/splash_screen/frame_13.xpm";
	m_game->s_frame[13] = "./images/splash_screen/frame_14.xpm";
}

void	set_e_frames(t_game *m_game)
{
	m_game->e_frame[0] = "./images/e_frames/e_frame00.xpm";
	m_game->e_frame[1] = "./images/e_frames/e_frame01.xpm";
	m_game->e_frame[2] = "./images/e_frames/e_frame02.xpm";
	m_game->e_frame[3] = "./images/e_frames/e_frame03.xpm";
	m_game->e_frame[4] = "./images/e_frames/e_frame04.xpm";
	m_game->e_frame[5] = "./images/e_frames/e_frame05.xpm";
	m_game->e_frame[6] = "./images/e_frames/e_frame06.xpm";
	m_game->e_frame[7] = "./images/e_frames/e_frame07.xpm";
}
