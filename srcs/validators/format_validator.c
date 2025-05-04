/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_validator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:08:36 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/04 10:42:33 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

bool	is_valid_format(char *format);
bool	is_int_type(char c);
bool	is_int_type(char c);
bool	is_unsigned_int_type(char c);
bool	is_valid_flag(char **p_format);
void	jump_width(char **p_format);
void	set_flag(unsigned int *bitmask, char flag);

/* =============== Definition =============== */

bool	is_valid_format(char *format)
{
	if (*format++ != FORMAT_START)
		return (false);
	if (*format == FORMAT_START)
		return (true);
	if (!is_valid_flag(&format))
		return (false);
	jump_width(&format);
	if (!is_valid_type(*format))
		return (false);
	return (true);
}

bool	is_valid_flag(char **p_format)
{
	unsigned int	bitmask;

	bitmask = 0;
	if (!*p_format)
		return (false);
	while (**p_format && ft_strchr(FLAGS, **p_format))
	{
		if (is_flag_set(bitmask, **p_format))
			return (false);
		else
			(set_flag(&bitmask, **p_format));
		*p_format = *p_format + 1;
	}
	return (true);
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
