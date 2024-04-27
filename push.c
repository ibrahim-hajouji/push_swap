/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 11:57:29 by ihajouji          #+#    #+#             */
/*   Updated: 2024/03/24 17:04:04 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *s_a, t_stack *s_b, int a)
{
	if (s_b->top < 0)
		return ;
	s_a->top++;
	s_a->stack_array[s_a->top] = s_b->stack_array[s_b->top];
	s_b->top--;
	if (a == 1)
		write(1, "pa\n", 3);
}

void	pb(t_stack *s_a, t_stack *s_b, int a)
{
	if (s_a->top < 0)
		return ;
	s_b->top++;
	s_b->stack_array[s_b->top] = s_a->stack_array[s_a->top];
	s_a->top--;
	if (a == 1)
		write(1, "pb\n", 3);
}
