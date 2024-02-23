/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:49:54 by nholbroo          #+#    #+#             */
/*   Updated: 2024/02/22 16:40:15 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
	{
		if (ft_error_one_arg(argv[1]))
			return (1);
		a = ft_init_stack_one_arg(argv[1], &a);
	}
	else if (argc > 2)
	{
		if (ft_error_more_args(argv, argc))
			return (1);
		a = ft_initialize_a(&a, argv, argc, 1);
	}
	if (ft_is_sorted(a))
		return (ft_free_stack(a));
	ft_index_check(&a);
	ft_sort(&a, &b);
	return (0);
}
