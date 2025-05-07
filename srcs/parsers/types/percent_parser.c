/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 22:42:58 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/07 22:45:25 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

t_status	parse_percent(t_format *format);

/* =============== Definition =============== */

t_status	parse_percent(t_format *format)
{
	if (format->hash || format->minus || format->plus || format->precision >= 0
		|| format->space || format->width || format->zero)
		return (ERROR);
	return (SUCCESS);
}
