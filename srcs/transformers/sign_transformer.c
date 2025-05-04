/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sign_transformer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 22:11:54 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/04 22:50:46 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

t_status	apply_sign(t_format *format, char **p_nbr, bool is_positive);

/* =============== Definition =============== */

t_status	apply_sign(t_format *format, char **p_nbr, bool is_positive)
{
	char	*result;

	if (!is_positive)
		result = ft_strjoin("-", *p_nbr);
	else if (format->plus)
		result = ft_strjoin("+", *p_nbr);
	else if (format->space)
		result = ft_strjoin(" ", *p_nbr);
	else
		return (NOOP);
	if (!result)
		return (ERROR);
	free(*p_nbr);
	*p_nbr = result;
	return (SUCCESS);
}
