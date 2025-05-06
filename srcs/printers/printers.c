/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:02:00 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/06 03:36:08 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

int	print_text_el(t_element *el);
int	print_format_el(t_element *el);
int	print_contents(t_list *head);

/* =============== Definition =============== */

int	print_contents(t_list *head)
{
	t_list		*next;
	t_element	*element;
	int			written_bytes;

	written_bytes = 0;
	if (!head)
		return (0);
	while (head)
	{
		element = head->content;
		next = head->next;
		if (element->type == T_TEXT)
			written_bytes += print_text_el(element);
		else
			written_bytes += print_format_el(element);
		free_el(head->content);
		free(head);
		head = next;
	}
	return (written_bytes);
}

int	print_text_el(t_element *el)
{
	size_t		written_bytes;
	t_text_raw	text_raw;

	if (!el)
		return (0);
	text_raw = el->data.text_raw;
	written_bytes = print_n(text_raw.text, text_raw.len);
	return (free(el), written_bytes);
}

int	print_format_el(t_element *el)
{
	int			written_bytes;
	t_format	format;

	written_bytes = 0;
	if (!el)
		return (0);
	format = el->data.format;
	written_bytes = print_n(format.text, -1);
	return (free(el), written_bytes);
}
