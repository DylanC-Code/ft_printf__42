/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_transformers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:17:55 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/05 15:57:39 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

t_status	transform_int(t_format *format, int n);
t_status	transform_c(t_format *format, char c);
t_status	transform_di(t_format *format, int nbr);

/* =============== Definition =============== */

t_status	transform_int(t_format *format, int n)
{
	if (format->type == 'c')
		return (transform_c(format, n));
	else if (format->type == 'd' || format->type == 'i')
		return (transform_di(format, n));
	return (ERROR);
}

t_status	transform_c(t_format *format, char c)
{
	format->text = malloc(2);
	if (!format->text)
		return (ERROR);
	format->text[0] = c;
	format->text[1] = '\0';
	return (apply_width(format));
}

t_status	transform_di(t_format *format, int nbr)
{
	const bool	is_positive = nbr >= 0;

	(void)is_positive;
	format->text = ft_itoa(ft_abs(nbr));
	if (apply_precision(format) == ERROR)
		return (ERROR);
	if (apply_sign(format, is_positive) == ERROR)
		return (ERROR);
	if (apply_width(format) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
