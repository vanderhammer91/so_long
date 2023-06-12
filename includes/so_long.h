/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:52:38 by ivanderw          #+#    #+#             */
/*   Updated: 2023/06/09 15:39:36 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>
# include <limits.h>
# include <mlx.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_data{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;

typedef struct s_point
{
	int		x;
	int		y;
	char	f_dir;
}	t_point;

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	void	*wall_tile;
	char	*wall_path;
	void	*collectible_tile;
	char	*collectible_path;
	char	*c_frame[16];
	void	*splash_tile;
	char	*splash_path;	
	char	*s_frame[14];
	int		splash_state;
	int		collectible_state;
	void	*exit_tile;
	char	*exit_path;
	char	*e_frame[8];
	int		exit_state;
	void	*enemy_tile;
	char	*enemy_path;
	void	*down_tile;
	char	*down_path;
	void	*up_tile;
	char	*up_path;
	void	*left_tile;
	char	*left_path;
	void	*right_tile;
	char	*right_path;
	int		tile_width;
	int		tile_height;
	int		game_height;
	int		game_width;
	int		exit_frame_counter;
	char	**map;
	char	**map_copy;
	int		steps;
	int		frame;
	int		has_started;
	t_point	enemy;
	int		enemy_state;
	t_point	player;
	t_point	exit;
}	t_game;

int		ft_printf(const char *inputstr, ...);
int		ft_printf_printadd_length(unsigned long long my_ptr);
int		ft_printf_printchar_length(char n);
int		ft_printf_printdecimal_length(int n);
int		ft_printf_printhex_length(unsigned int n, const char mychar);
int		ft_printf_printstr_length(char *str);
int		ft_printf_printunsigned_length(unsigned int n);
int		ft_strncmp(const char *s1, const char *s2, int n);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *newlist);
void	ft_lstadd_front(t_list **lst, t_list *newlist);
void	ft_putchar(char c);
void	ft_printbr(void);
size_t	ft_strlen(const char *s);
long	ft_atoi(const char *str);
char	*get_next_line(int fd);
char	*ft_itoa(int n);
char	*ft_strchr(const char *string, int searchedChar);
char	*ft_strdup(char *src);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);

int		ft_moveplayer_right(t_game *m_game);
int		ft_moveplayer_left(t_game *m_game);
int		ft_moveplayer_up(t_game *m_game);
int		ft_moveplayer_down(t_game *m_game);

int		get_map_height_from_argv(char *str);
int		get_map_height_from_arr(char **m_map);
void	print_map(t_game *m_game);
int		copy_map(t_game *game, char **map_copy);
int		set_map(char **argv, t_game *game);
void	fill_check_map(char **map, t_game m_game, int y_coord, int x_coord);
int		check_flood_map(char **map_copy, t_game m_game);
int		perform_map_checks(t_game *m_game);
void	draw_map(t_game *m_game);
void	refresh_map(t_game *m_game);
void	zero_map(t_game *m_game);

void	set_point_data(int y_it, int x_it, t_point *m_point);
void	set_coordinates(t_game *m_game);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		key_hook(int keycode, t_game *m_game);
void	ft_start_exit(t_game *m_game, char *error_msg);
void	free_array(char **my_array, int array_height);
void	set_m_game_state(t_game *m_game, char **argv);
void	set_tile_states(t_game *m_game);
int		character_count(t_game *m_game, char c);
int		frame_refresh(t_game *m_game);

void	set_c_frames(t_game *m_game);
void	set_s_frames(t_game *m_game);
void	set_e_frames(t_game *m_game);

int		is_clear_left(t_game *m_game, int y_cur, int x_cur);
int		is_clear_right(t_game *m_game, int y_cur, int x_cur);
int		is_clear_above(t_game *m_game, int y_cur, int x_cur);
int		is_clear_below(t_game *m_game, int y_cur, int x_cur);
void	set_enemy_coords(t_game *m_game, int y_set, int x_set);
void	set_enemy_state(t_game *m_game);
void	enemy_turn_right(t_game *m_game);
void	enemy_turn_left(t_game *m_game);
void	iterate_enemy_location(t_game *m_game);	

#endif
