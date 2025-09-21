/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 17:06:03 by marvin            #+#    #+#             */
/*   Updated: 2025/08/11 14:26:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*node_to_move;

	if (*stack_a == NULL)
		return ;
	node_to_move = *stack_a;
	*stack_a = (*stack_a)->next;
	node_to_move->next = *stack_b;
	*stack_b = node_to_move;
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*node_to_move;

	if (*stack_b == NULL)
		return;

	node_to_move = *stack_b;
	*stack_b = (*stack_b)->next;
	node_to_move->next = *stack_a;
	*stack_a = node_to_move;
}
