/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 17:35:02 by marvin            #+#    #+#             */
/*   Updated: 2025/09/19 16:29:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *stack)
{
	if (stack == NULL || stack->next == NULL)
		return (1);
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	get_list_size(t_node *head)
{
	int	size;

	size = 0;
	while (head != NULL)
	{
		size++;
		head = head->next;
	}
	return (size);
}


static int	*create_sorted_array(t_node *stack, int size)
{
	int		*arr;
	int		i;
	t_node	*current;

	arr = (int *)malloc(sizeof(int) * size);
	if (arr == NULL)
		return (NULL);
	i = 0;
	current = stack;
	while (current != NULL)
	{
		arr[i] = current->value;
		current = current->next;
		i++;
	}
	merge_sort(arr, 0, size - 1);
	return (arr);
}

static void	set_index_from_array(t_node *stack, int *sorted_arr, int size)
{
	t_node	*current;
	int		i;

	current = stack;
	while (current != NULL)
	{
		i = 0;
		while (i < size)
		{
			if (current->value == sorted_arr[i])
			{
				current->index = i;
				break;
			}
			i++;
		}
		current = current->next;
	}
}

int assign_index(t_node *stack)
{
	int	*sorted_array;
	int	size;

	if (stack == NULL)
		return -1;
	size = get_list_size(stack);
	sorted_array = create_sorted_array(stack, size);
	if (sorted_array == NULL)
		return -2;
	set_index_from_array(stack, sorted_array, size);
	free(sorted_array);
	return size;
}
