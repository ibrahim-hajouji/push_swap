/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:19:50 by ihajouji          #+#    #+#             */
/*   Updated: 2024/03/23 17:52:32 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0' || (str[0] == ' ' && str[1] == '\0'))
		ft_error();
}

void	check_duplicate(int *arr, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (arr[i] == arr[j])
				ft_error();
			j++;
		}
		i++;
	}
}
