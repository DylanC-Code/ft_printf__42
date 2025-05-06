/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 03:40:21 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/06 03:40:43 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

t_status	parse_plus(t_format *format, char **p_str);

/* =============== Definition =============== */

t_status	parse_plus(t_format *format, char **p_str)
{
	if (!p_str || !*p_str)
		return (ERROR);
	if (**p_str != '+')
		return (NOOP);
	if (format->plus == true)
		return (ERROR);
	format->plus = true;
	format->len++;
	*p_str = *p_str + 1;
	return (SUCCESS);
}
