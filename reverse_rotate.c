/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:32:36 by marvin            #+#    #+#             */
/*   Updated: 2025/08/11 14:33:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node **stack_a)
{
	t_node	*last;
	t_node	*before_last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	before_last = *stack_a;
	last = (*stack_a)->next;
	while (last->next != NULL)
	{
		before_last = before_last->next;
		last = last->next;
	}
	last->next = *stack_a;
	*stack_a = last;
	before_last->next = NULL;
}

void	rrb(t_node **stack_b)
{
	t_node	*last;
	t_node	*before_last;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	before_last = *stack_b;
	last = (*stack_b)->next;
	while (last->next != NULL)
	{
		before_last = before_last->next;
		last = last->next;
	}
	last->next = *stack_b;
	*stack_b = last;
	before_last->next = NULL;
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
