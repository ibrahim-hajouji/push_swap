/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 11:56:22 by ihajouji          #+#    #+#             */
/*   Updated: 2024/03/24 19:53:57 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	number;

	i = 0;
	sign = 1;
	number = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] == '\0')
		ft_error();
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			ft_error();
		else
			number = number * 10 + (str[i++] - '0');
	}
	if (number < INT_MIN || number > INT_MAX)
		ft_error();
	return (number * sign);
}

int	already_sorted(t_stack *stack)
{
	int	i;

	i = stack->top;
	while (i > 0)
	{
		if (stack->stack_array[i] > stack->stack_array[i - 1])
			return (0);
		i--;
	}
	return (1);
}
