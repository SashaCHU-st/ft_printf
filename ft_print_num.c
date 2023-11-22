/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:19:35 by aheinane          #+#    #+#             */
/*   Updated: 2023/11/22 13:30:50 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

void	ft_puthexad_fd(unsigned int n)
{
	if (n == 0)
		ft_putchar_fd('0');
	else if (n >= 16)
	{
		ft_puthexad_fd(n / 16);
		ft_puthexad_fd(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd(n + '0');
		else
			ft_putchar_fd(n + 'A' - 10);
	}
}

int	ft_putunbr_fd(unsigned int n)
{
	size_t	count;

	count = 0;
	if (n >= 10)
	{
		count += ft_putunbr_fd (n / 10);
		count += ft_putunbr_fd (n % 10);
	}
	else
	{
		ft_putchar_fd(n + '0');
		count += ft_number_len(n);
	}
	return (count);
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

int	ft_putnbr_fd(int n)
{
	long	i;
	size_t	count;

	i = n;
	count = 0;
	if (i < 0)
	{
		count += ft_putchar_fd ('-');
		i = -i;
	}
	if (i >= 10)
	{
		count += ft_putnbr_fd (i / 10);
		count += ft_putnbr_fd (i % 10);
	}
	else
	{
		ft_putchar_fd(i + '0');
		count += ft_number_len(i);
	}
	return (count);
}
