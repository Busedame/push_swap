/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_more_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:28:57 by nholbroo          #+#    #+#             */
/*   Updated: 2024/02/23 15:23:04 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// These functions do input checks in the case where argc > 2.

int	ft_more_nbrcheck(char **argv, int argc)
{
	int	i;
	int	crstr;

	crstr = 1;
	while (crstr < argc)
	{
		i = 0;
		while (argv[crstr][i] != '\0')
		{
			if (argv[crstr][i] >= '0' && argv[crstr][i] <= '9')
				i++;
			else if ((argv[crstr][i] == '-' || argv[crstr][i] == '+') 
					&& (argv[crstr][i + 1] >= '0' && argv[crstr][i + 1] <= '9'))
				i++;
			else if (argv[crstr][i] == ' ')
				i++;
			else
				return (0);
		}
		crstr++;
	}
	return (1);
}

int	ft_more_intrange_check(char **argv, int argc)
{
	int			crnbr;
	long long	value;

	crnbr = 1;
	while (crnbr < argc)
	{
		value = ft_atol(argv[crnbr]);
		if (value < -2147483648 || value > 2147483647)
			return (1);
		crnbr++;
	}
	return (0);
}

int	ft_more_dupcheck(char **argv, int argc)
{
	int		i;
	int		crstr;

	crstr = 1;
	while (crstr < argc)
	{
		i = crstr + 1;
		while (i < argc)
		{
			if (!ft_strcmp(argv[crstr], argv[i]))
				return (0);
			else
				i++;
		}
		crstr++;
	}
	return (1);
}

int	ft_error_more_args(char **argv, int argc)
{
	if (!ft_more_nbrcheck(argv, argc))
		return (ft_printf("Error\n"));
	if (!ft_more_dupcheck(argv, argc))
		return (ft_printf("Error\n"));
	if (ft_more_intrange_check(argv, argc))
		return (ft_printf("Error\n"));
	return (0);
}
