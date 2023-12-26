/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:59:05 by ygolshan          #+#    #+#             */
/*   Updated: 2023/05/28 15:07:50 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incs/so_long.h"

int	update_content(t_mem *mem, int i, int j)
{
	char	current_cell;
	int		result;

	current_cell = mem->map[i][j];
	result = 0;
	if (current_cell == 'c')
	{
		mem->map[i][j] = '2';
		mem->game->cont++;
		if (mem->game->cont == mem->collect)
			mem->game->exit = 1;
		result = 1;
	}
	else if (current_cell == 'e')
	{
		if (mem->game->exit != 1)
			result = 2;
		else
			cleanup_memory(mem, 1);
	}
	return (result);
}

void	move_player(t_mem *mem, int i, int j, int k)
{
	int	status;

	status = update_content(mem, i, j);
	mlx_put_image_to_window(mem->game->mlx, mem->game->win, mem->game->imgs[0], \
		mem->p_pos[1] * 32, mem->p_pos[0] * 32);
	if (mem->map[mem->p_pos[0]][mem->p_pos[1]] == 'e')
		mlx_put_image_to_window(mem->game->mlx, mem->game->win, \
		mem->game->imgs[3], mem->p_pos[1] * 32, mem->p_pos[0] * 32);
	if (status == 1)
		mlx_put_image_to_window(mem->game->mlx, mem->game->win, \
		mem->game->imgs[0], j * 32, i * 32);
	else if (status == 2)
		mlx_put_image_to_window(mem->game->mlx, mem->game->win, \
		mem->game->imgs[3], j * 32, i * 32);
	mlx_put_image_to_window(mem->game->mlx, mem->game->win, \
		mem->game->imgs[k], j * 32, i * 32);
	mem->p_pos[0] = i;
	mem->p_pos[1] = j;
	mem->game->movements++;
	ft_putnbr(mem->game->movements);
	write(1, "\n", 1);
}

int	key_hook(int keycode, void *param)
{
	t_mem	*mem;
	int		row;
	int		col;

	mem = (t_mem *)param;
	row = mem->p_pos[0];
	col = mem->p_pos[1];
	if (keycode == 0 && mem->map[row][col - 1] != '1')
		move_player(mem, row, col - 1, 5);
	else if (keycode == 2 && mem->map[row][col + 1] != '1')
		move_player(mem, row, col + 1, 4);
	else if (keycode == 13 && mem->map[row - 1][col] != '1')
		move_player(mem, row - 1, col, 6);
	else if (keycode == 1 && mem->map[row + 1][col] != '1')
		move_player(mem, row + 1, col, 7);
	else if (keycode == 53)
		cleanup_memory(mem, 1);
	return (0);
}
