/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:05:44 by aheinane          #+#    #+#             */
/*   Updated: 2023/11/22 13:29:24 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str )
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_helper(va_list args, const char s)
{
	int		count;

	count = 0;
	if (s == 'c')
		count = ft_putchar_fd(va_arg(args, int));
	else if (s == 's')
		count += ft_putstr_fd(va_arg(args, char *));
	else if (s == 'p')
		count = ft_print_ptr(va_arg(args, unsigned long long));
	else if (s == 'd' || s == 'i' )
		count = ft_putnbr_fd(va_arg(args, int));
	else if (s == 'x')
		count = ft_print_hexa(va_arg(args, unsigned int));
	else if (s == 'X')
		count = ft_print_hexabig(va_arg(args, unsigned int));
	else if (s == 'u')
		count = ft_putunbr_fd(va_arg(args, unsigned int));
	else if (s == '%')
		count = write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		number;
	int		i;
	int		count;

	number = ft_strlen(s);
	i = 0;
	count = 0;
	va_start (args, s);
	while (i < number)
	{
		if (s[i] == '%')
		{
			count += ft_helper(args, s[i + 1]);
			i++;
		}
		else
			count += write(1, &s[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
// #include <stdio.h>
// int main (void)
// {
// 	int i = 42;
// 	int *p = &i;
// 	ft_printf("%d %c %i %s \n", 5, 'h', -82, "llllll");
// 	   printf("%d %c %i %s \n\n", 5, 'h', -82, "llllll" );
// 	ft_printf("MINE NULL %s NULL \n", NULL);   
// 	   printf("ORIG NULL %s NULL \n\n", NULL);

// 	ft_printf("MINE%d\n", -10);
// 	printf("ORIG%d\n\n", -10);
// 	int index1 = 	ft_printf("%d", -10);
// 	int index2 = 	printf("%d", -10);
// printf("\n");
// 	printf ("MINE = %d \nORIG = %d\n\n", index1, index2);
// 	ft_printf("MINE %X %x %% %u %p \n",  -82, -82, -82, &p);
// 	   printf("ORIG %X %x %% %u %p \n\n", -82, -82, -1, &p);
// 	return (0);
// }
