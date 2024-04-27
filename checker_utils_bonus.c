/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:26:48 by ihajouji          #+#    #+#             */
/*   Updated: 2024/03/24 22:54:29 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

void	check_operation(char *str)
{
	if (ft_strcmp(str, "sa\n") || ft_strcmp(str, "sb\n") || ft_strcmp(str,
			"ss\n") || ft_strcmp(str, "ra\n") || ft_strcmp(str, "rb\n")
		|| ft_strcmp(str, "rr\n") || ft_strcmp(str, "pa\n") || ft_strcmp(str,
			"pb\n") || ft_strcmp(str, "rra\n") || ft_strcmp(str, "rrb\n")
		|| ft_strcmp(str, "rrr\n"))
		return ;
	else
	{
		write(2, "Error\n", 6);
		exit(0);
	}
}

void	do_(char *str, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strcmp(str, "sa\n"))
		sa(stack_a, 0);
	else if (ft_strcmp(str, "sb\n"))
		sb(stack_b, 0);
	else if (ft_strcmp(str, "ss\n"))
		ss(stack_a, stack_b, 0);
	else if (ft_strcmp(str, "ra\n"))
		ra(stack_a, 0);
	else if (ft_strcmp(str, "rb\n"))
		rb(stack_b, 0);
	else if (ft_strcmp(str, "rr\n"))
		rr(stack_a, stack_b, 0);
	else if (ft_strcmp(str, "rra\n"))
		rra(stack_a, 0);
	else if (ft_strcmp(str, "rrb\n"))
		rrb(stack_b, 0);
	else if (ft_strcmp(str, "rrr\n"))
		rrr(stack_a, stack_b, 0);
	else if (ft_strcmp(str, "pa\n"))
		pa(stack_a, stack_b, 0);
	else if (ft_strcmp(str, "pb\n"))
		pb(stack_a, stack_b, 0);
}
