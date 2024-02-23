/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_and_max_value.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:29:33 by nholbroo          #+#    #+#             */
/*   Updated: 2024/02/21 13:58:42 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_find_greatest_value_in_b(t_list **b, t_list *a)
{
	long	i;
	t_list	*curr_b;

	i = LONG_MIN;
	curr_b = *b;
	while (curr_b)
	{
		if (curr_b->value > i)
		{
			i = curr_b->value;
			a->target = curr_b;
		}
		curr_b = curr_b->next;
	}
}

void	ft_find_smallest_value_in_a(t_list *b, t_list **a)
{
	long	i;
	t_list	*curr_a;

	i = LONG_MAX;
	curr_a = *a;
	while (curr_a)
	{
		if (curr_a->value < i)
		{
			i = curr_a->value;
			b->target = curr_a;
		}
		curr_a = curr_a->next;
	}
}
