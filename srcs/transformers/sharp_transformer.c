/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sharp_transformer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 20:23:29 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/15 21:57:11 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

t_status	apply_sharp(t_format *format, bool upper);

/* =============== Definition =============== */

t_status	apply_sharp(t_format *format, bool upper)
{
	char	*result;

	if (!format->sharp || (format->text_len == 1 && format->text[0] == '0'))
		return (NOOP);
	if (upper)
		result = ft_strjoin("0X", format->text);
	else
		result = ft_strjoin("0x", format->text);
	if (!result)
		return (ERROR);
	free(format->text);
	format->text = result;
	format->text_len = ft_strlen(result);
	return (SUCCESS);
}
