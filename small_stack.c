/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:18:22 by ihajouji          #+#    #+#             */
/*   Updated: 2024/03/25 21:15:10 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_two(t_stack *stack_a)
{
	if (stack_a->stack_array[1] > stack_a->stack_array[0])
		sa(stack_a, 1);
	else
		return ;
}

void	handle_three(t_stack *stack_a)
{
	int	i;
	int	highest;

	i = stack_a->top;
	highest = stack_a->stack_array[i];
	while (i > 0)
	{
		if (highest < stack_a->stack_array[i - 1])
			highest = stack_a->stack_array[i - 1];
		i--;
	}
	i = stack_a->top;
	if (stack_a->stack_array[i] == highest)
		ra(stack_a, 1);
	else if (stack_a->stack_array[--i] == highest)
		rra(stack_a, 1);
	i = stack_a->top;
	if (stack_a->stack_array[i] > stack_a->stack_array[i - 1])
		sa(stack_a, 1);
}

void	handle_four(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	lowest;

	i = stack_a->top;
	lowest = stack_a->stack_array[i];
	while (i > 0)
	{
		if (lowest > stack_a->stack_array[i - 1])
			lowest = stack_a->stack_array[i - 1];
		i--;
	}
	i = stack_a->top;
	if (stack_a->stack_array[i - 1] == lowest)
		sa(stack_a, 1);
	if (stack_a->stack_array[i - 2] == lowest)
		rra(stack_a, 1);
	if (stack_a->stack_array[i - 3] == lowest)
		rra(stack_a, 1);
	if (!already_sorted(stack_a))
	{
		pb(stack_a, stack_b, 1);
		handle_three(stack_a);
		pa(stack_a, stack_b, 1);
	}
}

void	get_lowest(t_stack *stack_a)
{
	int	i;
	int	lowest;

	i = stack_a->top;
	lowest = stack_a->stack_array[i];
	while (i >= 0)
	{
		if (lowest > stack_a->stack_array[i])
			lowest = stack_a->stack_array[i];
		i--;
	}
	if (stack_a->stack_array[3] == lowest)
		ra(stack_a, 1);
	else if (stack_a->stack_array[2] == lowest)
	{
		ra(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (stack_a->stack_array[1] == lowest)
	{
		rra(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (stack_a->stack_array[0] == lowest)
		rra(stack_a, 1);
}

void	handle_five(t_stack *stack_a, t_stack *stack_b)
{
	get_lowest(stack_a);
	if (!already_sorted(stack_a))
	{
		pb(stack_a, stack_b, 1);
		handle_four(stack_a, stack_b);
		pa(stack_a, stack_b, 1);
	}
}
