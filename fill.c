/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:20:33 by ihajouji          #+#    #+#             */
/*   Updated: 2024/03/25 06:48:33 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count(char **av)
{
	int		i;
	int		j;
	int		count;
	char	**str;

	i = 1;
	count = 0;
	while (av[i])
	{
		j = 0;
		str = ft_split(av[i], ' ');
		while (str[j])
		{
			j++;
			count++;
		}
		ft_free(str, j);
		free(str);
		i++;
	}
	return (count);
}

int	*fill_array(char **av, int count)
{
	int		i;
	int		j;
	int		index;
	int		*arr;
	char	**str;

	index = 0;
	i = 1;
	arr = malloc(sizeof(int) * count);
	while (av[i])
	{
		j = 0;
		check(av[i]);
		str = ft_split(av[i], ' ');
		while (str[j])
		{
			arr[index] = ft_atoi(str[j]);
			index++;
			j++;
		}
		ft_free(str, j);
		free(str);
		i++;
	}
	return (arr);
}

t_stack	*allocate_stack(t_stack *stack, int count)
{
	stack = malloc(sizeof(t_stack));
	stack->stack_array = malloc(sizeof(int) * count);
	if (!stack)
		return (NULL);
	return (stack);
}

t_stack	*fill_stack(t_stack *stack, int *arr, int count)
{
	int	i;
	int	j;

	i = 0;
	j = count - 1;
	stack = allocate_stack(stack, count);
	while (i < count)
	{
		stack->stack_array[i] = arr[j];
		i++;
		j--;
	}
	return (stack);
}
