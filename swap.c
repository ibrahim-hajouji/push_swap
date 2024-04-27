/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:11:33 by ihajouji          #+#    #+#             */
/*   Updated: 2024/03/25 04:42:57 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a, int a)
{
	int	temp;

	if (stack_a->top <= 0)
		return ;
	temp = stack_a->stack_array[stack_a->top];
	stack_a->stack_array[stack_a->top] = stack_a->stack_array[stack_a->top - 1];
	stack_a->stack_array[stack_a->top - 1] = temp;
	if (a)
		write(1, "sa\n", 3);
}

void	sb(t_stack *stack_b, int a)
{
	int	temp;

	if (stack_b->top <= 0)
		return ;
	temp = stack_b->stack_array[stack_b->top];
	stack_b->stack_array[stack_b->top] = stack_b->stack_array[stack_b->top - 1];
	stack_b->stack_array[stack_b->top - 1] = temp;
	if (a)
		write(1, "sb\n", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b, int a)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	if (a == 1)
		write(1, "ss\n", 3);
}
