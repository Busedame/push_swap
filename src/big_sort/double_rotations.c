/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_rotations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:09:57 by nholbroo          #+#    #+#             */
/*   Updated: 2024/02/21 13:58:33 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	to_a_rr(t_list **a, t_list **b, t_list **curr_x, t_list **target)
{
	while ((*a)->value != (*target)->value && (*b)->value != (*curr_x)->value)
		rr(a, b);
	while ((*a)->value != (*target)->value)
		ra(a, false);
	while ((*b)->value != (*curr_x)->value)
		rb(b, false);
	pa(a, b);
}

void	to_a_rrr(t_list **a, t_list **b, t_list **curr_x, t_list **target)
{
	while ((*a)->value != (*target)->value && (*b)->value != (*curr_x)->value)
		rrr(a, b);
	while ((*a)->value != (*target)->value)
		rra(a, false);
	while ((*b)->value != (*curr_x)->value)
		rrb(b, false);
	pa(a, b);
}

void	to_b_rr(t_list **a, t_list **b, t_list **curr_x, t_list **target)
{
	while ((*a)->value != (*curr_x)->value && (*b)->value != (*target)->value)
		rr(a, b);
	while ((*b)->value != (*target)->value)
		rb(b, false);
	while ((*a)->value != (*curr_x)->value)
		ra(a, false);
	pb(a, b);
}

void	to_b_rrr(t_list **a, t_list **b, t_list **curr_x, t_list **target)
{
	while ((*a)->value != (*curr_x)->value && (*b)->value != (*target)->value)
		rrr(a, b);
	while ((*b)->value != (*target)->value)
		rrb(b, false);
	while ((*a)->value != (*curr_x)->value)
		rra(a, false);
	pb(a, b);
}
