/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftakemur <ftakemur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 16:07:32 by ftakemur          #+#    #+#             */
/*   Updated: 2025/09/21 22:02:15 by ftakemur         ###   ########.fr       */
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
		num = ft_atol_by_len(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (0);
		j = i + 1;
		while (j < argc)
		{
			com = ft_atol_by_len(argv[j]);
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
	new_node->index = -1;
	new_node->next = new_node;
	new_node->prev = new_node;
	return (new_node);
}

void	add_node_to_back(t_node **head, t_node *new_node)
{
	t_node	*last;

	if (head == NULL || new_node == NULL)
		return ;
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	last = (*head)->prev;
	new_node->next = *head;
	new_node->prev = last;
	(*head)->prev = new_node;
	last->next = new_node;
}

void	add_node_to_front(t_node **head, t_node *new_node)
{
	if (head == NULL || new_node == NULL)
		return ;
	add_node_to_back(head, new_node);
	*head = new_node;
}
