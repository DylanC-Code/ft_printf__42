/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_parsers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:57:15 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/04 16:25:29 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

t_status	parse_type(t_format *format, char c);

/* =============== Definition =============== */

t_status	parse_type(t_format *format, char c)
{
	format->type = c;
	if (format->type == '%')
		return (SUCCESS);
	else if (ft_strchr(INT_TYPES, format->type))
		return (parse_int_type(format));
	return (ERROR);
}
