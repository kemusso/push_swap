/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftakemur <ftakemur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 16:09:18 by ftakemur          #+#    #+#             */
/*   Updated: 2025/09/21 16:11:08 by ftakemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *stack)
{
	t_node	*current;
	int		size;
	int		i;

	if (stack == NULL)
		return (1);
	size = get_list_size(stack);
	current = stack;
	i = 0;
	while (i < size - 1)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
		i++;
	}
	return (1);
}

int	get_list_size(t_node *head)
{
	int		size;
	t_node	*current;

	if (head == NULL)
		return (0);
	size = 1;
	current = head->next;
	while (current != head)
	{
		size++;
		current = current->next;
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
	while (i < size)
	{
		arr[i] = current->value;
		current = current->next;
		i++;
	}
	merge_sort(arr, 0, size - 1);
	return (arr);
}

static void	set_indices_from_array(t_node *stack, int *sorted_arr, int size)
{
	t_node	*current;
	int		i;
	int		j;

	j = 0;
	current = stack;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			if (current->value == sorted_arr[i])
			{
				current->index = i;
				break ;
			}
			i++;
		}
		current = current->next;
		j++;
	}
}

int	assign_index(t_node *stack)
{
	int	*sorted_array;
	int	size;

	if (stack == NULL)
		return (0);
	size = get_list_size(stack);
	sorted_array = create_sorted_array(stack, size);
	if (sorted_array == NULL)
		return (0);
	set_indices_from_array(stack, sorted_array, size);
	free(sorted_array);
	return (size);
}
