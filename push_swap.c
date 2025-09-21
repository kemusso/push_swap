/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 16:34:02 by marvin            #+#    #+#             */
/*   Updated: 2025/09/21 10:28:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_node **stack)
{
	t_node	*current;
	t_node	*tmp;

	if (stack == NULL || *stack == NULL)
		return ;
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
	t_node	*stock_a;
	t_node	*stock_b;
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
	sort_list(&stack_a);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
