/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:28:15 by marvin            #+#    #+#             */
/*   Updated: 2025/08/11 14:32:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*find_last_node(t_node *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next != NULL)
	{
		head = head->next;
	}
	return (head);
}

void	ra(t_node **stack_a)
{
	t_node	*first;
	t_node	*last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	first = *stack_a;
	*stack_a = first->next;
	last = find_last_node(*stack_a);
	first->next = NULL;
	last->next = first;
}

void	rb(t_node **stack_b)
{
	t_node	*first;
	t_node	*last;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	first = *stack_b;
	*stack_b = first->next;
	last = find_last_node(*stack_b);
	first->next = NULL;
	last->next = first;
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}


