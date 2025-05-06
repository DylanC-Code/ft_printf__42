/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_parsers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 03:38:55 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/06 03:39:05 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

t_status	parse_zero(t_format *format, char **p_str);

/* =============== Definition =============== */

t_status	parse_zero(t_format *format, char **p_str)
{
	if (!p_str || !*p_str)
		return (ERROR);
	if (**p_str != '0')
		return (NOOP);
	if (format->zero == true)
		return (ERROR);
	format->zero = true;
	format->len++;
	*p_str = *p_str + 1;
	return (SUCCESS);
}
