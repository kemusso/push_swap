/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:45:15 by marvin            #+#    #+#             */
/*   Updated: 2025/09/19 16:16:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int	are_args_valid(int argc, char **argv)
{
	int		i;
	int		j;
	long	num;
	long	com;

	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			return (0);
		num = ft_atoi(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (0);
		j = i + 1;
		while (j < argc)
		{
			com = ft_atoi(argv[j]);
			if (num == com)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

t_node	*create_new_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node->value = value;
	new_node->index = 0;
	new_node->next = NULL;
	return (new_node);
}

void	add_node_to_back(t_node **head, t_node *new_node)
{
	t_node	*current;

	if (*head == NULL)
	{
		*head = new_node;
		return;
	}
	current = *head;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = new_node;
}
