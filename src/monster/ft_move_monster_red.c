/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_monster_red.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:19:11 by ilbendib          #+#    #+#             */
/*   Updated: 2024/01/02 11:33:54 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_move_monster_left_red(t_game *game)
{
	int	x;
	int	y;

	x = game->monster_red->x;
	y = game->monster_red->y;
	game->map[y][x] = '0';
	game->map[y][x - 1] = 'R';
	game->monster_red->x = x - 1;
}

void	ft_move_monster_right_red(t_game *game)
{
	int	x;
	int	y;

	x = game->monster_red->x;
	y = game->monster_red->y;
	game->map[y][x] = '0';
	game->map[y][x + 1] = 'R';
	game->monster_red->x = x + 1;
}

void	ft_move_monster_red(t_game *game)
{
	int	x;
	int	y;

	x = game->monster_red->x;
	y = game->monster_red->y;
	if (game->monster_red_direction == 1)
	{
		if (move_monster_is_good(game, x + 1, y))
			ft_move_monster_right_red(game);
		else
			game->monster_red_direction = -1;
	}
	else
	{
		if (move_monster_is_good(game, x - 1, y))
			ft_move_monster_left_red(game);
		else
			game->monster_red_direction = 1;
	}
}
