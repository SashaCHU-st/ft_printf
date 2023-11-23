/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:06:49 by aheinane          #+#    #+#             */
/*   Updated: 2023/11/23 15:19:32 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	ft_helper(va_list args, const char s);
int	ft_print_hexabig(unsigned long n);
int	ft_print_hexa(unsigned long n);
int	ft_puthexadbig(unsigned int n);
int	ft_putunbr(unsigned long n);
int	ft_putnbr(long n);
int	ft_puthexad(unsigned long n);
int	ft_ptr_len(unsigned long num);
int	ft_print_ptr(unsigned long ptr);
int	ft_putchar(char c);
int	ft_putstr(char *s);

#endif