/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:57:57 by ygolshan          #+#    #+#             */
/*   Updated: 2023/05/28 15:10:25 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incs/so_long.h"

int	check_position(int i, int j, char **map)
{
	char	cell;

	cell = map[i][j];
	if (cell == '1' || cell == '2' || cell == 'P' || cell == 'c' || cell == 'e')
		return (1);
	return (0);
}

t_node	*check_neighbour(int i, int j, t_mem *mem)
{
	if (!check_position(i - 1, j, mem->map))
		return (create_node_element(i - 1, j));
	if (!check_position(i, j + 1, mem->map))
		return (create_node_element(i, j + 1));
	if (!check_position(i + 1, j, mem->map))
		return (create_node_element(i + 1, j));
	if (!check_position(i, j - 1, mem->map))
		return (create_node_element(i, j - 1));
	else
		return (NULL);
}

void	save_position(t_mem *mem, t_node *neighbour, int *collect)
{
	if (mem->map[neighbour->i][neighbour->j] == 'C')
	{
		mem->c_pos[*collect * 2] = neighbour->i;
		mem->c_pos[(*collect * 2) + 1] = neighbour->j;
		(*collect)++;
	}
	else
	{
		mem->e_pos[0] = neighbour->i;
		mem->e_pos[1] = neighbour->j;
	}
}

void	update_neighbours(t_queue *queue, t_mem *mem, int *cont, \
	int *collect)
{
	int		k;
	t_node	*neighbour;

	k = -1;
	while (++k < 4)
	{
		neighbour = check_neighbour(queue->first->i, queue->first->j, mem);
		if (neighbour)
		{
			enqueue_node(queue, neighbour);
			if (mem->map[neighbour->i][neighbour->j] == 'C' || \
				mem->map[neighbour->i][neighbour->j] == 'E')
			{
				save_position(mem, neighbour, collect);
				mem->map[neighbour->i][neighbour->j] += ('a' - 'A');
				(*cont)++;
			}
			else
				mem->map[neighbour->i][neighbour->j] = '2';
		}
	}
}

int	check_path(t_mem *mem, int i, int j)
{
	t_queue	*queue;
	int		cont;
	int		collect;
	int		k;

	queue = create_queue_node();
	mem->c_pos = (int *)malloc(sizeof(int) * mem->collect * 2);
	enqueue_node(queue, create_node_element(i, j));
	cont = 0;
	collect = 0;
	k = 0;
	while (queue->first && cont < mem->collect + 1)
	{
		update_neighbours(queue, mem, &cont, &collect);
		dequeue_node(queue);
	}
	if (queue->first)
		free_queue(queue);
	free(queue);
	if (cont == mem->collect + 1)
		return (0);
	return (1);
}
