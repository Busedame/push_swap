/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median_and_currpos.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:08:55 by nholbroo          #+#    #+#             */
/*   Updated: 2024/02/21 13:58:40 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_above_median(t_list **x)
{
	int		len;
	int		median;
	t_list	*currnode;

	ft_node_current_position(x);
	currnode = *x;
	len = ft_stacklen(currnode);
	median = len / 2;
	currnode = *x;
	while (currnode)
	{
		if (currnode->currpos <= median)
			currnode->abovemedian = true;
		else if (currnode->currpos > median)
			currnode->abovemedian = false;
		currnode = currnode->next;
	}
}

void	ft_node_current_position(t_list **x)
{
	t_list	*currnode;
	int		i;

	currnode = *x;
	i = 0;
	while (currnode)
	{
		currnode->currpos = i;
		i++;
		currnode = currnode->next;
	}
}

void	ft_median_and_currpos(t_list **a, t_list **b)
{
	ft_above_median(a);
	ft_above_median(b);
}
