/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_int_transformers.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:08:58 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/07 22:17:46 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

t_status	transform_unsigned_int(t_format *format, unsigned int nbr);
t_status	transform_u(t_format *format, unsigned int nbr);

/* =============== Definition =============== */

t_status	transform_unsigned_int(t_format *format, unsigned int nbr)
{
	if (format->type == 'u')
		return (transform_u(format, nbr));
	return (ERROR);
}

t_status	transform_u(t_format *format, unsigned int nbr)
{
	// format->text = utoa_base(nbr, "012456789abcdef");
	format->text = ft_uitoa(nbr);
	if (!format->text)
		return (ERROR);
	if (apply_precision(format) == ERROR)
		return (ERROR);
	if (apply_width(format) == ERROR)
		return (ERROR);
	format->text_len = ft_strlen(format->text);
	return (SUCCESS);
}
