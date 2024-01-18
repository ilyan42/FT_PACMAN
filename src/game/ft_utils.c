/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:56:41 by ilbendib          #+#    #+#             */
/*   Updated: 2024/01/02 11:33:32 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_print_score(t_game *game)
{
	char	*score;
	char	*phrase;

	score = ft_itoa(game->nbr_score);
	phrase = ft_strjoin("SCORE : ", score);
	mlx_string_put(game->mlx, game->win, 40, 40, 0xffffff, phrase);
	free(score);
	free(phrase);
}

void	ft_check_len_last_line(t_game *game)
{
	int		y;
	size_t	len;

	y = -1;
	len = ft_strlen(game->map[0]) - 1;
	while (game->map[++y])
	{
		if (y > 0 && game->map[y + 1] == NULL)
		{
			if (ft_strlen(game->map[y]) != len)
			{
				ft_printf("Error\nError line\n");
				close_game(game);
			}
		}
	}
}

int	ft_check_object_in_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x] && x < game->size_x)
		{
			if (!(game->map[y][x] == '1' || game->map[y][x] == 'P'
					|| game->map[y][x] == '0' || game->map[y][x] == 'E'
					|| game->map[y][x] == 'C' || game->map[y][x] == 'B'
					|| game->map[y][x] == 'R' || game->map[y][x] == 'G'))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	ft_check_img(t_game *game)
{
	if (!game->pacman_img || !game->pacman_colec || !game->pacman_down
		|| !game->pacman_exit_close || !game->pacman_exit_open
		|| !game->pacman_gnd || !game->pacman_left || !game->pacman_up
		|| !game->pacman_wall || !game->monster_blue_img
		|| !game->monster_green_img || !game->monster_red_img)
	{
		ft_printf("Error\nError image generation\n");
		exit(0);
	}
}
