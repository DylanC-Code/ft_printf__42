/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_transformers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 23:12:13 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/08 18:58:13 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

t_status	transform_c(t_format *format, char c);
t_status	transform_null_char(t_format *format);
t_status	transform_char(t_format *format, char c);

/* =============== Definition =============== */

t_status	transform_c(t_format *format, char c)
{
	format->text = malloc(2);
	if (!format->text)
		return (ERROR);
	format->text[0] = c;
	format->text[1] = '\0';
	format->text_len = 1;
	if (apply_width(format) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
