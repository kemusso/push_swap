/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftakemur <ftakemur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 16:30:09 by ftakemur          #+#    #+#             */
/*   Updated: 2025/09/21 16:30:27 by ftakemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **stack_a)
{
	int	i0;
	int	i1;
	int	i2;

	i0 = (*stack_a)->index;
	i1 = (*stack_a)->next->index;
	i2 = (*stack_a)->next->next->index;
	if (i0 > i1 && i1 < i2 && i0 < i2)
		sa(stack_a);
	else if (i0 > i1 && i1 > i2)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (i0 > i1 && i1 < i2 && i0 > i2)
		ra(stack_a);
	else if (i0 < i1 && i1 > i2 && i0 < i2)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (i0 < i1 && i1 > i2 && i0 > i2)
		rra(stack_a);
}

static int	find_smallest_index_pos(t_node *stack)
{
	int		i;
	int		size;
	int		min_index;
	int		min_pos;
	t_node	*current;

	i = 0;
	min_pos = 0;
	min_index = stack->index;
	size = get_list_size(stack);
	current = stack;
	while (i < size)
	{
		if (current->index < min_index)
		{
			min_index = current->index;
			min_pos = i;
		}
		current = current->next;
		i++;
	}
	return (min_pos);
}

void	sort_five(t_node **stack_a, t_node **stack_b)
{
	int	size;
	int	pos;
	int	i;

	size = get_list_size(*stack_a);
	while (size > 3)
	{
		pos = find_smallest_index_pos(*stack_a);
		i = 0;
		if (pos <= get_list_size(*stack_a) / 2)
		{
			while (i++ < pos)
				ra(stack_a);
		}
		else
		{
			while (i++ < get_list_size(*stack_a) - pos)
				rra(stack_a);
		}
		pb(stack_a, stack_b);
		size--;
	}
	sort_three(stack_a);
	while (*stack_b != NULL)
		pa(stack_a, stack_b);
}

void	radix_sort(t_node **stack_a, t_node **stack_b)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	size = get_list_size(*stack_a);
	max_bits = 0;
	while (((size - 1) >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*stack_a)->index >> i) & 1) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			j++;
		}
		while (get_list_size(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}
