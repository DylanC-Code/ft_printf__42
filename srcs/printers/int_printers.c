/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_printers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 21:30:06 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/04 11:50:49 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

int	print_int_type(t_format *format, int n);
int	print_c(t_format *format, char c);
int	print_di(t_format *format, int n);

/* =============== Definition =============== */

int	print_int_type(t_format *format, int n)
{
	if (format->type == 'c')
		return (print_c(format, n));
	else if (format->type == 'd' || format->type == 'i')
		return (print_di(format, n));
	return (0);
}

int	print_c(t_format *format, char c)
{
	int	bytes_written;

	bytes_written = 0;
	if (!format->minus && format->padding > 1)
		bytes_written += print_padding(format->padding - 1);
	bytes_written += write(STDOUT_FILENO, &c, 1);
	if (format->minus && format->padding > 1)
		bytes_written += print_padding(format->padding - 1);
	return (bytes_written);
}
int	print_di(t_format *format, int n)
{
	char	*ascii_n;

	ascii_n = ft_itoa(n);
	(void)ascii_n;
	(void)format;
	__builtin_printf("TEUB %4d\n", 6893211);
	return (0);
}
