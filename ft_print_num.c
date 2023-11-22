/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:19:35 by aheinane          #+#    #+#             */
/*   Updated: 2023/11/22 17:11:56 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

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

int	ft_number_len(int num)
{
	size_t	len;

	len = 0;
	if (num <= 0)
		len = 1;
	while (num)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

int	ft_putunbr_fd(unsigned int n)
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
		if (ft_putchar_fd(n + '0') < 0)
			return (-1);
		count += ft_number_len(n);
	}
	return (count);
}

int	ft_putnbr_fd(int n)
{
	long	i;
	int		count;

	i = n;
	count = 0;
	if (i < 0)
	{
		count += ft_putchar_fd ('-');
		if (count < 0)
			return (-1);
		i = -i;
	}
	if (i >= 10)
	{
		count += ft_putnbr_fd (i / 10);
		if (count < 0)
			return (-1);
		count += ft_putnbr_fd (i % 10);
		if (count < 0)
			return (-1);
	}
	else
	{
		if (ft_putchar_fd(i + '0') < 0)
			return (-1);
		count += ft_number_len(i);
	}
	return (count);
}
