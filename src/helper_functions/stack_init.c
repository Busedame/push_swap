/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:19:37 by nholbroo          #+#    #+#             */
/*   Updated: 2024/02/21 13:59:18 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// Initialize stack a with the input numbers.

t_list	*ft_last_node(t_list *stack)
{
	int	i;
	int	stacklen;

	i = 0;
	stacklen = ft_stacklen(stack);
	while (i < stacklen - 1)
	{
		stack = stack->next;
		i++;
	}
	return (stack);
}

void	ft_first_node(char *nbr, t_list **a, t_list *node)
{
	node->value = ft_atol(nbr);
	node->next = NULL;
	node->previous = NULL;
	*a = node;
}

t_list	*ft_initialize_a(t_list **a, char **argv, int argc, int i)
{
	t_list	*node;
	t_list	*last;

	while (i < argc)
	{
		node = (t_list *)malloc(sizeof(t_list));
		if (!node)
		{
			ft_free_stack(*a);
			return (NULL);
		}
		if (!*a)
			ft_first_node(argv[i], a, node);
		else
		{
			last = ft_last_node(*a);
			node->previous = last;
			last->next = node;
			node->value = ft_atol(argv[i]);
			node->next = NULL;
		}
		i++;
	}
	return (*a);
}

t_list	*ft_init_stack_one_arg(char *argv, t_list **a)
{
	int		count;
	char	**arr;

	count = ft_wordcount(argv, ' ');
	arr = ft_split(argv, ' ');
	*a = ft_initialize_a(a, arr, count, 0);
	ft_freearray(arr, count);
	return (*a);
}
