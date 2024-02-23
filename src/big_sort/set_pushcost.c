/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pushcost.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:09:36 by nholbroo          #+#    #+#             */
/*   Updated: 2024/02/21 13:58:45 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	ft_what_is_lowest_cost(t_list **x)
{
	t_list	*curr_x;
	long	lowestcost;

	curr_x = *x;
	lowestcost = LONG_MAX;
	if (curr_x->pushcost == 0)
		return (0);
	while (curr_x)
	{
		if (curr_x->pushcost < lowestcost)
			lowestcost = curr_x->pushcost;
		curr_x = curr_x->next;
	}
	return (lowestcost);
}

t_list	*ft_where_is_lowest_cost(t_list **x, int lowestcost)
{
	t_list	*curr_x;

	curr_x = *x;
	while (curr_x->pushcost != lowestcost)
		curr_x = curr_x->next;
	return (curr_x);
}

void	ft_reset_pushcost(t_list **x)
{
	t_list	*currnode;

	currnode = *x;
	while (currnode)
	{
		currnode->pushcost = -1;
		currnode = currnode->next;
	}
}

void	ft_pushcost_to_a(t_list **a, t_list **b)
{
	t_list	*curr_a;
	t_list	*curr_b;

	curr_a = *a;
	curr_b = *b;
	ft_median_and_currpos(a, b);
	while (curr_b)
	{
		curr_b->pushcost = curr_b->currpos;
		if (!curr_b->abovemedian)
			curr_b->pushcost = ft_stacklen(*b) - curr_b->currpos;
		if (curr_b->target->abovemedian)
			curr_b->pushcost += curr_b->target->currpos;
		else
			curr_b->pushcost += ft_stacklen(*a) - curr_b->target->currpos;
		curr_b = curr_b->next;
	}
}

void	ft_pushcost_to_b(t_list **a, t_list **b)
{
	t_list	*curr_a;
	t_list	*curr_b;

	curr_a = *a;
	curr_b = *b;
	ft_median_and_currpos(a, b);
	while (curr_a)
	{
		curr_a->pushcost = curr_a->currpos;
		if (!curr_a->abovemedian)
			curr_a->pushcost = ft_stacklen(*a) - curr_a->currpos;
		if (curr_a->target->abovemedian)
			curr_a->pushcost += curr_a->target->currpos;
		else
			curr_a->pushcost += ft_stacklen(*b) - curr_a->target->currpos;
		curr_a = curr_a->next;
	}
}
