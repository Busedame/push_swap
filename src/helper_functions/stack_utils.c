/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 20:45:48 by nholbroo          #+#    #+#             */
/*   Updated: 2024/02/22 16:39:02 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// Random stack-functions, plus ft_is_sorted which is checking if the input nbrs
// are already sorted.

bool	ft_is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->next->value > stack->value)
			stack = stack->next;
		else
			return (false);
	}
	return (true);
}

int	ft_stacklen(t_list *stack)
{
	int	len;

	len = 0;
	if (!stack)
		return (0);
	while (stack != NULL)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

t_list	*ft_one_before_last_node(t_list *stack)
{
	int	i;
	int	stacklen;

	i = 0;
	stacklen = ft_stacklen(stack);
	while (i < stacklen - 2)
	{
		stack = stack->next;
		i++;
	}
	return (stack);
}
