/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_parsers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 22:54:29 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/04 12:00:49 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

t_status	parse_width(t_format *format, char **p_str);
t_status	parse_flags(t_format *format, char **p_str);
t_status	parse_minus(t_format *format, char **p_str);
t_status	parse_plus(t_format *format, char **p_str);

/* =============== Definition =============== */

t_status	parse_flags(t_format *format, char **p_str)
{
	t_status	padding_width;
	t_status	minus_status;
	t_status	plus_status;

	minus_status = parse_minus(format, p_str);
	if (minus_status == ERROR)
		return (ERROR);
	plus_status = parse_plus(format, p_str);
	if (plus_status == ERROR)
		return (ERROR);
	padding_width = parse_width(format, p_str);
	if (padding_width == ERROR)
		return (ERROR);
	if (padding_width || minus_status || plus_status)
		return (parse_flags(format, p_str), SUCCESS);
	return (NOOP);
}

t_status	parse_minus(t_format *format, char **p_str)
{
	if (!p_str || !*p_str)
		return (ERROR);
	if (**p_str != '-')
		return (NOOP);
	if (format->minus == true)
		return (ERROR);
	format->minus = true;
	format->len++;
	*p_str = *p_str + 1;
	return (SUCCESS);
}
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

t_status	parse_width(t_format *format, char **p_str)
{
	int	padding;

	padding = 0;
	if (!*p_str)
		return (ERROR);
	while (**p_str && ft_isdigit(**p_str))
	{
		padding = padding * 10 + **p_str - '0';
		*p_str = *p_str + 1;
		format->len++;
	}
	if (!padding)
		return (NOOP);
	format->padding = padding;
	return (SUCCESS);
}
