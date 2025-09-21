/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftakemur <ftakemur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 16:08:59 by ftakemur          #+#    #+#             */
/*   Updated: 2025/09/21 16:09:00 by ftakemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **stack_a)
{
	t_node	*first;
	t_node	*second;

	if (*stack_a == NULL || (*stack_a)->next == *stack_a)
		return ;
	first = *stack_a;
	second = first->next;
	first->next = second->next;
	second->next->prev = first;
	second->next = first;
	second->prev = first->prev;
	first->prev->next = second;
	first->prev = second;
	*stack_a = second;
	ft_printf("sa\n");
}

void	sb(t_node **stack_b)
{
	t_node	*first;
	t_node	*second;

	if (*stack_b == NULL || (*stack_b)->next == *stack_b)
		return ;
	first = *stack_b;
	second = first->next;
	first->next = second->next;
	second->next->prev = first;
	second->next = first;
	second->prev = first->prev;
	first->prev->next = second;
	first->prev = second;
	*stack_b = second;
	ft_printf("sb\n");
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	t_node	*first_a;
	t_node	*second_a;
	t_node	*first_b;
	t_node	*second_b;

	if (*stack_a != NULL && (*stack_a)->next != *stack_a)
	{
		first_a = *stack_a;
		second_a = first_a->next;
		first_a->next = second_a->next;
		second_a->next->prev = first_a;
		second_a->next = first_a;
		second_a->prev = first_a->prev;
		first_a->prev->next = second_a;
		first_a->prev = second_a;
		*stack_a = second_a;
	}
	if (*stack_b != NULL && (*stack_b)->next != *stack_b)
	{
		first_b = *stack_b;
		second_b = first_b->next;
		first_b->next = second_b->next;
		second_b->next->prev = first_b;
		second_b->next = first_b;
		second_b->prev = first_b->prev;
		first_b->prev->next = second_b;
		first_b->prev = second_b;
		*stack_b = second_b;
	}
	ft_printf("ss\n");
}
