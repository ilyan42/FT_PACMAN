/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:23:59 by ilbendib          #+#    #+#             */
/*   Updated: 2024/01/03 13:36:04 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_check_map_player(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
				game->map_player += 1;
			x++;
		}
		y++;
	}
}

void	ft_check_map_colec(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				game->map_colect += 1;
			x++;
		}
		y++;
	}
}

void	ft_check_map_exit(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'E')
				game->map_exit += 1;
			x++;
		}
		y++;
	}
}

void	ft_check_map(t_game *game)
{
	ft_check_map_player(game);
	ft_check_map_colec(game);
	ft_check_map_exit(game);
	if (ft_check_object_in_map(game) == 0)
	{
		ft_printf("Error\nError line\n");
		error_check_map(game);
	}
	if (game->map_colect == 0)
	{
		ft_printf("ERROR\n 0 collect\n");
		error_check_map(game);
	}
	if (game->map_exit != 1)
	{
		ft_printf("ERROR\n 0 or to many exit\n");
		error_check_map(game);
	}
	if (game->map_player != 1)
	{
		ft_printf("ERROR\n to many player\n");
		error_check_map(game);
	}
	ft_layout(game);
}

void	error_check_map(t_game *game)
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
	exit(EXIT_SUCCESS);
}
