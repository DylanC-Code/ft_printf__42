/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pchar_transformer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:16:12 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/05 16:58:52 by dcastor          ###   ########.fr       */
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
	if (apply_precision_str(format) == ERROR)
		return (ERROR);
	if (apply_width_str(format) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

static t_status	apply_precision_str(t_format *format)
{
	const size_t	len = ft_strlen(format->text);
	char			*result;
	size_t			i;

	i = -1;
	if (!format->precision || (unsigned int)format->precision >= len)
		return (NOOP);
	result = malloc(format->precision + 1);
	if (!result)
		return (ERROR);
	result[format->precision] = '\0';
	ft_strlcpy(result, format->text, format->precision + 1);
	free(format->text);
	format->text = result;
	return (SUCCESS);
}

static t_status	apply_width_str(t_format *format)
{
	const size_t	len = ft_strlen(format->text);
	size_t			pad_len;
	char			*result;

	if (!format->width || format->width <= len)
		return (NOOP);
	pad_len = format->width - len;
	result = malloc(format->width + 1);
	if (!result)
		return (ERROR);
	ft_strset(result, ' ', pad_len);
	ft_strlcpy(result + pad_len, format->text, len + 1);
	free(format->text);
	format->text = result;
	return (SUCCESS);
}
