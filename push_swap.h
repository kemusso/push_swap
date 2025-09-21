/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 16:33:14 by marvin            #+#    #+#             */
/*   Updated: 2025/09/21 10:26:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_merge_data
{
	int				*l_arr;
	int				*r_arr;
	int				n1;
	int				n2;
}					t_merge_data;

extern t_node		*stack_a;
extern t_node		*stack_b;

void				sa(t_node **stack_a);
void				sb(t_node **stack_b);
void				ss(t_node **stack_a, t_node **stack_b);

void				pa(t_node **stack_a, t_node **stack_b);
void				pb(t_node **stack_a, t_node **stack_b);

void				ra(t_node **stack_a);
void				rb(t_node **stack_b);
void				rr(t_node **stack_a, t_node **stack_b);

void				rra(t_node **stack_a);
void				rrb(t_node **stack_b);
void				rrr(t_node **stack_a, t_node **stack_b);

t_node				*create_new_node(int value);
void				add_node_to_back(t_node **head, t_node *new_node);
int					are_args_valid(int argc, char **argv);

int					is_sorted(t_node *stack);
int					assign_index(t_node *stack);

void				merge_sort(int *arr, int left, int right);

#endif
