/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_parsers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:19:27 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/07 17:50:27 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

t_status	parse_int_type(t_format *format);
t_status	parse_type_di(t_format *format);
t_status	parse_type_c(t_format *format);

/* =============== Definition =============== */

t_status	parse_int_type(t_format *format)
{
	if (format->type == 'd' || format->type == 'i')
		return (parse_type_di(format));
	if (format->type == 'c')
		return (parse_type_c(format));
	return (ERROR);
}

t_status	parse_type_di(t_format *format)
{
	if (format->hash)
		return (ERROR);
	return (SUCCESS);
}

t_status	parse_type_c(t_format *format)
{
	if (format->zero)
		return (ERROR);
	else if (format->plus)
		return (ERROR);
	else if (format->space)
		return (ERROR);
	else if (format->hash)
		return (ERROR);
	else if (format->precision)
		return (ERROR);
	return (SUCCESS);
}
