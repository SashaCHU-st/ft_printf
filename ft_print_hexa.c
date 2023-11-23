/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:41:42 by aheinane          #+#    #+#             */
/*   Updated: 2023/11/23 15:18:02 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexabig(unsigned long n)
{
	if (n == 0)
		return (write(1, "0", 1));
	else
		if (ft_puthexadbig(n) < 0)
			return (-1);
	return (ft_ptr_len(n));
}

int	ft_print_hexa(unsigned long n)
{
	if (n == 0)
		return (write(1, "0", 1));
	else
		if (ft_puthexad(n) < 0)
			return (-1);
	return (ft_ptr_len(n));
}
