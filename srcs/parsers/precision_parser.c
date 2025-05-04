/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 20:56:44 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/04 21:10:45 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

t_status	parse_precision(t_format *format, char **p_str);

/* =============== Definition =============== */

t_status	parse_precision(t_format *format, char **p_str)
{
	unsigned int	precision;

	precision = 0;
	if (**p_str != '.')
		return (NOOP);
	*p_str = *p_str + 1;
	format->len++;
	while (**p_str && ft_isdigit(**p_str))
	{
		precision = precision * 10 + **p_str - '0';
		*p_str = *p_str + 1;
		format->len++;
	}
	if (precision > INT_MAX)
		return (ERROR);
	format->precision = precision;
	return (SUCCESS);
}
