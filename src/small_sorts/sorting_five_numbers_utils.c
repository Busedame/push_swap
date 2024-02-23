/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_five_numbers_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:14:01 by nholbroo          #+#    #+#             */
/*   Updated: 2024/02/22 15:56:34 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// Different operations to move the lowest and second lowest value number to 
// stack b temporarily.

int	ft_find_seclowest(t_list **a, int seclowest)
{
	t_list	*node;

	node = *a;
	seclowest = 0;
	while (node && node->index != 1)
	{
		node = node->next;
		seclowest++;
	}
	return (seclowest);
}

void	ft_lowest_is_two_three_or_four(t_list **a, t_list **b, int lowest)
{
	if (lowest == 2)
	{
		ra(a, false);
		ra(a, false);
		pb(a, b);
	}
	else if (lowest == 3)
	{
		rra(a, false);
		rra(a, false);
		pb(a, b);
	}
	else if (lowest == 4)
	{
		rra(a, false);
		pb(a, b);
	}
}

void	ft_lowest_is_zero_or_one(t_list **a, t_list **b, int lowest)
{
	if (lowest == 0)
		pb(a, b);
	else if (lowest == 1)
	{
		sa(a);
		pb(a, b);
	}
}

void	ft_seclowest_zero_or_one(t_list **a, t_list **b, int seclowest)
{
	if (seclowest == 0)
		pb(a, b);
	else if (seclowest == 1)
	{
		sa(a);
		pb(a, b);
	}
}

void	ft_seclowest_two_or_three(t_list **a, t_list **b, int seclowest)
{
	if (seclowest == 2)
	{
		rra(a, false);
		rra(a, false);
		pb(a, b);
	}
	else if (seclowest == 3)
	{
		rra(a, false);
		pb(a, b);
	}
}
