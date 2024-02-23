/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_sort_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:26:22 by nholbroo          #+#    #+#             */
/*   Updated: 2024/02/21 13:59:45 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// The different operations for sorting b.

void	sb(t_list **b)
{
	t_list	*tmp;
	t_list	*last;

	if (!*(b) || !(*b)->next)
		return ;
	tmp = *b;
	(*b) = (*b)->next;
	last = (*b);
	if (last->next)
	{
		tmp->next = last->next;
		last->next->previous = tmp;
	}
	else 
		tmp->next = NULL;
	tmp->previous = last;
	last->next = tmp;
	last->previous = NULL;
	*b = last;
	ft_print_operation("sb");
}

void	rb(t_list **b, bool rotate_both)
{
	t_list	*last;
	t_list	*tmp;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	(*b) = (*b)->next;
	last = ft_last_node(*b);
	tmp->next = NULL;
	last->next = tmp;
	if (!rotate_both)
		ft_print_operation("rb");
}

void	rrb(t_list **b, bool rotate_both)
{
	t_list	*last;
	t_list	*beflast;
	t_list	*tmp;

	if (!*b || !(*b)->next)
		return ;
	last = ft_last_node(*b);
	beflast = ft_one_before_last_node(*b);
	tmp = *b;
	*b = last;
	(*b)->next = tmp;
	beflast->next = NULL;
	if (!rotate_both)
		ft_print_operation("rrb");
}

void	pa(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!*b)
		return ;
	tmp = (*b)->next;
	(*b)->next = *a;
	*a = *b;
	*b = tmp;
	ft_print_operation("pa");
}
