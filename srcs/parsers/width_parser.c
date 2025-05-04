/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 13:48:23 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/04 13:48:58 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

t_status	parse_width(t_format *format, char **p_str);

/* =============== Definition =============== */

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
	format->width = padding;
	return (SUCCESS);
}
