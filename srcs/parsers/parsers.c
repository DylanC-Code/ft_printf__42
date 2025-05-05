/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:04:20 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/05 14:00:07 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

t_status	parse_str(char *str, t_list **head);
int			parse_text(char *p_start, t_list **head);
int			parse_format(char *str, t_list **head);
t_status	parse_type(t_format *format, char c);

/* =============== Definition =============== */

t_status	parse_str(char *str, t_list **head)
{
	char	*start_format;
	ssize_t	format_len;
	ssize_t	text_len;

	text_len = NOOP;
	format_len = NOOP;
	start_format = ft_strchr(str, FORMAT_START);
	while (start_format)
	{
		text_len = parse_text(str, head);
		if (text_len < 0)
			return (ERROR);
		format_len = parse_format(start_format + 1, head);
		if (format_len <= 0)
			return (ERROR);
		str = start_format + format_len;
		start_format = ft_strchr(str, FORMAT_START);
	}
	text_len = parse_text(str, head);
	if (text_len < 0)
		return (ERROR);
	return (SUCCESS);
}

int	parse_text(char *p_start, t_list **head)
{
	t_element	*raw_text_el;
	t_list		*node;
	size_t		len;

	if (!p_start)
		return (ERROR);
	len = 0;
	while (p_start[len] && p_start[len] != FORMAT_START)
		len++;
	if (len == 0)
		return (NOOP);
	raw_text_el = create_text_raw(p_start, len);
	if (!raw_text_el)
		return (ERROR);
	node = ft_lstnew(raw_text_el);
	if (!node)
		return (free(raw_text_el), ERROR);
	ft_lstadd_back(head, node);
	return (raw_text_el->data.text_raw.len);
}

int	parse_format(char *str, t_list **head)
{
	t_element	*format_el;
	t_format	*format;
	t_list		*node;

	format_el = create_format();
	if (!format_el)
		return (ERROR);
	node = ft_lstnew(format_el);
	if (!node)
		return (free(format_el), ERROR);
	format = &format_el->data.format;
	if (parse_flags(format, &str) == ERROR)
		return (free(format_el), ERROR);
	if (parse_width(format, &str) == ERROR)
		return (free(format_el), ERROR);
	if (parse_precision(format, &str) == ERROR)
		return (free(format_el), ERROR);
	if (parse_type(format, *str) == ERROR)
		return (free(format_el), ERROR);
	ft_lstadd_back(head, node);
	return (format->len);
}
