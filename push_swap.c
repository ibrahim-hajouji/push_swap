/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:11:29 by ihajouji          #+#    #+#             */
/*   Updated: 2024/03/25 21:02:39 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack *stack_a, t_stack *stack_b, int count)
{
	if (!already_sorted(stack_a))
	{
		if (count == 2)
			handle_two(stack_a);
		else if (count == 3)
			handle_three(stack_a);
		else if (count == 4)
			handle_four(stack_a, stack_b);
		else if (count == 5)
			handle_five(stack_a, stack_b);
		else
			handle_lot(stack_a, stack_b, count);
	}
}

int	main(int ac, char **av)
{
	int		count;
	int		*arr;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac > 1)
	{
		count = ft_count(av);
		arr = fill_array(av, count);
		check_duplicate(arr, count);
		stack_a = fill_stack(stack_a, arr, count);
		stack_b = allocate_stack(stack_b, count);
		free(arr);
		stack_a->top = count - 1;
		stack_b->top = -1;
		sort(stack_a, stack_b, count);
		free(stack_a->stack_array);
		free(stack_b->stack_array);
		free(stack_a);
		free(stack_b);
	}
}
