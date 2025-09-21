/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftakemur <ftakemur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 16:06:21 by ftakemur          #+#    #+#             */
/*   Updated: 2025/09/21 22:00:45 by ftakemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_merge_data
{
	int				*l_arr;
	int				*r_arr;
	int				n1;
	int				n2;
}					t_merge_data;

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
void				add_node_to_front(t_node **head, t_node *new_node);
int					are_args_valid(int argc, char **argv);
int					is_sorted(t_node *stack);
int					assign_index(t_node *stack);
void				merge_sort(int *arr, int left, int right);
int					get_list_size(t_node *head);
void				free_stack(t_node **stack);
t_node				*build_stack_from_args(int argc, char **argv);
void				handle_error(t_node **stack_a);
void				sort_three(t_node **stack_a);
void				sort_five(t_node **stack_a, t_node **stack_b);
void				radix_sort(t_node **stack_a, t_node **stack_b);
long				ft_atol_by_len(const char *str);

#endif
