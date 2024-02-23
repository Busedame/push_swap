/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_rotations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:09:44 by nholbroo          #+#    #+#             */
/*   Updated: 2024/02/21 13:58:48 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_final_rotation(t_list **a)
{
	t_list	*curr_a;

	curr_a = *a;
	while (curr_a->index != 0)
		curr_a = curr_a->next;
	ft_above_median(a);
	if (curr_a->abovemedian == true)
	{
		while ((*a)->index != 0)
			ra(a, false);
	}
	else
	{
		while ((*a)->index != 0)
			rra(a, false);
	}
}

void	ft_rra_node_is_not_above_median(t_list **head_x, t_list **curr_x)
{
	while ((*head_x)->value != (*curr_x)->value)
		rra(head_x, false);
}

void	ft_rrb_node_is_not_above_median(t_list **head_x, t_list **curr_x)
{
	while ((*head_x)->value != (*curr_x)->value)
		rrb(head_x, false);
}

void	ft_ra_node_is_above_median(t_list **head_x, t_list **curr_x)
{
	while ((*head_x)->value != (*curr_x)->value)
		ra(head_x, false);
}

void	ft_rb_node_is_above_median(t_list **head_x, t_list **curr_x)
{
	while ((*head_x)->value != (*curr_x)->value)
		rb(head_x, false);
}
