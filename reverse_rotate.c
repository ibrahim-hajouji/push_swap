/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 13:39:59 by ihajouji          #+#    #+#             */
/*   Updated: 2024/03/25 04:37:57 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack_a, int a)
{
	int	temp;
	int	i;

	i = 0;
	if (stack_a->top < 0)
		return ;
	temp = stack_a->stack_array[0];
	while (i < stack_a->top)
	{
		stack_a->stack_array[i] = stack_a->stack_array[i + 1];
		i++;
	}
	stack_a->stack_array[stack_a->top] = temp;
	if (a)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *stack_b, int a)
{
	int	temp;
	int	i;

	i = 0;
	if (stack_b->top < 0)
		return ;
	temp = stack_b->stack_array[0];
	while (i < stack_b->top)
	{
		stack_b->stack_array[i] = stack_b->stack_array[i + 1];
		i++;
	}
	stack_b->stack_array[stack_b->top] = temp;
	if (a)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack_a, t_stack *stack_b, int a)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (a == 1)
		write(1, "rrr\n", 4);
}
