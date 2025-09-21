/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftakemur <ftakemur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 16:07:55 by ftakemur          #+#    #+#             */
/*   Updated: 2025/09/21 19:44:01 by ftakemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*node_to_move;

	if (stack_a == NULL || *stack_a == NULL)
		return ;
	node_to_move = *stack_a;
	if (node_to_move->next == node_to_move)
		*stack_a = NULL;
	else
	{
		node_to_move->prev->next = node_to_move->next;
		node_to_move->next->prev = node_to_move->prev;
		*stack_a = node_to_move->next;
	}
	node_to_move->next = node_to_move;
	node_to_move->prev = node_to_move;
	add_node_to_front(stack_b, node_to_move);
	ft_printf("pb\n");
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*node_to_move;

	if (stack_b == NULL || *stack_b == NULL)
		return ;
	node_to_move = *stack_b;
	if (node_to_move->next == node_to_move)
		*stack_b = NULL;
	else
	{
		node_to_move->prev->next = node_to_move->next;
		node_to_move->next->prev = node_to_move->prev;
		*stack_b = node_to_move->next;
	}
	node_to_move->next = node_to_move;
	node_to_move->prev = node_to_move;
	add_node_to_front(stack_a, node_to_move);
	ft_printf("pa\n");
}
