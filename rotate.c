/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftakemur <ftakemur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 16:08:09 by ftakemur          #+#    #+#             */
/*   Updated: 2025/09/21 16:08:10 by ftakemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **stack_a)
{
	if (stack_a != NULL && *stack_a != NULL)
		*stack_a = (*stack_a)->next;
	ft_printf("ra\n");
}

void	rb(t_node **stack_b)
{
	if (stack_b != NULL && *stack_b != NULL)
		*stack_b = (*stack_b)->next;
	ft_printf("rb\n");
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	if (stack_a != NULL && *stack_a != NULL)
		*stack_a = (*stack_a)->next;
	if (stack_b != NULL && *stack_b != NULL)
		*stack_b = (*stack_b)->next;
	ft_printf("rr\n");
}
