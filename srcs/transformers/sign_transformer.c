/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sign_transformer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 22:11:54 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/08 20:53:45 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

t_status	apply_sign(t_format *format);

/* =============== Definition =============== */

t_status	apply_sign(t_format *format)
{
	char	*result;

	if (*format->text == '-')
		return (NOOP);
	if (format->plus)
		result = ft_strjoin("+", format->text);
	else if (format->space)
		result = ft_strjoin(" ", format->text);
	else
		return (NOOP);
	if (!result)
		return (ERROR);
	free(format->text);
	format->text = result;
	format->text_len = ft_strlen(format->text);
	return (SUCCESS);
}
// t_status	apply_sign(t_format *format, bool is_positive)
// {
// 	char	*result;

// 	if (!is_positive && *format->text != '-')
// 		result = ft_strjoin("-", format->text);
// 	else if (format->plus)
// 		result = ft_strjoin("+", format->text);
// 	else if (format->space)
// 		result = ft_strjoin(" ", format->text);
// 	else
// 		return (NOOP);
// 	if (!result)
// 		return (ERROR);
// 	free(format->text);
// 	format->text = result;
// 	format->text_len = ft_strlen(format->text);
// 	return (SUCCESS);
// }
