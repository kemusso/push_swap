/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftakemur <ftakemur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 21:23:47 by ftakemur          #+#    #+#             */
/*   Updated: 2025/09/21 21:58:12 by ftakemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static const char	*parse_num_info(const char *str, int *sign, int *len)
{
	const char	*num_start;

	*sign = 1;
	*len = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*sign = -1;
		str++;
	}
	num_start = str;
	while (*num_start >= '0' && *num_start <= '9')
	{
		(*len)++;
		num_start++;
	}
	return (str);
}

long	ft_atol_by_len(const char *str)
{
	long		result;
	int			sign;
	int			digit_len;
	const char	*num_start;

	result = 0;
	num_start = parse_num_info(str, &sign, &digit_len);
	if (digit_len > 10)
		return (LONG_MAX);
	while (*num_start >= '0' && *num_start <= '9')
	{
		result = result * 10 + (*num_start - '0');
		num_start++;
	}
	return (result * sign);
}
