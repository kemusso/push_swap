/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftakemur <ftakemur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 16:06:57 by ftakemur          #+#    #+#             */
/*   Updated: 2025/09/21 21:23:36 by ftakemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_node **stack)
{
	t_node	*current;
	t_node	*last;
	t_node	*tmp;

	if (stack == NULL || *stack == NULL)
		return ;
	last = (*stack)->prev;
	last->next = NULL;
	current = *stack;
	while (current != NULL)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	handle_error(t_node **stack_a)
{
	if (stack_a != NULL)
		free_stack(stack_a);
	write(2, "Error\n", 6);
	exit(1);
}

t_node	*build_stack_from_args(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*new_node;
	int		i;
	int		number;

	i = 1;
	stack_a = NULL;
	if (!are_args_valid(argc, argv))
		return (NULL);
	while (i < argc)
	{
		number = ft_atoi(argv[i]);
		new_node = create_new_node(number);
		if (new_node == NULL)
			return (free_stack(&stack_a), NULL);
		add_node_to_back(&stack_a, new_node);
		i++;
	}
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	stack_a = build_stack_from_args(argc, argv);
	if (stack_a == NULL)
		handle_error(&stack_a);
	if (is_sorted(stack_a))
		return (free_stack(&stack_a), 0);
	size = assign_index(stack_a);
	if (size == 2)
		sa(&stack_a);
	else if (size == 3)
		sort_three(&stack_a);
	else if (size <= 5)
		sort_five(&stack_a, &stack_b);
	else
		radix_sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
