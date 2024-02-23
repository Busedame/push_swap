/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_target.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:58:56 by nholbroo          #+#    #+#             */
/*   Updated: 2024/02/23 17:25:48 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_reset_targets(t_list **x)
{
	t_list	*currnode;

	currnode = *x;
	while (currnode)
	{
		currnode->target = NULL;
		currnode = currnode->next;
	}
}

static void	get_target_in_b(t_list *curr_a, t_list **b, long closest_lower)
{
	t_list	*curr_b;

	curr_b = *b;
	while (curr_b)
	{
		if (curr_b->value < curr_a->value
			&& curr_b->value > closest_lower)
		{
			closest_lower = curr_b->value;
			curr_a->target = curr_b;
		}
		curr_b = curr_b->next;
	}
}

static void	get_target_in_a(t_list **a, t_list *curr_b, long closest_greater)
{
	t_list	*curr_a;

	curr_a = *a;
	while (curr_a)
	{
		if (curr_a->value > curr_b->value
			&& curr_a->value < closest_greater)
		{
			closest_greater = curr_a->value;
			curr_b->target = curr_a;
		}
		curr_a = curr_a->next;
	}
}

void	ft_target_node_in_a(t_list **a, t_list **b)
{
	t_list	*curr_b;
	long	closest_greater;

	curr_b = *b;
	i = 0;
	ft_reset_targets(b);
	while (curr_b)
	{
		closest_greater = LONG_MAX;
		get_target_in_a(a, curr_b, closest_greater);
		if (curr_b->target == NULL)
			ft_find_smallest_value_in_a(curr_b, a);
		curr_b = curr_b->next;
	}
}

void	ft_target_node_in_b(t_list **a, t_list **b)
{
	t_list	*curr_a;
	long	closest_lower;

	curr_a = *a;
	ft_reset_targets(a);
	while (curr_a)
	{
		closest_lower = LONG_MIN;
		get_target_in_b(curr_a, b, closest_lower);
		if (curr_a->target == NULL)
			ft_find_greatest_value_in_b(b, curr_a);
		curr_a = curr_a->next;
	}
}
