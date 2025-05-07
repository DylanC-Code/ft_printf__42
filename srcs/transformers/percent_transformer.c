/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_transformer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 22:46:44 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/07 22:49:04 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

t_status	transform_percent(t_format *format);

/* =============== Definition =============== */
t_status	transform_percent(t_format *format)
{
	format->text = ft_strdup("%");
	if (!format->text)
		return (ERROR);
	format->text_len = ft_strlen(format->text);
	return (SUCCESS);
}
