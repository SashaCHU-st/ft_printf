/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_strchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:50:43 by aheinane          #+#    #+#             */
/*   Updated: 2023/11/22 16:57:59 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr_fd(char *s)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	if (s == NULL)
	{
		count = write(1, "(null)", 6);
		if (count < 0)
			return (-1);
		return (6);
	}
	while (s[i] != '\0')
	{
		count = write (1, &s[i], 1);
		if (count < 0)
			return (-1);
		i++;
	}
	return (i);
}
