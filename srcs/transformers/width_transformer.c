/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_transformer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 09:39:16 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/05 11:37:19 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

t_status		apply_width(t_format *format, char **p_nbr);
static t_status	fill_width_with_zero(t_format *format, char **p_nbr);
static t_status	fill_width_with_space(t_format *format, char **p_nbr);

/* =============== Definition =============== */

t_status	apply_width(t_format *format, char **p_nbr)
{
	if (format->zero && !format->minus && !format->precision)
		return (fill_width_with_zero(format, p_nbr));
	return (fill_width_with_space(format, p_nbr));
}

static t_status	fill_width_with_zero(t_format *format, char **p_nbr)
{
	const size_t	len = ft_strlen(*p_nbr);
	const bool		is_sign = ft_strchr("-+", **p_nbr);
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
		result[i++] = **p_nbr;
		ft_strlcpy(result + i + pad_len, *p_nbr + 1, len + 1);
	}
	else
		ft_strlcpy(result + i + pad_len, *p_nbr, len + 1);
	free(*p_nbr);
	*p_nbr = result;
	return (SUCCESS);
}
static t_status	fill_width_with_space(t_format *format, char **p_nbr)
{
	(void)format;
	(void)p_nbr;
	return (ERROR);
}
