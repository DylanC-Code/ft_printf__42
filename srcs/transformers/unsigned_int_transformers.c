/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_int_transformers.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:08:58 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/08 20:38:44 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

t_status	transform_unsigned_int(t_format *format, unsigned int nbr);
t_status	transform_u(t_format *format, unsigned int nbr);
t_status	transform_x(t_format *format, unsigned int nbr);
t_status	transform_X(t_format *format, unsigned int nbr);

/* =============== Definition =============== */

t_status	transform_unsigned_int(t_format *format, unsigned int nbr)
{
	if (format->type == 'u')
		return (transform_u(format, nbr));
	else if (format->type == 'x')
		return (transform_x(format, nbr));
	else if (format->type == 'X')
		return (transform_X(format, nbr));
	return (ERROR);
}

t_status	transform_u(t_format *format, unsigned int nbr)
{
	format->text = ft_uitoa(nbr);
	if (!format->text)
		return (ERROR);
	format->text_len = ft_strlen(format->text);
	if (apply_precision(format) == ERROR)
		return (ERROR);
	if (apply_width(format) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

t_status	transform_x(t_format *format, unsigned int nbr)
{
	format->text = ft_uitoa_base(nbr, "0123456789abcdef");
	if (!format->text)
		return (ERROR);
	format->text_len = ft_strlen(format->text);
	if (apply_precision(format) == ERROR)
		return (ERROR);
	if (apply_sharp(format, false) == ERROR)
		return (ERROR);
	if (apply_width(format) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
t_status	transform_X(t_format *format, unsigned int nbr)
{
	format->text = ft_uitoa_base(nbr, "0123456789ABCDEF");
	if (!format->text)
		return (ERROR);
	format->text_len = ft_strlen(format->text);
	if (apply_precision(format) == ERROR)
		return (ERROR);
	if (apply_sharp(format, true) == ERROR)
		return (ERROR);
	if (apply_width(format) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
