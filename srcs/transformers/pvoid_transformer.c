/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pvoid_transformer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:03:03 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/08 21:28:55 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

t_status		transform_pvoid(t_format *format, void *ptr);
static t_status	transform_null_ptr(t_format *format);
static char		*ultoa_base(uintptr_t n, char *base);

/* =============== Definition =============== */

t_status	transform_pvoid(t_format *format, void *ptr)
{
	uintptr_t	addr;
	char		*hex;

	if (!ptr)
		return (transform_null_ptr(format));
	addr = (uintptr_t)ptr;
	hex = ultoa_base(addr, "0123456789abcdef");
	if (!hex)
		return (ERROR);
	format->text = ft_strjoin("0x", hex);
	if (!format->text)
		return (free(hex), ERROR);
	format->text_len = ft_strlen(format->text);
	if (apply_width(format) == ERROR)
		return (free(hex), ERROR);
	format->text_len = ft_strlen(format->text);
	return (free(hex), SUCCESS);
}

static t_status	transform_null_ptr(t_format *format)
{
	format->text = ft_strdup("(nil)");
	if (!format->text)
		return (ERROR);
	format->text_len = ft_strlen(format->text);
	return (SUCCESS);
}

static char	*ultoa_base(uintptr_t n, char *base)
{
	size_t	base_len;
	int		i;
	char	buffer[65];

	base_len = 0;
	while (base[base_len])
		base_len++;
	buffer[64] = '\0';
	i = 63;
	if (n == 0)
		buffer[i--] = base[0];
	while (n > 0)
	{
		buffer[i--] = base[n % base_len];
		n /= base_len;
	}
	return (strdup(&buffer[i + 1]));
}
