/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_validator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:08:36 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/04 11:37:57 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

bool	is_valid_format(char *format);
bool	is_int_type(char c);
bool	is_int_type(char c);
bool	is_unsigned_int_type(char c);
bool	is_valid_flag(char **p_format, unsigned int *flags);
bool	is_valid_width(char **p_format, unsigned int *flags);
void	set_flag(unsigned int *bitmask, char flag);

/* =============== Definition =============== */

bool	is_valid_format(char *format)
{
	unsigned int	flags;

	flags = 0;
	if (*format++ != FORMAT_START)
		return (false);
	if (*format == FORMAT_START)
		return (true);
	if (!is_valid_flag(&format, &flags))
		return (false);
	if (!is_valid_width(&format, &flags))
		return (false);
	if (!is_valid_type(*format, flags))
		return (false);
	return (true);
}

bool	is_valid_flag(char **p_format, unsigned int *flags)
{
	if (!*p_format)
		return (false);
	while (**p_format && ft_strchr(FLAGS, **p_format))
	{
		if (is_flag_set(*flags, **p_format))
			return (false);
		else
			(set_flag(flags, **p_format));
		*p_format = *p_format + 1;
	}
	return (true);
}

bool	is_valid_width(char **p_format, unsigned int *flags)
{
	long unsigned	width;

	width = 0;
	if (!p_format || !*p_format)
		return (false);
	if (!ft_isdigit(**p_format))
		return (true);
	while (width <= INT_MAX && ft_isdigit(**p_format))
	{
		width = width * 10 + **p_format - '0';
		*p_format = *p_format + 1;
	}
	if (width > 0)
		*flags &= WIDTH;
	return (width <= INT_MAX);
}
bool	is_valid_precision(char **p_format, unsigned int *flags)
{
	unsigned long	precision;

	precision = 0;
	if (!p_format || !*p_format)
		return (false);
	if (**p_format != '.')
		return (true);
	*p_format = *p_format + 1;
	while (**p_format && ft_isdigit(**p_format))
	{
		precision = precision * 10 + **p_format - '0';
		*p_format = *p_format + 1;
	}
	*flags |= PRECISION;
	return (precision <= INT_MAX);
}

bool	is_int_type(char c)
{
	return (ft_strchr(INT_TYPES, c));
}
bool	is_unsigned_int_type(char c)
{
	return (ft_strchr(UNSIGNED_INT_TYPES, c));
}
void	set_flag(unsigned int *bitmask, char flag)
{
	if (flag == '-')
		*bitmask |= (1 << 1);
	else if (flag == '+')
		*bitmask |= (1 << 2);
	else if (flag == '#')
		*bitmask |= (1 << 3);
	else if (flag == '0')
		*bitmask |= (1 << 4);
	else if (flag == ' ')
		*bitmask |= (1 << 5);
}
