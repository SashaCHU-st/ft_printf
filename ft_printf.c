/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:05:44 by aheinane          #+#    #+#             */
/*   Updated: 2023/11/23 13:45:54 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_helper(va_list args, const char s)
{
	int		count;

	count = 0;
	if (s == 'c')
		count = ft_putchar_fd(va_arg(args, int));
	else if (s == 's')
		count += ft_putstr_fd(va_arg(args, char *));
	else if (s == 'p')
		count = ft_print_ptr(va_arg(args, unsigned long));
	else if (s == 'd' || s == 'i' )
		count = ft_putnbr_fd(va_arg(args, int));
	else if (s == 'x')
		count = ft_print_hexa(va_arg(args, unsigned int));
	else if (s == 'X')
		count = ft_print_hexabig(va_arg(args, unsigned int));
	else if (s == 'u')
		count = ft_putunbr_fd(va_arg(args, unsigned int));
	else if (s == '%')
	{
		count = write(1, "%", 1);
		if (count < 0)
			return (-1);
	}
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start (args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			count += ft_helper(args, s[i + 1]);
			i++;
		}
		else
			count += write(1, &s[i], 1);
		if (count < 0)
		{
			va_end(args);
			return (-1);
		}
		i++;
	}
	va_end(args);
	return (count);
}
