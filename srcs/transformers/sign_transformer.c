/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sign_transformer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 22:11:54 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/04 22:14:58 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

t_status	apply_sign(char **p_nbr, bool is_positive, bool display_plus);

/* =============== Definition =============== */

t_status	apply_sign(char **p_nbr, bool is_positive, bool display_plus)
{
	char	*result;

	if (is_positive && !display_plus)
		return (NOOP);
	if (is_positive)
		result = ft_strjoin("+", *p_nbr);
	else
		result = ft_strjoin("-", *p_nbr);
	if (!result)
		return (ERROR);
	free(*p_nbr);
	*p_nbr = result;
	return (SUCCESS);
}
