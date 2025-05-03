/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_parsers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 22:54:29 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/04 00:30:06 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

t_status	parse_padding(t_format *format, char **p_str);
t_status	parse_flags(t_format *format, char **p_str);

/* =============== Definition =============== */

t_status	parse_flags(t_format *format, char **p_str)
{
	t_status	padding_status;

	padding_status = parse_padding(format, p_str);
	if (padding_status == ERROR)
		return (ERROR);
	return (padding_status);
}

t_status	parse_padding(t_format *format, char **p_str)
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
