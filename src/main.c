/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:48:40 by ilbendib          #+#    #+#             */
/*   Updated: 2024/01/03 13:57:06 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_free_img(t_game *game)
{
	mlx_destroy_image(game->mlx, game->pacman_img);
	mlx_destroy_image(game->mlx, game->pacman_colec);
	mlx_destroy_image(game->mlx, game->pacman_down);
	mlx_destroy_image(game->mlx, game->pacman_exit_open);
	mlx_destroy_image(game->mlx, game->pacman_exit_close);
	mlx_destroy_image(game->mlx, game->pacman_wall);
	mlx_destroy_image(game->mlx, game->pacman_up);
	mlx_destroy_image(game->mlx, game->pacman_left);
	mlx_destroy_image(game->mlx, game->monster_blue_img);
	mlx_destroy_image(game->mlx, game->monster_green_img);
	mlx_destroy_image(game->mlx, game->monster_red_img);
	mlx_destroy_image(game->mlx, game->pacman_gnd);
}

int	close_game(t_game *game)
{
	ft_free_img(game);
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	ft_free_splitted_map(game->map);
	free(game->pacman);
	free(game->monster_blue);
	free(game->monster_red);
	free(game->monster_green);
	free(game->player_position);
	exit(EXIT_SUCCESS);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2)
	{
		ft_parsing_map(av[1], &game);
		size_map(&game);
		ft_game_init(&game);
		ft_check_map(&game);
		nb_colect_in_map(&game);
		ft_print_map(&game);
		ft_init_player(&game);
		ft_pos_monster_blue(&game);
		ft_pos_monster_green(&game);
		ft_pos_monster_red(&game);
		ft_draw_pacman_down(&game);
		mlx_loop_hook(game.mlx, ft_update, (void *)&game);
		mlx_hook(game.win, 17, 0, close_game, (void *)&game);
		mlx_hook(game.win, KeyPress, KeyPressMask, ft_handle_key_press,
			(void *)&game);
		mlx_loop(game.mlx);
	}
	return (0);
}
