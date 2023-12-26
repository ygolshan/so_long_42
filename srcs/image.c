/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:01:00 by ygolshan          #+#    #+#             */
/*   Updated: 2023/05/28 15:15:20 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incs/so_long.h"

void	load_images(t_game *game)
{
	int	width;
	int	height;

	game->imgs[0] = mlx_xpm_file_to_image(game->mlx,
			"./images/back.xpm", &width, &height);
	game->imgs[1] = mlx_xpm_file_to_image(game->mlx,
			"./images/wall.xpm", &width, &height);
	game->imgs[2] = mlx_xpm_file_to_image(game->mlx,
			"./images/collect.xpm", &width, &height);
	game->imgs[3] = mlx_xpm_file_to_image(game->mlx,
			"./images/exit.xpm", &width, &height);
	game->imgs[4] = mlx_xpm_file_to_image(game->mlx,
			"./images/girl.xpm", &width, &height);
	game->imgs[5] = mlx_xpm_file_to_image(game->mlx,
			"./images/girl.xpm", &width, &height);
	game->imgs[6] = mlx_xpm_file_to_image(game->mlx,
			"./images/girl.xpm", &width, &height);
	game->imgs[7] = mlx_xpm_file_to_image(game->mlx,
			"./images/girl.xpm", &width, &height);
	if (game->imgs[0] == NULL || game->imgs[1] == NULL
		|| game->imgs[2] == NULL || game->imgs[3] == NULL
		|| game->imgs[4] == NULL || game->imgs[5] == NULL
		|| game->imgs[6] == NULL || game->imgs[7] == NULL)
		exit(1);
}

void	print_images(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x * 32, y * 32);
}

int	render_map(t_game *game, char **map)
{
	int	x;
	int	y;

	load_images(game);
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == '0' || map[y][x] == '2')
				print_images(game, game->imgs[0], x, y);
			else if (map[y][x] == '1')
				print_images(game, game->imgs[1], x, y);
			else if (map[y][x] == 'c')
				print_images(game, game->imgs[2], x, y);
			else if (map[y][x] == 'e')
				print_images(game, game->imgs[3], x, y);
			else if (map[y][x] == 'P')
				print_images(game, game->imgs[4], x, y);
		}
	}
	return (0);
}

void	end_game(t_game *game)
{
	if (game != NULL)
	{
		if (game->mlx != NULL)
		{
			mlx_destroy_window(game->mlx, game->win);
			free(game->mlx);
		}
		free(game);
	}
	exit(-1);
}

int	close_window(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == 53 && game != NULL)
	{
		end_game(game);
	}
	return (0);
}
