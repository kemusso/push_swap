/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftakemur <ftakemur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 16:08:32 by ftakemur          #+#    #+#             */
/*   Updated: 2025/09/21 16:08:33 by ftakemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node **stack_a)
{
	if (stack_a != NULL && *stack_a != NULL)
		*stack_a = (*stack_a)->prev;
	ft_printf("rra\n");
}

void	rrb(t_node **stack_b)
{
	if (stack_b != NULL && *stack_b != NULL)
		*stack_b = (*stack_b)->prev;
	ft_printf("rrb\n");
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	if (stack_a != NULL && *stack_a != NULL)
		*stack_a = (*stack_a)->prev;
	if (stack_b != NULL && *stack_b != NULL)
		*stack_b = (*stack_b)->prev;
	ft_printf("rrr\n");
}
