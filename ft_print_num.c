/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:19:35 by aheinane          #+#    #+#             */
/*   Updated: 2023/11/23 15:18:34 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexadbig(unsigned int n)
{
	if (n == 0)
		ft_putchar('0');
	else if (n >= 16)
	{
		if (ft_puthexadbig(n / 16) < 0)
			return (-1);
		if (ft_puthexadbig(n % 16) < 0)
			return (-1);
	}
	else
	{
		if (n <= 9)
		{
			if (ft_putchar(n + '0') < 0)
				return (-1);
		}
		else
		{
			if (ft_putchar(n + 'A' - 10) < 0)
				return (-1);
		}
	}
	return (0);
}

int	ft_putunbr(unsigned long n)
{
	int	count;

	count = 0;
	if (n >= 10)
	{
		count += ft_putunbr (n / 10);
		if (count < 0)
			return (-1);
		count += ft_putunbr (n % 10);
		if (count < 0)
			return (-1);
	}
	else
	{
		count += ft_putchar(n + '0');
		if (count < 0)
			return (-1);
	}
	return (count);
}

int	ft_putnbr(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		if (count < 0)
			return (-1);
		n = -n;
	}
	count += ft_putunbr(n);
	return (count);
}
