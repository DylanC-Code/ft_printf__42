/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 23:55:10 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/04 10:44:41 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

bool	is_flag_set(unsigned int bitmask, char c);
bool	is_valid_type(char c);

/* =============== Definition =============== */

bool	is_flag_set(unsigned int bitmask, char flag)
{
	if (flag == '-' && bitmask & (1 << 1))
		return (true);
	else if (flag == '+' && bitmask & (1 << 2))
		return (true);
	else if (flag == '#' && bitmask & (1 << 3))
		return (true);
	else if (flag == '0' && bitmask & (1 << 4))
		return (true);
	else if (flag == ' ' && bitmask & (1 << 5))
		return (true);
	return (false);
}

bool	is_valid_type(char c)
{
	return (ft_strchr(TYPES, c));
}
