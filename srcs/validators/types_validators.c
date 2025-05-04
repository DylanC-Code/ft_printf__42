/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_validators.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:16:52 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/04 11:17:15 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

bool	is_valid_type_c(unsigned int flags);
bool	is_valid_type_di(unsigned int flags);

/* =============== Definition =============== */

bool	is_valid_type_c(unsigned int flags)
{
	if (flags & ZERO)
		return (false);
	else if (flags & PLUS)
		return (false);
	else if (flags & SPACE)
		return (false);
	else if (flags & HASH)
		return (false);
	else if (flags & PRECISION)
		return (false);
	return (true);
}

bool	is_valid_type_di(unsigned int flags)
{
	return (!(flags & HASH));
}
