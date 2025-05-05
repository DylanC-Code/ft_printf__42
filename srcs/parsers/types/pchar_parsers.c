/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pchar_parsers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:08:17 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/05 16:13:27 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

t_status	parse_pchar_type(t_format *format);

/* =============== Definition =============== */

t_status	parse_pchar_type(t_format *format)
{
	if (format->zero || format->plus || format->space || format->hash)
		return (ERROR);
	return (SUCCESS);
}
