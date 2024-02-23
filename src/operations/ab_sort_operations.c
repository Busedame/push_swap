/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_sort_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:58:03 by nholbroo          #+#    #+#             */
/*   Updated: 2024/02/21 13:59:42 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// The different operations for sorting a and b simultanously.

void	ss(t_list **a, t_list **b)
{
	if (!*a || !*b || !(*a)->next || !(*b)->next)
		return ;
	sa(a);
	sb(b);
	ft_print_operation("ss");
}

void	rr(t_list **a, t_list **b)
{
	if (!*a || !*b || !(*a)->next || !(*b)->next)
		return ;
	ra(a, true);
	rb(b, true);
	ft_print_operation("rr");
}

void	rrr(t_list **a, t_list **b)
{
	if (!*a || !*b || !(*a)->next || !(*b)->next)
		return ;
	rra(a, true);
	rrb(b, true);
	ft_print_operation("rrr");
}
