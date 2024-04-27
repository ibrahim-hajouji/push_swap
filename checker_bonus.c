/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:51:28 by ihajouji          #+#    #+#             */
/*   Updated: 2024/03/25 21:04:11 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	sort_array(t_stack *stack_a)
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

int	arr_cmp(int *arr, int *arr2, int len, int len2)
{
	int	i;
	int	j;

	i = len;
	j = len2;
	while (i >= 0 && j >= 0)
	{
		if (arr[i] == arr2[j])
		{
			i--;
			j--;
		}
		else
			return (0);
	}
	return (1);
}

void	checker(t_stack *stack_a, t_stack *stack_b, int count)
{
	char	*str;
	t_stack	*sorted;

	sorted = NULL;
	sorted = fill_stack(sorted, stack_a->stack_array, count);
	sorted->top = count - 1;
	sort_array(sorted);
	while (1)
	{
		str = get_next_line(0);
		if (str == NULL)
			break ;
		check_operation(str);
		do_(str, stack_a, stack_b);
		free(str);
	}
	if (arr_cmp(sorted->stack_array, stack_a->stack_array, count - 1,
			stack_a->top))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(sorted);
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
		checker(stack_a, stack_b, count);
		free(stack_a->stack_array);
		free(stack_a);
		free(stack_b->stack_array);
		free(stack_b);
	}
}
