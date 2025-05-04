/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_transformer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 20:40:46 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/04 22:20:44 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

t_status		apply_precision(char **p_nbr, long precision);
static t_status	apply_precision_edge_case(char **p_str);
static t_status	apply_precision_normal_case(char **p_nbr, const size_t nbr_len,
					unsigned int precision);

/* =============== Definition =============== */

t_status	apply_precision(char **p_nbr, long precision)
{
	const size_t	nbr_len = ft_strlen(*p_nbr);

	if (precision < 0)
		return (NOOP);
	if (precision == 0 && nbr_len == 1 && ft_strncmp(*p_nbr, "0", 1) == 0)
		return (apply_precision_edge_case(p_nbr));
	if ((long unsigned)precision <= nbr_len)
		return (SUCCESS);
	return (apply_precision_normal_case(p_nbr, nbr_len, precision));
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
