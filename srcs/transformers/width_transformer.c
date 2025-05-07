/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_transformer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 09:39:16 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/07 21:44:44 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

t_status		apply_width(t_format *format);
static t_status	fill_width_with_zero(t_format *format);
static t_status	fill_width_with_space(t_format *format);
static t_status	fill_width_with_space_by_end(t_format *format);

/* =============== Definition =============== */

t_status	apply_width(t_format *format)
{
	if (format->minus)
		return (fill_width_with_space_by_end(format));
	else if (format->zero && format->precision == 0)
		return (fill_width_with_zero(format));
	return (fill_width_with_space(format));
}

static t_status	fill_width_with_zero(t_format *format)
{
	const size_t	len = ft_strlen(format->text);
	const bool		is_sign = ft_strchr("-+", *format->text);
	const size_t	pad_len = format->width - len;
	char			*result;
	size_t			i;

	i = 0;
	if (format->width <= len)
		return (NOOP);
	result = malloc(format->width + 1);
	if (!result)
		return (ERROR);
	ft_strset(result + i, '0', format->width);
	if (is_sign)
	{
		result[i++] = *format->text;
		ft_strlcpy(result + i + pad_len, format->text + 1, len + 1);
	}
	else
		ft_strlcpy(result + i + pad_len, format->text, len + 1);
	free(format->text);
	format->text = result;
	return (SUCCESS);
}

static t_status	fill_width_with_space(t_format *format)
{
	const size_t	len = ft_strlen(format->text);
	const size_t	pad_len = format->width - len;
	char			*result;

	if (format->width <= len)
		return (NOOP);
	result = malloc(format->width + 1);
	if (!result)
		return (ERROR);
	ft_strset(result, ' ', pad_len);
	ft_strlcpy(result + pad_len, format->text, len + 1);
	free(format->text);
	format->text = result;
	return (SUCCESS);
}

static t_status	fill_width_with_space_by_end(t_format *format)
{
	const size_t	len = ft_strlen(format->text);
	const size_t	pad_len = format->width - len;
	char			*result;

	if (format->width <= len)
		return (NOOP);
	result = malloc(format->width + 1);
	if (!result)
		return (ERROR);
	ft_strlcpy(result, format->text, len + 1);
	ft_strset(result + len, ' ', pad_len);
	free(format->text);
	format->text = result;
	return (SUCCESS);
}
