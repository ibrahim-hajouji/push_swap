/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:39:18 by ihajouji          #+#    #+#             */
/*   Updated: 2024/03/26 14:27:19 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_arr(t_stack *stack_a)
{
	int	i;
	int	temp;

	i = stack_a->top;
	temp = stack_a->stack_array[i];
	while (i > 0)
	{
		if (stack_a->stack_array[i] > stack_a->stack_array[i - 1])
		{
			temp = stack_a->stack_array[i];
			stack_a->stack_array[i] = stack_a->stack_array[i - 1];
			stack_a->stack_array[i - 1] = temp;
			i = stack_a->top;
		}
		else
			i--;
	}
}

void	fill_index(t_stack *stack_a, t_stack *temp, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = 0;
		while (j < count)
		{
			if (stack_a->stack_array[i] == temp->stack_array[j])
			{
				stack_a->stack_array[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	sort_hundred(t_stack *stack_a, t_stack *stack_b, int count)
{
	t_stack	*temp;

	temp = 0;
	temp = fill_stack(temp, stack_a->stack_array, count);
	temp->top = count - 1;
	sort_arr(temp);
	fill_index(stack_a, temp, count);
	free(temp);
	range(stack_a, stack_b, 0, 5);
}

void	handle_lot(t_stack *stack_a, t_stack *stack_b, int count)
{
	if (count > 5 && count <= 100)
		sort_hundred(stack_a, stack_b, count);
	else
		sort_lot(stack_a, stack_b, count);
}
