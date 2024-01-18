/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:39:28 by ilyanbendib       #+#    #+#             */
/*   Updated: 2024/01/03 13:28:25 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	initialize_window(t_game *game, int img_size)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Error: environement not set\n");
		return (exit(0), (void)0);
	}
	game->win = mlx_new_window(game->mlx, game->height * img_size, game->width
			* img_size, "FT_PACMAN");
}

void	load_images(t_game *game, int img_size)
{
	game->pacman_colec = mlx_xpm_file_to_image(game->mlx, "./img/colec.xpm",
			&img_size, &img_size);
	game->pacman_img = mlx_xpm_file_to_image(game->mlx,
			"./img/pacman_right.xpm", &img_size, &img_size);
	game->pacman_wall = mlx_xpm_file_to_image(game->mlx, "./img/wall_pac.xpm",
			&img_size, &img_size);
	game->pacman_gnd = mlx_xpm_file_to_image(game->mlx, "./img/ground_pac.xpm",
			&img_size, &img_size);
	game->monster_red_img = mlx_xpm_file_to_image(game->mlx,
			"./img/Monster_red.xpm", &img_size, &img_size);
	game->monster_green_img = mlx_xpm_file_to_image(game->mlx,
			"./img/Monster_green.xpm", &img_size, &img_size);
	game->monster_blue_img = mlx_xpm_file_to_image(game->mlx,
			"./img/Monster_blue.xpm", &img_size, &img_size);
	game->pacman_up = mlx_xpm_file_to_image(game->mlx, "./img/pacman_up.xpm",
			&img_size, &img_size);
	game->pacman_left = mlx_xpm_file_to_image(game->mlx,
			"./img/pacman_left.xpm", &img_size, &img_size);
	game->pacman_down = mlx_xpm_file_to_image(game->mlx,
			"./img/pacman_down.xpm", &img_size, &img_size);
	game->pacman_exit_close = mlx_xpm_file_to_image(game->mlx,
			"./img/exit_cole2.xpm", &img_size, &img_size);
	game->pacman_exit_open = mlx_xpm_file_to_image(game->mlx,
			"./img/exit_open.xpm", &img_size, &img_size);
	ft_check_img(game);
}

void	initialize_game(t_game *game)
{
	game->pacman = malloc(sizeof(t_game));
	game->monster_red = malloc(sizeof(t_game));
	game->monster_blue = malloc(sizeof(t_game));
	game->monster_green = malloc(sizeof(t_game));
	game->nbr_move = 0;
	game->nbr_colec = 0;
	game->nbr_colect_in_map = 0;
	game->monster_direction = 1;
	game->monster_green_direction = 0;
	game->monster_red_direction = 0;
	game->map_colect = 0;
	game->map_exit = 0;
	game->map_player = 0;
	game->nbr_score = 650;
	game->height = game->size_x;
	game->width = game->size_y;
}

void	ft_game_init(t_game *game)
{
	int	img_size;

	img_size = SIZE;
	initialize_game(game);
	initialize_window(game, img_size);
	load_images(game, img_size);
	mlx_clear_window(game->mlx, game->win);
}

int	ft_update(t_game *game)
{
	static int	count;

	count++;
	if (count == 5000)
	{
		ft_print_map(game);
		if (ft_monster_blue_is_present(game))
			ft_move_monster_blue(game);
		if (ft_monster_green_is_present(game))
			ft_move_monster_green(game);
		if (ft_monster_red_is_present(game))
			ft_move_monster_red(game);
		ft_print_movements(game);
		ft_print_score(game);
		count = 0;
		game->nbr_score -= 1;
		if (game->nbr_score == 0)
		{
			ft_printf("YOU LOSE !!\n");
			close_game(game);
		}
	}
	return (0);
}
