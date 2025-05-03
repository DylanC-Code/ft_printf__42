/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_validator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:08:36 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/03 19:32:06 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

bool	is_valid_type(char c);
bool	is_valid_format(char *format);
bool	is_int_type(char c);
bool	is_int_type(char c);
bool	is_unsigned_int_type(char c);

/* =============== Definition =============== */

bool	is_valid_type(char c)
{
	size_t	i;

	i = -1;
	while (TYPES[++i])
		if (TYPES[i] == c)
			return (true);
	return (false);
}

bool	is_valid_format(char *format)
{
	if (*format++ != FORMAT_START)
		return (false);
	if (*format == FORMAT_START)
		return (true);
	// is_valid_flags(&format);
	if (!is_valid_type(*format))
		return (false);
	return (true);
}

bool	is_int_type(char c)
{
	return (ft_strchr(INT_TYPES, c));
}
bool	is_unsigned_int_type(char c)
{
	return (ft_strchr(UNSIGNED_INT_TYPES, c));
}
