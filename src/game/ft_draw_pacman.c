/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_pacman.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:19:06 by ilbendib          #+#    #+#             */
/*   Updated: 2024/01/02 11:33:10 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_draw_pacman_right(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->pacman_img,
		game->pacman->x * SIZE, game->pacman->y * SIZE);
}

void	ft_draw_pacman_left(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->pacman_left,
		game->pacman->x * SIZE, game->pacman->y * SIZE);
}

void	ft_draw_pacman_up(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->pacman_up,
		game->pacman->x * SIZE, game->pacman->y * SIZE);
}

void	ft_draw_pacman_down(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->pacman_down,
		game->pacman->x * SIZE, game->pacman->y * SIZE);
}
