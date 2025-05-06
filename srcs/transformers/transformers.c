/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:55:32 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/06 03:44:14 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

t_status	apply_formats(t_list *head, va_list args);
t_status	apply_format(t_element *element, va_list args);

/* =============== Definition =============== */

t_status	apply_formats(t_list *head, va_list args)
{
	t_list		*next;
	t_element	*element;

	if (!head)
		return (NOOP);
	while (head)
	{
		element = head->content;
		next = head->next;
		if (apply_format(element, args) == ERROR)
			return (ERROR);
		head = next;
	}
	return (SUCCESS);
}

t_status	apply_format(t_element *element, va_list args)
{
	t_format	*format;

	if (element->type == T_TEXT)
		return (NOOP);
	format = &element->data.format;
	if (ft_strchr(INT_TYPES, format->type))
		return (transform_int(format, va_arg(args, int)));
	else if (format->type == 's')
		return (transform_pchar(format, va_arg(args, char *)));
	return (ERROR);
}
