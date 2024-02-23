/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_one_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:32:12 by nholbroo          #+#    #+#             */
/*   Updated: 2024/02/21 13:59:09 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// These functions do input checks in the case where argc == 2.

int	ft_one_nbrcheck(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else if ((str[i] == '-' || str[i] == '+') && (str[i + 1] >= '0' 
				&& str[i + 1] <= '9'))
			i++;
		else if (str[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

static int	ft_number_amount(char **arr)
{
	int	crnbr;
	int	max;

	crnbr = 0;
	max = 0;
	while (arr[crnbr])
	{
		max++;
		crnbr++;
	}
	return (max);
}

int	ft_one_dupcheck(char *str)
{
	int		i;
	int		crnbr;
	char	**arr;
	int		max;

	arr = ft_split(str, ' ');
	if (!arr)
		return (0);
	max = ft_number_amount(arr);
	crnbr = 0;
	while (crnbr < max)
	{
		i = crnbr + 1;
		while (i < max)
		{
			if (!ft_strcmp(arr[crnbr], arr[i]))
				return (ft_freearray(arr, max));
			else
				i++;
		}
		crnbr++;
	}
	ft_freearray(arr, max);
	return (1);
}

int	ft_one_intrange_check(char **arr, int count)
{
	int			crnbr;
	long long	value;

	crnbr = 0;
	while (crnbr < count)
	{
		value = ft_atol(arr[crnbr]);
		if (value < -2147483648 || value > 2147483647)
		{
			ft_freearray(arr, count);
			ft_printf("Error\n");
			return (1);
		}
		crnbr++;
	}
	return (0);
}

int	ft_error_one_arg(char *str)
{
	long long	value;
	char		**arr;
	int			count;

	if (!ft_one_nbrcheck(str))
		return (ft_printf("Error\n"));
	if (!ft_one_dupcheck(str))
		return (ft_printf("Error\n"));
	if (ft_strchr(str, ' '))
	{
		value = ft_atol(str);
		if (value < -2147483648 || value > 2147483647)
		{
			ft_printf("Error\n");
			return (1);
		}
	}
	arr = ft_split(str, ' ');
	if (!arr)
		return (1);
	count = ft_wordcount(str, ' ');
	if (ft_one_intrange_check(arr, count))
		return (1);
	ft_freearray(arr, count);
	return (0);
}
