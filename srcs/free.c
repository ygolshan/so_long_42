/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:58:08 by ygolshan          #+#    #+#             */
/*   Updated: 2023/05/28 15:10:25 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incs/so_long.h"

void	free_array(char **arr)
{
	char	**temp;

	temp = arr;
	if (arr == NULL)
		return ;
	while (*temp != NULL)
	{
		free(*temp);
		*temp = NULL;
		temp++;
	}
	free(arr);
}

void	cleanup_memory(t_mem *mem, int on_off)
{
	if (mem == NULL)
		return ;
	free_array(mem->map);
	free(mem->c_pos);
	if (on_off == 1 || on_off == 2)
		end_game(mem->game);
	free(mem);
	if (on_off == 1)
		exit(-1);
}

int	handle_exit(t_mem *mem)
{
	if (mem == NULL)
		return (0);
	cleanup_memory(mem, 2);
	return (0);
}

void	free_queue(t_queue *queue)
{
	while (queue->first != NULL)
	{
		dequeue_node(queue);
	}
}
