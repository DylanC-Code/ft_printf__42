/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pvoid_parsers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:56:36 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/07 16:00:25 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

t_status	parse_pvoid_type(t_format *format);

/* =============== Definition =============== */

t_status	parse_pvoid_type(t_format *format)
{
	if (format->hash || format->zero || format->space || format->precision
		|| format->plus)
		return (ERROR);
	return (SUCCESS);
}
