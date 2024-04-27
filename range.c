/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:29:54 by ihajouji          #+#    #+#             */
/*   Updated: 2024/03/25 06:58:56 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min(t_stack *stack)
{
	int	minimum;
	int	i;

	i = stack->top;
	minimum = stack->stack_array[i];
	while (i >= 0)
	{
		if (minimum > stack->stack_array[i])
			minimum = stack->stack_array[i];
		i--;
	}
	return (minimum);
}

int	get_index_min(t_stack *stack, int min, int count)
{
	int	i;

	i = 0;
	while (i <= count)
	{
		if (stack->stack_array[i] == min)
			return (i);
		i++;
	}
	return (0);
}

void	b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	middle;
	int	minimum;
	int	i;

	while (stack_b->top >= 0)
	{
		middle = stack_b->top / 2;
		minimum = min(stack_b);
		i = get_index_min(stack_b, minimum, stack_b->top);
		if (i < middle)
		{
			while (stack_b->stack_array[stack_b->top] != minimum)
				rrb(stack_b, 1);
		}
		else
		{
			while (stack_b->stack_array[stack_b->top] != minimum)
				rb(stack_b, 1);
		}
		pa(stack_a, stack_b, 1);
	}
}

void	range(t_stack *stack_a, t_stack *stack_b, int start, int end)
{
	while (stack_a->top >= 0)
	{
		if (stack_a->stack_array[stack_a->top] <= start)
		{
			pb(stack_a, stack_b, 1);
			rb(stack_b, 1);
			start++;
			end++;
		}
		else if ((stack_a->stack_array[stack_a->top] > start)
			&& (stack_a->stack_array[stack_a->top] < end))
		{
			pb(stack_a, stack_b, 1);
			start++;
			end++;
		}
		else if (stack_a->stack_array[stack_a->top] >= end)
			ra(stack_a, 1);
	}
	b_to_a(stack_a, stack_b);
}

void	sort_lot(t_stack *stack_a, t_stack *stack_b, int count)
{
	t_stack	*temp;

	temp = 0;
	temp = fill_stack(temp, stack_a->stack_array, count);
	temp->top = count - 1;
	sort_arr(temp);
	fill_index(stack_a, temp, count);
	free(temp);
	range(stack_a, stack_b, 0, 30);
}
