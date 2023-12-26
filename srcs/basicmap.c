/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basicmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:58:31 by ygolshan          #+#    #+#             */
/*   Updated: 2023/05/28 14:59:20 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incs/so_long.h"

void	initialize_game(t_game *game)
{
	game->mlx = NULL;
	game->mlx = mlx_init();
	if (game->mlx == NULL)
	{
		end_game(game);
		return ;
	}
}

void	create_window(t_game *game, int width, int height)
{
	game->win = mlx_new_window(game->mlx, width, height, "so_long");
	if (game->win == NULL)
		end_game(game);
}

void	setup_game(t_mem *mem)
{
	int	width;

	width = ft_strlen(mem->map[0]) - 1;
	mem->game = (t_game *)malloc(sizeof(t_game));
	initialize_game(mem->game);
	create_window(mem->game, width * 32, mem->map_len * 32);
	mem->game->cont = 0;
	mem->game->exit = 0;
	mem->game->movements = 0;
}

int	count_lines(char *addr)
{
	int		fd;
	int		cont;
	int		read_len;
	char	buff[2];

	fd = open(addr, O_RDONLY);
	if (fd <= 0)
	{
		perror("");
		return (1);
	}
	cont = 1;
	read_len = 1;
	while (read_len)
	{
		read_len = read(fd, buff, 1);
		buff[read_len] = '\0';
		if (buff[0] == '\n')
			cont++;
	}
	close(fd);
	return (cont);
}

int	save_map(char *map_addr, t_mem *mem)
{
	int		fd;
	int		i;
	char	*str;

	fd = open(map_addr, O_RDONLY);
	mem->map_len = count_lines(map_addr);
	if (mem->map_len == 1)
		return (1);
	mem->map = (char **)malloc(sizeof(char *) * (mem->map_len + 1));
	if (!mem->map)
		exit(-1);
	i = 0;
	str = get_next_line(fd);
	mem->map[i++] = str;
	while (str)
	{
		str = get_next_line(fd);
		mem->map[i++] = str;
	}
	if (mem->map[i - 2][ft_strlen(mem->map[i - 2]) - 1] == '\n')
		mem->map_len--;
	close(fd);
	return (0);
}
