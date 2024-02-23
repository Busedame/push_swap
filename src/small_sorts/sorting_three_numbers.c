/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_three_numbers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:47:28 by nholbroo          #+#    #+#             */
/*   Updated: 2024/02/22 16:40:43 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	first_is_greater_than_next(t_list **a, t_list **b, t_list *node)
{
	if (node->index > node->next->next->index)
	{
		ra(a, false);
		node = *a;
		if (node->index > node->next->index)
			sa(a);
		if (!(*b))
			ft_finish_sort(a);
	}
	else
	{
		sa(a);
		node = *a;
		if (!(*b))
			ft_finish_sort(a);
	}
}

static void	first_greater_than_after_next(t_list **a, t_list **b, t_list *node)
{
	rra(a, false);
	if (node->index > node->next->index)
		sa(a);
	if (!(*b))
		ft_finish_sort(a);
}

void	ft_sort_three_numbers(t_list **a, t_list **b)
{
	t_list	*node;

	node = *a;
	if (ft_is_sorted(*a))
		return ;
	if (node->index > node->next->index)
		first_is_greater_than_next(a, b, node);
	else if (node->index > node->next->next->index)
		first_greater_than_after_next(a, b, node);
	else
	{
		rra(a, false);
		sa(a);
		if (!(*b))
			ft_finish_sort(a);
	}
}
