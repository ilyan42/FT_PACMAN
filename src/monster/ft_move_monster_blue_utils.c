/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_monster_blue_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:24:37 by ilbendib          #+#    #+#             */
/*   Updated: 2024/01/02 11:33:45 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_move_monster_horizontal_blue(t_game *game)
{
	int	x;
	int	y;

	x = game->monster_blue->x;
	y = game->monster_blue->y;
	if (game->monster_direction == 1)
	{
		if (move_monster_is_good(game, x + 1, y))
			ft_move_monster_right_blue(game);
		else
			game->monster_direction = 2;
	}
	else if (game->monster_direction == -1)
	{
		if (move_monster_is_good(game, x - 1, y))
			ft_move_monster_left_blue(game);
		else
			game->monster_direction = 3;
	}
}

void	ft_move_monster_vertical_blue(t_game *game)
{
	int	x;
	int	y;

	x = game->monster_blue->x;
	y = game->monster_blue->y;
	if (game->monster_direction == 2)
	{
		if (move_monster_is_good(game, x, y - 1))
			ft_move_monster_up_blue(game);
		else
			game->monster_direction = -1;
	}
	else if (game->monster_direction == 3)
	{
		if (move_monster_is_good(game, x, y + 1))
			ft_move_monster_down_blue(game);
		else
			game->monster_direction = 1;
	}
}

void	ft_move_monster_blue(t_game *game)
{
	if (game->monster_direction == 1 || game->monster_direction == -1)
		ft_move_monster_horizontal_blue(game);
	else
		ft_move_monster_vertical_blue(game);
}
