/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_transformers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:17:55 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/08 20:54:24 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

t_status	transform_int(t_format *format, int n);
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

t_status	transform_di(t_format *format, int nbr)
{
	format->text = ft_itoa(nbr);
	format->text_len = ft_strlen(format->text);
	if (apply_precision(format) == ERROR)
		return (ERROR);
	if (apply_sign(format) == ERROR)
		return (ERROR);
	if (apply_width(format) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
