/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_parsers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 22:54:29 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/04 15:55:20 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

t_status	parse_flags(t_format *format, char **p_str);
t_status	parse_minus(t_format *format, char **p_str);
t_status	parse_plus(t_format *format, char **p_str);
t_status	parse_space(t_format *format, char **p_str);
t_status	parse_hash(t_format *format, char **p_str);
t_status	parse_zero(t_format *format, char **p_str);

/* =============== Definition =============== */

t_status	parse_flags(t_format *format, char **p_str)
{
	t_status	minus_status;
	t_status	zero_status;
	t_status	plus_status;
	t_status	space_status;
	t_status	hash_status;

	minus_status = parse_minus(format, p_str);
	if (minus_status == ERROR)
		return (ERROR);
	zero_status = parse_zero(format, p_str);
	if (zero_status == ERROR)
		return (ERROR);
	hash_status = parse_hash(format, p_str);
	if (hash_status == ERROR)
		return (ERROR);
	space_status = parse_space(format, p_str);
	if (space_status == ERROR)
		return (ERROR);
	plus_status = parse_plus(format, p_str);
	if (plus_status == ERROR)
		return (ERROR);
	if (minus_status || zero_status || hash_status || space_status
		|| plus_status)
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
t_status	parse_space(t_format *format, char **p_str)
{
	if (!p_str || !*p_str)
		return (ERROR);
	if (**p_str != ' ')
		return (NOOP);
	if (format->space == true)
		return (ERROR);
	format->space = true;
	format->len++;
	*p_str = *p_str + 1;
	return (SUCCESS);
}
t_status	parse_hash(t_format *format, char **p_str)
{
	if (!p_str || !*p_str)
		return (ERROR);
	if (**p_str != '#')
		return (NOOP);
	if (format->hash == true)
		return (ERROR);
	format->hash = true;
	format->len++;
	*p_str = *p_str + 1;
	return (SUCCESS);
}

