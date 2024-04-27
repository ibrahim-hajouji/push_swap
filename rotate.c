/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:53:35 by ihajouji          #+#    #+#             */
/*   Updated: 2024/03/25 04:42:08 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack_a, int a)
{
	int	i;
	int	temp;

	i = stack_a->top;
	if (stack_a->top <= 0)
		return ;
	temp = stack_a->stack_array[stack_a->top];
	while (i > 0)
	{
		stack_a->stack_array[i] = stack_a->stack_array[i - 1];
		i--;
	}
	stack_a->stack_array[0] = temp;
	if (a)
		write(1, "ra\n", 3);
}

void	rb(t_stack *stack_b, int a)
{
	int	i;
	int	temp;

	i = stack_b->top;
	if (stack_b->top <= 0)
		return ;
	temp = stack_b->stack_array[stack_b->top];
	while (i > 0)
	{
		stack_b->stack_array[i] = stack_b->stack_array[i - 1];
		i--;
	}
	stack_b->stack_array[0] = temp;
	if (a)
		write(1, "rb\n", 3);
}

void	rr(t_stack *stack_a, t_stack *stack_b, int a)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (a == 1)
		write(1, "rr\n", 3);
}
