/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:16:53 by ihajouji          #+#    #+#             */
/*   Updated: 2024/04/02 15:41:30 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	top;
	int	*stack_array;
}		t_stack;

/* error handling */
void	ft_error(void);
void	check(char *str);
void	check_duplicate(int *arr, int count);
void	ft_free(char **pointer, int count);

/* fillinig array && stack */
int		ft_count(char **av);
int		*fill_array(char **av, int count);
t_stack	*allocate_stack(t_stack *stack, int count);
t_stack	*fill_stack(t_stack *stack, int *arr, int count);

/* OPERATIONS */
void	pa(t_stack *stack_a, t_stack *stack_b, int a);
void	pb(t_stack *stack_a, t_stack *stack_b, int a);
void	sa(t_stack *stack_a, int a);
void	sb(t_stack *stack_b, int a);
void	ss(t_stack *stack_a, t_stack *stack_b, int a);
void	ra(t_stack *stack_a, int a);
void	rb(t_stack *stack_b, int a);
void	rr(t_stack *stack_a, t_stack *stack_b, int a);
void	rra(t_stack *stack_a, int a);
void	rrb(t_stack *stack_b, int a);
void	rrr(t_stack *stack_a, t_stack *stack_b, int a);

/* SORT */
void	sort(t_stack *stack_a, t_stack *stack_b, int count);
void	get_lowest(t_stack *stack_a);
void	handle_two(t_stack *stack_a);
void	handle_three(t_stack *stack_a);
void	handle_four(t_stack *stack_a, t_stack *stack_b);
void	handle_five(t_stack *stack_a, t_stack *stack_b);
void	sort_arr(t_stack *stack_a);
void	fill_index(t_stack *stack_a, t_stack *temp, int count);
void	sort_hundred(t_stack *stack_a, t_stack *stack_b, int count);
int		min(t_stack *stack);
int		get_index_min(t_stack *stack, int min, int count);
void	b_to_a(t_stack *stack_a, t_stack *stack_b);
void	range(t_stack *stack_a, t_stack *stack_b, int start, int end);
void	sort_lot(t_stack *stack_a, t_stack *stack_b, int count);
void	handle_lot(t_stack *stack_a, t_stack *stack_b, int count);

/* utils */
int		ft_atoi(char *str);
int		already_sorted(t_stack *stack);
char	**ft_split(char const *s, char c);

#endif
