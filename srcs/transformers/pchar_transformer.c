/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pchar_transformer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:16:12 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/08 20:01:32 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

t_status		transform_pchar(t_format *format, char *str);
static t_status	apply_precision_str(t_format *format);
static t_status	apply_width_str(t_format *format);
/* =============== Definition =============== */

t_status	transform_pchar(t_format *format, char *str)
{
	if (!str)
		format->text = ft_strdup("(null)");
	else
		format->text = ft_strdup(str);
	format->text_len = ft_strlen(str);
	if (apply_precision_str(format) == ERROR)
		return (ERROR);
	if (apply_width(format) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

static t_status	apply_precision_str(t_format *format)
{
	char	*result;

	if (format->precision < 0
		|| (unsigned int)format->precision >= format->text_len)
		return (NOOP);
	result = malloc(format->precision + 1);
	if (!result)
		return (ERROR);
	result[format->precision] = '\0';
	ft_strlcpy(result, format->text, format->precision + 1);
	free(format->text);
	format->text = result;
	format->text_len = format->precision;
	return (SUCCESS);
}
