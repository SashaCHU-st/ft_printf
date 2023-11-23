/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:19:35 by aheinane          #+#    #+#             */
/*   Updated: 2023/11/23 13:42:50 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexad_fd(unsigned int n)
{
	if (n == 0)
		ft_putchar_fd('0');
	else if (n >= 16)
	{
		if (ft_puthexad_fd(n / 16) < 0)
			return (-1);
		if (ft_puthexad_fd(n % 16) < 0)
			return (-1);
	}
	else
	{
		if (n <= 9)
		{
			if (ft_putchar_fd(n + '0') < 0)
				return (-1);
		}
		else
		{
			if (ft_putchar_fd(n + 'A' - 10) < 0)
				return (-1);
		}
	}
	return (0);
}

int	ft_putunbr_fd(unsigned long n)
{
	int	count;

	count = 0;
	if (n >= 10)
	{
		count += ft_putunbr_fd (n / 10);
		if (count < 0)
			return (-1);
		count += ft_putunbr_fd (n % 10);
		if (count < 0)
			return (-1);
	}
	else
	{
		count += ft_putchar_fd(n + '0');
		if (count < 0)
			return (-1);
	}
	return (count);
}

int	ft_putnbr_fd(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count += ft_putchar_fd ('-');
		if (count < 0)
			return (-1);
		n = -n;
	}
	count += ft_putunbr_fd(n);
	return (count);
}
