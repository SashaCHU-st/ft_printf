/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:48:21 by aheinane          #+#    #+#             */
/*   Updated: 2023/11/23 15:19:01 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexad(unsigned long n)
{
	if (n >= 16)
	{
		if (ft_puthexad(n / 16) < 0)
			return (-1);
		if (ft_puthexad(n % 16) < 0)
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
			if (ft_putchar(n + 'a' - 10) < 0)
				return (-1);
		}
	}
	return (0);
}

int	ft_ptr_len(unsigned long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

int	ft_print_ptr(unsigned long ptr)
{
	int	count;

	count = 0;
	count += write(1, "0x", 2);
	if (count < 0)
		return (-1);
	if (ptr == 0)
		return (count += write(1, "0", 1));
	else
	{
		if (ft_puthexad(ptr) < 0)
			return (-1);
		count += ft_ptr_len(ptr);
	}
	return (count);
}
