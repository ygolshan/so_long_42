/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:00:09 by ygolshan          #+#    #+#             */
/*   Updated: 2023/05/28 15:10:25 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incs/so_long.h"

t_queue	*create_queue_node(void)
{
	t_queue	*queue;

	queue = (t_queue *)malloc(sizeof(t_queue));
	if (queue != NULL)
	{
		queue->first = NULL;
		queue->last = NULL;
	}
	return (queue);
}

t_node	*create_node_element(int i, int j)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node != NULL)
	{
		node->i = i;
		node->j = j;
		node->prev = NULL;
		node->next = NULL;
	}
	return (node);
}

void	enqueue_node(t_queue *queue, t_node *node)
{
	if (queue->first == NULL && queue->last == NULL)
	{
		queue->first = node;
		queue->last = node;
	}
	else
	{
		node->next = queue->last;
		queue->last->prev = node;
		queue->last = node;
	}
}

void	dequeue_node(t_queue *queue)
{
	t_node	*aux;

	aux = queue->first;
	if (aux->prev)
	{
		queue->first = aux->prev;
		queue->first->next = NULL;
	}
	else
		queue->first = NULL;
	free(aux);
}
