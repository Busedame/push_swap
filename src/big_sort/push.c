/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:09:28 by nholbroo          #+#    #+#             */
/*   Updated: 2024/02/21 13:58:43 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_init_push_to_b(t_list **a, t_list **b)
{
	pb(a, b);
	pb(a, b);
}

void	ft_push_to_b(t_list **a, t_list **b, t_list *curr_a)
{
	ft_median_and_currpos(a, b);
	if (curr_a->abovemedian && curr_a->target->abovemedian)
		return (to_b_rr(a, b, &curr_a, &curr_a->target));
	else if (!curr_a->abovemedian && !curr_a->target->abovemedian)
		return (to_b_rrr(a, b, &curr_a, &curr_a->target));
	if (curr_a->abovemedian == true)
		ft_ra_node_is_above_median(a, &curr_a);
	else if (curr_a->abovemedian == false)
		ft_rra_node_is_not_above_median(a, &curr_a);
	if (curr_a->target->abovemedian == true)
		ft_rb_node_is_above_median(b, &curr_a->target);
	else if (curr_a->target->abovemedian == false)
		ft_rrb_node_is_not_above_median(b, &curr_a->target);
	pb(a, b);
}

void	ft_push_to_a(t_list **a, t_list **b, t_list *curr_b)
{
	ft_median_and_currpos(a, b);
	if (curr_b->abovemedian && curr_b->target->abovemedian)
		return (to_a_rr(a, b, &curr_b, &curr_b->target));
	else if (!curr_b->abovemedian && !curr_b->target->abovemedian)
		return (to_a_rrr(a, b, &curr_b, &curr_b->target));
	if (curr_b->abovemedian == true)
		ft_rb_node_is_above_median(b, &curr_b);
	else if (curr_b->abovemedian == false)
		ft_rrb_node_is_not_above_median(b, &curr_b);
	if (curr_b->target->abovemedian == true)
		ft_ra_node_is_above_median(a, &curr_b->target);
	else if (curr_b->target->abovemedian == false)
		ft_rra_node_is_not_above_median(a, &curr_b->target);
	pa(a, b);
}
