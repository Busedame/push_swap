/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:31:20 by nholbroo          #+#    #+#             */
/*   Updated: 2025/02/13 15:23:12 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// Checking which sorting algorhitm to use.

void	ft_finish_sort(t_list **a)
{
	while (*a)
	{
		ft_printf("%i\n", (*a)->value);
		(*a) = (*a)->next;
	}
	ft_free_stack(*a);
	exit(0);
}

void	ft_print_operation(char *str)
{
	ft_printf("%s\n", str);
}

void	ft_sort_two_numbers(t_list **a)
{
	sa(a);
	ft_finish_sort(a);
}

void	ft_sort(t_list **a, t_list **b)
{
	t_list	*tmp;
	int		count;

	count = 0;
	tmp = *a;
	while (tmp && count < 6)
	{
		tmp = tmp->next;
		count++;
	}
	if (count == 2)
		ft_sort_two_numbers(a);
	else if (count == 3)
		ft_sort_three_numbers(a, b);
	else if (count == 4)
		ft_sort_four_numbers(a, b);
	else if (count == 5)
		ft_sort_five_numbers(a, b);
	else
		ft_sort_x_numbers(a, b);
}
