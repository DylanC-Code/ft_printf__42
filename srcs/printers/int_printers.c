/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_printers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 21:30:06 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/05 12:07:51 by dcastor          ###   ########.fr       */
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
	if (!format->minus && format->width > 1)
		bytes_written += print_padding(format->width - 1);
	bytes_written += write(STDOUT_FILENO, &c, 1);
	if (format->minus && format->width > 1)
		bytes_written += print_padding(format->width - 1);
	return (bytes_written);
}
int	print_di(t_format *format, int n)
{
	const bool	is_positive = n >= 0;
	char		*result;

	(void)is_positive;
	result = ft_itoa(ft_abs(n));
	if (apply_precision(&result, format->precision) == ERROR)
		return (ERROR);
	if (apply_sign(format, &result, is_positive) == ERROR)
		return (ERROR);
	if (apply_width(format, &result) == ERROR)
		return (ERROR);
	// if (format->plus && is_positive)
	// 	apply_positive(&result);
	// else if (!is_positive)
	// 	apply_negative(&result);
	__builtin_printf("=> |%s|\n", result);
	return (0);
}
