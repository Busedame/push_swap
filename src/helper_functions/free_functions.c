/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:17:03 by nholbroo          #+#    #+#             */
/*   Updated: 2024/02/21 13:59:12 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// Different functions to free dynamically allocated memory.

int	ft_freearray(char **arr, int max)
{
	int	crstr;

	crstr = 0;
	while (crstr < max)
	{
		free(arr[crstr]);
		arr[crstr] = NULL;
		crstr++;
	}
	free(arr);
	arr = NULL;
	return (0);
}

void	*ft_free(void *ptr)
{
	free(ptr);
	ptr = NULL;
	return (NULL);
}

int	ft_free_stack(t_list *a)
{
	t_list	*node;

	while (a)
	{
		node = a->next;
		free(a);
		a = node;
	}
	return (0);
}
