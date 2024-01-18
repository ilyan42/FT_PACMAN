/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:34:43 by ilbendib          #+#    #+#             */
/*   Updated: 2024/01/02 11:34:09 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static char	**path_clone(char **map)
{
	int		rows;
	char	**clone;
	int		i;

	rows = 0;
	i = -1;
	while (map[rows])
		rows++;
	clone = ft_calloc(rows + 1, sizeof(char *));
	if (!clone)
		return (NULL);
	while (map[++i])
		clone[i] = ft_strdup(map[i]);
	return (clone);
}

static void	flood(int x, int y, t_game *game)
{
	if (game->map_dup[y][x] == '1' || game->map_dup[y][x] == '3')
		return ;
	game->map_dup[y][x] = '3';
	flood(x, y + 1, game);
	flood(x, y - 1, game);
	flood(x - 1, y, game);
	flood(x + 1, y, game);
	return ;
}

static int	check_collec_exit(t_game *game)
{
	int	i;

	i = 0;
	while (game->map_dup[i])
	{
		if (ft_strchr(game->map_dup[i], 'C') || \
			ft_strchr(game->map_dup[i], 'E'))
			return (0);
		i++;
	}
	return (1);
}

int	is_rectangular(t_game *game)
{
	if (game->size_x > game->size_y || game->size_x < game->size_y)
		return (1);
	return (0);
}

int	pathfinder(t_game *game)
{
	int	is_path;
	int	nb_collec;

	nb_collec = game->collect;
	game->map_dup = path_clone(game->map);
	game->nb_moves_max = (game->size_x * game->size_y) * 2;
	game->nb_moves = 0;
	flood(game->player_position->x, game->player_position->y, game);
	is_path = check_collec_exit(game);
	ft_free_splitted_map(game->map_dup);
	game->collect = nb_collec;
	return (is_path);
}
