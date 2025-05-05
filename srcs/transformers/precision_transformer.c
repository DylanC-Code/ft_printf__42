/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_transformer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 20:40:46 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/05 15:52:45 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

t_status		apply_precision(t_format *format);
static t_status	apply_precision_edge_case(char **p_str);
static t_status	apply_precision_normal_case(char **p_nbr, const size_t nbr_len,
					unsigned int precision);

/* =============== Definition =============== */

t_status	apply_precision(t_format *format)
{
	const size_t	nbr_len = ft_strlen(format->text);

	if (format->precision < 0)
		return (NOOP);
	if (format->precision == 0 && nbr_len == 1 && ft_strncmp(format->text, "0",
			1) == 0)
		return (apply_precision_edge_case(&format->text));
	if ((long unsigned)format->precision <= nbr_len)
		return (SUCCESS);
	return (apply_precision_normal_case(&format->text, nbr_len,
			format->precision));
}

static t_status	apply_precision_edge_case(char **p_nbr)
{
	free(*p_nbr);
	*p_nbr = malloc(1);
	if (!*p_nbr)
		return (ERROR);
	**p_nbr = '\0';
	return (SUCCESS);
}

static t_status	apply_precision_normal_case(char **p_nbr, const size_t nbr_len,
		unsigned int precision)
{
	char	*result;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	result = malloc(precision + 1);
	if (!result)
		return (ERROR);
	while (++i < precision)
	{
		if (i < precision - nbr_len)
			result[i] = '0';
		else
			result[i] = (*p_nbr)[++j];
	}
	result[precision] = '\0';
	free(*p_nbr);
	*p_nbr = result;
	return (SUCCESS);
}
