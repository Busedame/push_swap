/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:11:35 by nholbroo          #+#    #+#             */
/*   Updated: 2024/02/22 16:37:03 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	ft_to_b(t_list **a, t_list **b, int len)
{
	t_list	*cheapest;
	int		lowestcost;

	while (len > 3)
	{
		ft_target_node_in_b(a, b);
		ft_pushcost_to_b(a, b);
		lowestcost = ft_what_is_lowest_cost(a);
		cheapest = ft_where_is_lowest_cost(a, lowestcost);
		ft_push_to_b(a, b, cheapest);
		len--;
	}
}

static void	ft_to_a(t_list **a, t_list **b)
{
	t_list	*curr_b;
	int		lowestcost;

	curr_b = *b;
	while (curr_b)
	{
		ft_target_node_in_a(a, b);
		ft_pushcost_to_a(a, b);
		lowestcost = ft_what_is_lowest_cost(b);
		curr_b = ft_where_is_lowest_cost(b, lowestcost);
		ft_push_to_a(a, b, curr_b);
		curr_b = *b;
	}
}

void	ft_sort_x_numbers(t_list **a, t_list **b)
{
	int		len;

	ft_init_push_to_b(a, b);
	len = ft_stacklen(*a);
	ft_to_b(a, b, len);
	ft_sort_three_numbers(a, b);
	ft_to_a(a, b);
	ft_final_rotation(a);
	ft_finish_sort(a);
}
