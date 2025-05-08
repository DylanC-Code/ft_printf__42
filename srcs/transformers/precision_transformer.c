/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_transformer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 20:40:46 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/08 20:09:32 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

t_status		apply_precision(t_format *format);
static t_status	apply_precision_edge_case(t_format *format);
static t_status	apply_precision_normal_case(t_format *format);

/* =============== Definition =============== */

t_status	apply_precision(t_format *format)
{
	const size_t	nbr_len = ft_strlen(format->text);

	if (format->precision < 0)
		return (NOOP);
	if (format->precision == 0 && nbr_len == 1 && ft_strncmp(format->text, "0",
			1) == 0)
		return (apply_precision_edge_case(format));
	if ((long unsigned)format->precision <= nbr_len)
		return (SUCCESS);
	return (apply_precision_normal_case(format));
}

static t_status	apply_precision_edge_case(t_format *format)
{
	format->text[0] = '\0';
	format->text_len = format->precision;
	return (SUCCESS);
}

static t_status	apply_precision_normal_case(t_format *format)
{
	char	*result;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	result = malloc(format->precision + 1);
	if (!result)
		return (ERROR);
	while (++i < format->precision)
	{
		if (i < format->precision - format->text_len)
			result[i] = '0';
		else
			result[i] = (format->text)[++j];
	}
	result[format->precision] = '\0';
	free(format->text);
	format->text = result;
	format->text_len = format->precision;
	return (SUCCESS);
}
