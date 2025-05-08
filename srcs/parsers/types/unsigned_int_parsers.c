/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_int_parsers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:05:12 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/08 20:28:32 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

t_status	parse_unsigned_int_type(t_format *format);
t_status	parse_type_u(t_format *format);
t_status	parse_type_xX(t_format *format);

/* =============== Definition =============== */

t_status	parse_unsigned_int_type(t_format *format)
{
	if (format->type == 'u')
		return (parse_type_u(format));
	if (format->type == 'x' || format->type == 'X')
		return (parse_type_xX(format));
	return (ERROR);
}

t_status	parse_type_u(t_format *format)
{
	if (format->plus || format->space || format->sharp)
		return (ERROR);
	return (SUCCESS);
}

t_status	parse_type_xX(t_format *format)
{
	if (format->plus || format->space)
		return (ERROR);
	return (SUCCESS);
}
