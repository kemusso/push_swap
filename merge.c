/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 15:55:55 by marvin            #+#    #+#             */
/*   Updated: 2025/09/19 15:56:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_merge_data	prepare_merge_data(int *arr, int left, int mid, int right)
{
	t_merge_data	data;
	int				i;

	data.n1 = mid - left + 1;
	data.n2 = right - mid;
	data.l_arr = (int *)malloc(sizeof(int) * data.n1);
	data.r_arr = (int *)malloc(sizeof(int) * data.n2);
	i = 0;
	while (i < data.n1)
	{
		data.l_arr[i] = arr[left + i];
		i++;
	}
	i = 0;
	while (i < data.n2)
	{
		data.r_arr[i] = arr[mid + 1 + i];
		i++;
	}
	return (data);
}

void	do_merge(int *arr, int left, t_merge_data data)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = left;
	while (i < data.n1 && j < data.n2)
	{
		if (data.l_arr[i] <= data.r_arr[j])
			arr[k++] = data.l_arr[i++];
		else
			arr[k++] = data.r_arr[j++];
	}
	while (i < data.n1)
		arr[k++] = data.l_arr[i++];
	while (j < data.n2)
		arr[k++] = data.r_arr[j++];
}

void	merge(int *arr, int left, int mid, int right)
{
	t_merge_data	data;

	data = prepare_merge_data(arr, left, mid, right);
	do_merge(arr, left, data);
	free(data.l_arr);
	free(data.r_arr);
}

void	merge_sort(int *arr, int left, int right)
{
	int	mid;

	if (left < right)
	{
		mid = left + (right - left) / 2;
		merge_sort(arr, left, mid);
		merge_sort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}
