/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:48:21 by aheinane          #+#    #+#             */
/*   Updated: 2023/11/21 16:43:56 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexadbig_fd(unsigned long long n)
{
	if (n >= 16)
	{
		ft_puthexadbig_fd(n / 16);
		ft_puthexadbig_fd(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd(n + '0');
		else
			ft_putchar_fd(n + 'a' - 10);
	}

}

int	ft_ptr_len(unsigned long long num)
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

int	ft_print_ptr(unsigned long long ptr)
{
	int	length;

	length = 0;
	length += write(1, "0x", 2);
	if (ptr == 0)
		length += write(1, "0", 1);
	else
	{
		ft_puthexadbig_fd(ptr);
		length += ft_ptr_len(ptr);
	}
	return (length);
}
