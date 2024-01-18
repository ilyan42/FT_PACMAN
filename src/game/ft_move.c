/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:53:09 by ilbendib          #+#    #+#             */
/*   Updated: 2024/01/02 11:33:23 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_move_left(t_game *game)
{
	int	x;
	int	y;

	x = game->pacman->x;
	y = game->pacman->y;
	if (move_is_good(game, x - 1, y))
	{
		game->map[y][x] = '0';
		game->map[y][x - 1] = 'P';
		game->pacman->x = x - 1;
		game->nbr_move += 1;
	}
	ft_draw_pacman_left(game);
}

void	ft_move_right(t_game *game)
{
	int	x;
	int	y;

	x = game->pacman->x;
	y = game->pacman->y;
	if (move_is_good(game, x + 1, y))
	{
		game->map[y][x] = '0';
		game->map[y][x + 1] = 'P';
		game->pacman->x = x + 1;
		game->nbr_move += 1;
	}
	ft_draw_pacman_right(game);
}

void	ft_move_up(t_game *game)
{
	int	x;
	int	y;

	x = game->pacman->x;
	y = game->pacman->y;
	if (move_is_good(game, x, y - 1))
	{
		game->map[y][x] = '0';
		game->map[y - 1][x] = 'P';
		game->pacman->y = y - 1;
		game->nbr_move += 1;
	}
	ft_draw_pacman_up(game);
}

void	ft_move_down(t_game *game)
{
	int	x;
	int	y;

	x = game->pacman->x;
	y = game->pacman->y;
	if (move_is_good(game, x, y + 1))
	{
		game->map[y][x] = '0';
		game->map[y + 1][x] = 'P';
		game->pacman->y = y + 1;
		game->nbr_move += 1;
	}
	ft_draw_pacman_down(game);
}
