/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_five_numbers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:48:08 by nholbroo          #+#    #+#             */
/*   Updated: 2024/02/21 14:59:48 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	ft_find_lowest(t_list **a, int lowest)
{
	t_list	*node;

	node = *a;
	lowest = 0;
	while (node && node->index != 0)
	{
		node = node->next;
		lowest++;
	}
	return (lowest);
}

static void	first_is_greater_than_next(t_list **a, t_list *node)
{
	if (node->value > node->next->next->value)
	{
		ra(a, false);
		node = *a;
		if (node->value > node->next->value)
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
	if (node->value > node->next->value)
		sa(a);
}

static void	ft_sort_three_of_five_numbers(t_list **a, t_list **b)
{
	t_list	*node;

	node = *a;
	if (node->value > node->next->value)
		first_is_greater_than_next(a, node);
	else if (node->value > node->next->next->value)
		first_is_greater_than_after_next(a, node);
	else if (node->next->value > node->next->next->value)
	{
		rra(a, false);
		sa(a);
	}
	pa(a, b);
	pa(a, b);
}

void	ft_sort_five_numbers(t_list **a, t_list **b)
{
	int		lowest;
	int		seclowest;

	lowest = 0;
	seclowest = 0;
	lowest = ft_find_lowest(a, lowest);
	if (lowest == 0 || lowest == 1)
		ft_lowest_is_zero_or_one(a, b, lowest);
	else if (lowest == 2 || lowest == 3 || lowest == 4)
		ft_lowest_is_two_three_or_four(a, b, lowest);
	seclowest = ft_find_seclowest(a, seclowest);
	if (seclowest == 0 || seclowest == 1)
		ft_seclowest_zero_or_one(a, b, seclowest);
	else if (seclowest == 2 || seclowest == 3)
		ft_seclowest_two_or_three(a, b, seclowest);
	ft_sort_three_of_five_numbers(a, b);
	ft_finish_sort(a);
}
