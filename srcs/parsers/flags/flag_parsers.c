/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_parsers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 22:54:29 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/06 03:42:29 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

t_status	parse_flags(t_format *format, char **p_str);

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
