/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_monster_red.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:14:40 by ilbendib          #+#    #+#             */
/*   Updated: 2024/01/02 11:33:41 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_draw_monster_red(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->monster_red_img,
		game->monster_red->x * SIZE, game->monster_red->y * SIZE);
}

void	ft_pos_monster_red(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'R')
				ft_new_position_monster_red(x, y, game);
			x++;
		}
		y++;
	}
}

void	ft_new_position_monster_red(int x, int y, t_game *game)
{
	game->monster_red->x = x;
	game->monster_red->y = y;
}

int	ft_monster_red_is_present(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'R')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
