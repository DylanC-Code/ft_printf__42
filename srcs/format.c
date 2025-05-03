/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:33:43 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/03 15:09:54 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

t_format	*create_format(void);
t_status	parse_percent(t_format *format, char c);

/* =============== Definition =============== */

t_format	*create_format(void)
{
	t_format	*format;

	format = malloc(sizeof(t_format));
	if (!format)
		return (NULL);
	format->len = 1;
	format->type = 0;
	return (format);
}

t_status	parse_percent(t_format *format, char c)
{
	if (c != '%')
		return (NOOP);
	format->len++;
	format->type = '%';
	return (SUCCESS);
}
