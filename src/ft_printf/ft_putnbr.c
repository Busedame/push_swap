/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:25:21 by nholbroo          #+#    #+#             */
/*   Updated: 2024/02/22 16:29:39 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	ft_nbwrite(char *str, int n)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (n > 0)
	{
		str[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	str[i--] = '\0';
	while (i >= 0)
	{
		write(1, &str[i--], 1);
		count++;
	}
	return (count);
}

int	ft_putnbr(int n)
{
	char	str[12];
	int		i;

	i = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n == 0)
		return (write(1, "0", 1));
	if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
		i++;
	}
	return (ft_nbwrite(str, n) + i);
}
