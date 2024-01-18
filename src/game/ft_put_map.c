/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:10:57 by ilbendib          #+#    #+#             */
/*   Updated: 2024/01/02 11:33:28 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_init_player(t_game *game)
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
				ft_new_position(x, y, game);
			x++;
		}
		y++;
	}
	ft_print_map(game);
}

void	print_element(t_game *game, int x, int y, char element)
{
	if (element == '1')
		print_wall(game, x, y);
	else if (element == '0')
		print_ground(game, x, y);
	else if (element == 'C')
		print_collectible(game, x, y);
	else if (element == 'E')
		print_exit(game, x, y);
	else if (element == 'R')
		print_red_monster(game, x, y);
	else if (element == 'G')
		print_green_monster(game, x, y);
	else if (element == 'B')
		print_blue_monster(game, x, y);
}

void	ft_print_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			print_element(game, x, y, game->map[y][x]);
			x++;
		}
		y++;
	}
}

void	ft_new_position(int x, int y, t_game *game)
{
	game->pacman->x = x;
	game->pacman->y = y;
}

void	ft_print_movements(t_game *game)
{
	char	*movements;
	char	*phrase;

	movements = ft_itoa(game->nbr_move);
	phrase = ft_strjoin("MOVEMENTS : ", movements);
	mlx_string_put(game->mlx, game->win, 40, 20, 0xffffff, phrase);
	free(movements);
	free(phrase);
}
