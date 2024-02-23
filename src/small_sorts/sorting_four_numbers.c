/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_four_numbers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:48:08 by nholbroo          #+#    #+#             */
/*   Updated: 2024/02/21 13:59:55 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	first_is_greater_than_next(t_list **a, t_list *node)
{
	if (node->index > node->next->next->index)
	{
		ra(a, false);
		node = *a;
		if (node->index > node->next->index)
			sa(a);
	}
	else
	{
		sa(a);
		node = *a;
	}
}

static void	first_is_greater_than_after_next(t_list **a, t_list *node)
{
	rra(a, false);
	if (node->index > node->next->index)
		sa(a);
}

static void	ft_sort_three_of_four_numbers(t_list **a)
{
	t_list	*node;

	node = *a;
	if (node->index > node->next->index)
		first_is_greater_than_next(a, node);
	else if (node->index > node->next->next->index)
		first_is_greater_than_after_next(a, node);
	else if (node->next->index > node->next->next->index)
	{
		rra(a, false);
		sa(a);
	}
}

static void	ft_count_is_two_or_three(t_list **a, t_list **b, int count)
{
	if (count == 2)
	{
		rra(a, false);
		rra(a, false);
		pb(a, b);
		ft_sort_three_of_four_numbers(a);
	}
	else if (count == 3)
	{
		rra(a, false);
		pb(a, b);
		ft_sort_three_of_four_numbers(a);
	}
}

void	ft_sort_four_numbers(t_list **a, t_list **b)
{
	t_list	*node;
	int		count;

	node = *a;
	count = 0;
	while (node && node->index != 0)
	{
		node = node->next;
		count++;
	}
	if (count == 0)
	{
		pb(a, b);
		ft_sort_three_of_four_numbers(a);
	}
	else if (count == 1)
	{
		sa(a);
		pb(a, b);
		ft_sort_three_of_four_numbers(a);
	}
	else if (count == 2 || count == 3)
		ft_count_is_two_or_three(a, b, count);
	pa(a, b);
	ft_finish_sort(a);
}
