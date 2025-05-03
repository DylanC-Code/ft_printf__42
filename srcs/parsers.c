/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:04:20 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/03 19:04:29 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

int			parse_str(char *str, t_list **head);
int			parse_text(char *p_start, char *p_end, t_list **head);
int			parse_format(char *str, t_list **head);
t_status	parse_percent(t_format *format, char c);
t_status	parse_type(t_format *format, char c);

/* =============== Definition =============== */

int	parse_str(char *str, t_list **head)
{
	ssize_t	format_len;
	ssize_t	text_len;
	size_t	i;

	i = -1;
	text_len = NOOP;
	format_len = NOOP;
	while (str[++i])
	{
		if (!is_valid_format(str + i))
			continue ;
		format_len = parse_format(str + i, head);
		if (format_len <= 0)
			return (ERROR);
		text_len = parse_text(str, str + i, head);
		if (text_len < 0)
			return (ERROR);
		str += (format_len + text_len);
		i = 0;
	}
	text_len = parse_text(str, str + i, head);
	if (text_len < 0)
		return (ERROR);
	return (SUCCESS);
}

int	parse_text(char *p_start, char *p_end, t_list **head)
{
	t_element	*raw_text_el;
	t_list		*node;

	if (!p_start || !p_end || p_start > p_end)
		return (ERROR);
	if (!*p_start)
		return (NOOP);
	raw_text_el = create_text_raw(p_start, p_end);
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
	t_list		*node;

	format_el = create_format();
	if (!format_el)
		return (ERROR);
	node = ft_lstnew(format_el);
	if (!node)
		return (free(format_el), ERROR);
	parse_percent(&format_el->data.format, *++str);
	parse_type(&format_el->data.format, *str);
	ft_lstadd_back(head, node);
	return (format_el->data.format.len);
}

t_status	parse_percent(t_format *format, char c)
{
	if (c != '%')
		return (NOOP);
	format->len++;
	format->type = '%';
	return (SUCCESS);
}

t_status	parse_type(t_format *format, char c)
{
	size_t	i;

	i = -1;
	while (TYPES[++i])
		if (TYPES[i] == c)
			break ;
	if (!TYPES[i])
		return (NOOP);
	format->type = TYPES[i];
	format->len++;
	return (SUCCESS);
}
