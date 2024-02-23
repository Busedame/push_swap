/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_sort_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:26:22 by nholbroo          #+#    #+#             */
/*   Updated: 2024/02/21 13:59:40 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// The different operations for sorting a.

void	sa(t_list **a)
{
	t_list	*tmp;
	t_list	*last;

	if (!*(a) || !(*a)->next)
		return ;
	tmp = *a;
	(*a) = (*a)->next;
	last = (*a);
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
	*a = last;
	ft_print_operation("sa");
}

void	ra(t_list **a, bool rotboth)
{
	t_list	*last;
	t_list	*tmp;

	if (!*(a) || !(*a)->next)
		return ;
	tmp = *a;
	(*a) = (*a)->next;
	last = ft_last_node(*a);
	tmp->next = NULL;
	last->next = tmp;
	if (!rotboth)
		ft_print_operation("ra");
}

void	rra(t_list **a, bool rotboth)
{
	t_list	*last;
	t_list	*beflast;
	t_list	*tmp;

	if (!*(a) || !(*a)->next)
		return ;
	last = ft_last_node(*a);
	beflast = ft_one_before_last_node(*a);
	tmp = *a;
	*a = last;
	(*a)->next = tmp;
	beflast->next = NULL;
	if (!rotboth)
		ft_print_operation("rra");
}

void	pb(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!*a)
		return ;
	tmp = (*a)->next;
	(*a)->next = *b;
	*b = *a;
	*a = tmp;
	ft_print_operation("pb");
}
