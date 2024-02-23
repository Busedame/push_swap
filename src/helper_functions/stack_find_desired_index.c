/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_find_desired_index.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 20:27:55 by nholbroo          #+#    #+#             */
/*   Updated: 2024/02/21 15:02:06 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// Checking for which index I want the numbers to have when they are
// finished with being sorted.

static int	ft_find_curr_index(t_list *currnode, int nbr)
{
	while (currnode)
	{
		if (currnode->value < nbr && currnode->index == -1)
			nbr = currnode->value;
		currnode = currnode->next;
	}
	return (nbr);
}

static int	ft_set_curr_index(t_list *currnode, int nbr, int i)
{
	while (currnode)
	{
		if (nbr == currnode->value && currnode->index == -1)
		{
			currnode->index = i;
			i++;
			break ;
		}
		currnode = currnode->next;
	}
	return (i);
}

void	ft_index_check(t_list **a)
{
	int		nbr;
	t_list	*currnode;
	int		i;

	currnode = *a;
	while (currnode)
	{
		currnode->index = -1;
		currnode = currnode->next;
	}
	i = 0;
	currnode = *a;
	while (i < ft_stacklen(currnode))
	{
		nbr = INT_MAX;
		nbr = ft_find_curr_index(currnode, nbr);
		currnode = *a;
		i = ft_set_curr_index(currnode, nbr, i);
		currnode = *a;
	}
}
