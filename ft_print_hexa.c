/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:41:42 by aheinane          #+#    #+#             */
/*   Updated: 2023/11/22 13:27:26 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexabig(unsigned long long n)
{
	if (n == 0)
		return (write(1, "0", 1));
	else
		ft_puthexad_fd(n);
	return (ft_ptr_len(n));
}

int	ft_print_hexa(unsigned long long n)
{
	if (n == 0)
		return (write(1, "0", 1));
	else
		ft_puthexadbig_fd(n);
	return (ft_ptr_len(n));
}
