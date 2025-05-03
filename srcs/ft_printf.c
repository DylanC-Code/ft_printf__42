/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:54:36 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/03 14:22:50 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"
#include <stdarg.h>

/* =============== Declaration =============== */

int				ft_printf(const char *str, ...);
unsigned int	print_n(char *text, size_t n);
int				parse_str(char *str, t_list **head);
bool			is_valid_format(char *format);
int				parse_format(char *str, t_list **head);
int				parse_text(char *p_start, char *p_end, t_list **head);

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
		{
			written_bytes += print_n(element->data.text_raw.text,
					element->data.text_raw.len);
			ft_lstdelone(head, free);
		}
		else
		{
		}
		head = next;
	}
	return (written_bytes);
}

int	ft_printf(const char *str, ...)
{
	t_list	*list;
	int		written_bytes;

	if (!str)
		return (ERROR);
	list = NULL;
	parse_str((char *)str, &list);
	if (!list)
		return (0);
	written_bytes = print_contents(list);
	return (written_bytes);
}

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
	(void)head;
	(void)str;
	return (NOOP);
}

unsigned int	print_n(char *text, size_t n)
{
	const size_t	text_len = ft_strlen(text);
	size_t			len_to_print;
	ssize_t			bytes_written;

	bytes_written = 0;
	if (!text)
		return (bytes_written);
	if (n >= text_len)
		len_to_print = text_len;
	else
		len_to_print = n;
	bytes_written = write(STDOUT_FILENO, text, len_to_print);
	if (bytes_written >= 0)
		return (bytes_written);
	return (0);
}

int	main(void)
{
	ft_printf("Salut %05d les gens %+i ", 66, 77, 9, 12333);
	return (0);
}

bool is_valid_type(char c)
{
    
}

bool	is_valid_format(char *format)
{
	if (*format++ != FORMAT_START)
		return (false);
	if (*format++ == FORMAT_START)
		return (true);
	// is_valid_flags(&format);
	if (!is_valid_type(*format))
		return (false);
	return (true);
}
