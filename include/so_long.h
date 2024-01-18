/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:49:36 by ilbendib          #+#    #+#             */
/*   Updated: 2024/01/03 13:14:13 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../LIBFT/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_pos
{
	int		x;
	int		y;
}			t_pos;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*pacman_gnd;
	void	*pacman_img;
	t_pos	*pacman;
	void	*pacman_wall;
	void	*pacman_colec;
	void	*pacman_exit_close;
	void	*pacman_left;
	void	*pacman_up;
	void	*pacman_down;
	char	**map;
	int		map_height;
	int		size_x;
	int		size_y;
	int		height;
	int		width;
	int		nbr_move;
	void	*nbr_colec;
	void	*nbr_colect_in_map;
	void	*monster_blue_img;
	void	*monster_red_img;
	void	*monster_green_img;
	t_pos	*monster_blue;
	int		monster_direction;
	int		monster_green_direction;
	int		monster_red_direction;
	t_pos	*monster_green;
	t_pos	*monster_red;
	void	*pacman_exit_open;
	int		map_player;
	int		map_colect;
	int		map_exit;
	char	**map_dup;
	int		collect;
	int		nb_moves_max;
	int		nb_moves;
	t_pos	*player_position;
	int		nbr_score;
	int		check;
}			t_game;

// # define KEY_PRESS 2
// # define KEY_RELEASE 3
// # define KEY_PRESS_MASK (1L << 0)
# define ESCAPE_KEY 65307
# define SIZE 50

# define W 119
# define S_QW 115
# define A 97
# define D_QW 100

# define Z 13
# define Q 1
# define S 0
# define D 2

# define UP 65362
# define DOWN 65364
# define RIGHT 65363
# define LEFT 65361

void		ft_draw_pacman_down(t_game *game);
void		ft_draw_pacman_up(t_game *game);
void		ft_draw_pacman_left(t_game *game);
int			ft_handle_key_press(int keycode, void *param);
void		ft_draw_pacman_right(t_game *game);
void		ft_print_map(t_game *game);
void		ft_print_map(t_game *game);
void		ft_new_position(int x, int y, t_game *game);
void		ft_init_player(t_game *game);
void		ft_game_init(t_game *game);
void		ft_parsing_map(char *file, t_game *game);
int			ft_update(t_game *game);
void		size_map(t_game *game);
int			move_is_good(t_game *game, int x, int y);
void		ft_move_left(t_game *game);
void		ft_move_right(t_game *game);
void		ft_move_down(t_game *game);
void		ft_move_up(t_game *game);
void		ft_print_map(t_game *game);
int			nb_colec_is_good(t_game *game);
void		nb_colect_in_map(t_game *game);
void		ft_print_movements(t_game *game);
void		print_element(t_game *game, int x, int y, char element);
void		print_blue_monster(t_game *game, int x, int y);
void		print_green_monster(t_game *game, int x, int y);
void		print_red_monster(t_game *game, int x, int y);
void		print_exit(t_game *game, int x, int y);
void		print_collectible(t_game *game, int x, int y);
void		print_ground(t_game *game, int x, int y);
void		print_wall(t_game *game, int x, int y);
void		initialize_game(t_game *game);
void		load_images(t_game *game, int img_size);
void		initialize_window(t_game *game, int img_size);
void		allocate_and_fill_map(t_game *game, int fd);
void		count_map_height(t_game *game, int fd);
void		is_ber_file(char *map);

void		ft_layout(t_game *game);
int			pathfinder(t_game *game);
int			close_game(t_game *game);
void		ft_free_img(t_game *game);
void		ft_free_splitted_map(char **tab);
int			is_rectangular(t_game *game);
void		player_position(int x, int y, t_game *game);
void		check_walls(t_game *map_lay);

void		ft_print_score(t_game *game);
void		ft_check_len_last_line(t_game *game);
int			ft_check_object_in_map(t_game *game);
void		error_check_map(t_game *game);
void		ft_check_img(t_game *game);

/*******************Monster_Blue*******************/

void		ft_move_monster_left_blue(t_game *game);
void		ft_new_position_monster_blue(int x, int y, t_game *game);
int			move_monster_is_good(t_game *game, int x, int y);
void		ft_pos_monster_blue(t_game *game);
void		ft_draw_monster_blue(t_game *game);
void		ft_move_monster_right_blue(t_game *game);
void		ft_move_monster_blue(t_game *game);
void		ft_move_monster_up_blue(t_game *game);
void		ft_move_monster_down_blue(t_game *game);
void		ft_move_monster_vertical_blue(t_game *game);
void		ft_move_monster_horizontal_blue(t_game *game);
int			ft_monster_blue_is_present(t_game *game);

/*******************Monster_Green*******************/

void		ft_draw_monster_green(t_game *game);
void		ft_pos_monster_green(t_game *game);
void		ft_new_position_monster_green(int x, int y, t_game *game);
void		ft_move_monster_down_green(t_game *game);
void		ft_move_monster_up_green(t_game *game);
void		ft_move_monster_green(t_game *game);
int			ft_monster_green_is_present(t_game *game);

/*******************Monster_red*******************/

void		ft_move_monster_left_red(t_game *game);
void		ft_move_monster_right_red(t_game *game);
void		ft_move_monster_red(t_game *game);
void		ft_draw_monster_red(t_game *game);
void		ft_pos_monster_red(t_game *game);
void		ft_new_position_monster_red(int x, int y, t_game *game);
int			ft_monster_red_is_present(t_game *game);

void		ft_check_map(t_game *game);
void		ft_check_map_exit(t_game *game);
void		ft_check_map_colec(t_game *game);
void		ft_check_map_player(t_game *game);

#endif
