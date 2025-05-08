/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pchar_parsers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:08:17 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/08 20:41:47 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

t_status	parse_pchar_type(t_format *format);

/* =============== Definition =============== */

t_status	parse_pchar_type(t_format *format)
{
	if (format->plus || format->sharp)
		return (ERROR);
	return (SUCCESS);
}
