/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:57:18 by ygolshan          #+#    #+#             */
/*   Updated: 2023/05/28 16:14:00 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incs/so_long.h"

int	check_walls(int i, int j, int line_len, t_mem *mem)
{
	if (i == 0 && !(mem->map[i][j] == '1' || mem->map[i][j] == '\n'))
		return (1);
	else if (i == (mem->map_len) && \
		!(mem->map[i][j] == '1' || mem->map[i][j] == '\n'))
		return (2);
	else if ((j == 0 || j == line_len - 2) && mem->map[i][j] != '1')
		return (3);
	else if ((i == mem->map_len - 1) && (mem->map[i][j] != '1' \
		&& mem->map[i][j] != '\n'))
		return (3);
	else if (!(mem->map[i][j] == '0' || mem->map[i][j] == '1' || \
		mem->map[i][j] == 'C' || mem->map[i][j] == 'E' || \
		mem->map[i][j] == 'P' || mem->map[i][j] == '\n'))
		return (4);
	return (0);
}

void	count_items(int i, int j, t_mem *mem)
{
	char	current;

	current = mem->map[i][j];
	if (current == 'C')
		mem->collect++;
	else if (current == 'E')
		mem->exit++;
	else if (current == 'P')
	{
		mem->p_pos[0] = i;
		mem->p_pos[1] = j;
		mem->entry++;
	}
}

int	check_line(t_mem *mem, int line_len, int i, int j)
{
	if (i != mem->map_len - 1)
	{
		if (line_len != j)
			return (1);
	}
	else
	{
		if ((mem->map[i][j - 1] == '\n' && line_len != j)
			|| (mem->map[i][j - 1] == '\0' && line_len != j - 1))
		{
			return (1);
		}
	}
	return (0);
}

int	check_map_validity(t_mem *mem)
{
	int	i;
	int	j;
	int	line_len;

	mem->exit = 0;
	mem->entry = 0;
	mem->collect = 0;
	line_len = ft_strlen(mem->map[0]);
	i = -1;
	while (mem->map[++i])
	{
		j = -1;
		while (mem->map[i][++j])
		{
			if (check_walls(i, j, line_len, mem))
				return (1);
			count_items(i, j, mem);
		}
		if (check_line(mem, line_len, i, j))
			return (1);
	}
	if (mem->collect == 0 || mem->exit != 1 || mem->entry != 1)
		return (1);
	return (0);
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}
