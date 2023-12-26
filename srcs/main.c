/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:02:19 by ygolshan          #+#    #+#             */
/*   Updated: 2023/05/28 16:10:28 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incs/so_long.h"

t_mem	*initialize(char *filename)
{
	t_mem	*mem;

	mem = (t_mem *)malloc(sizeof(t_mem));
	if (mem == NULL)
	{
		write(1, "Error: Memory allocation failed\n", 31);
		return (NULL);
	}
	if (ft_strnstr(filename, ".ber", ft_strlen(filename)) || \
		save_map(filename, mem) || check_map_validity(mem) || \
		check_path(mem, mem->p_pos[0], mem->p_pos[1]))
	{
		write(1, "Error: Invalid map\n", 19);
		free(mem);
		return (NULL);
	}
	setup_game(mem);
	printf("maplen=     %d,\n", mem->map_len);
	render_map(mem->game, mem->map);
	return (mem);
}

int	main(int argc, char **argv)
{
	t_mem	*mem;

	if (argc != 2)
	{
		write(1, "Error: Invalid number of arguments\n", 35);
		return (1);
	}
	mem = initialize(argv[1]);
	if (mem == NULL)
		return (1);
	mlx_key_hook(mem->game->win, key_hook, mem);
	mlx_hook(mem->game->win, 17, 1L << 17, handle_exit, mem);
	mlx_loop(mem->game->mlx);
	free(mem);
	return (0);
}
