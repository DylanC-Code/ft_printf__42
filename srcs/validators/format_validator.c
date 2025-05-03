/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_validator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:08:36 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/04 00:18:59 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

bool	is_valid_format(char *format);
bool	is_int_type(char c);
bool	is_int_type(char c);
bool	is_unsigned_int_type(char c);
void	jump_flags(char **p_format);
void	jump_width(char **p_format);

/* =============== Definition =============== */

bool	is_valid_format(char *format)
{
	if (*format++ != FORMAT_START)
		return (false);
	if (*format == FORMAT_START)
		return (true);
	jump_flags(&format);
	jump_width(&format);
	if (!is_valid_type(*format))
		return (false);
	return (true);
}

void	jump_flags(char **p_format)
{
	if (!*p_format)
		return ;
	while (**p_format && is_valid_flag(**p_format))
		*p_format = *p_format + 1;
}

void	jump_width(char **p_format)
{
	int	width;

	width = 0;
	if (!p_format || !*p_format)
		return ;
	while (width >= 0 && ft_isdigit(**p_format))
	{
		width = width * 10 + **p_format - '0';
		*p_format = *p_format + 1;
	}
}

bool	is_int_type(char c)
{
	return (ft_strchr(INT_TYPES, c));
}
bool	is_unsigned_int_type(char c)
{
	return (ft_strchr(UNSIGNED_INT_TYPES, c));
}
