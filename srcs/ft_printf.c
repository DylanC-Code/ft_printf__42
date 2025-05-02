/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:54:36 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/02 17:07:38 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

int				ft_printf(const char *str, ...);
unsigned int	print_text_raw(char *text);

/* =============== Definition =============== */

int	ft_printf(const char *str, ...)
{
	unsigned int	written_bytes;
	t_format		*format;
	char			*s;
	size_t			i;

	i = 0;
	format = NULL;
	s = (char *)str;
	written_bytes = 0;
	while (ft_strchr(s + i, FORMAT_START))
	{
		parse_format(&format, s + i);
		if (format)
		{
            print_text_raw(s)
			i += format->length;
		}
		else
			i++;
	}
	written_bytes += print_text_raw(s);
	// __builtin_printf("%s", s);
	return (1);
}

unsigned int	print_text_raw(char *text)
{
	const size_t	text_len = ft_strlen(text);
	size_t			bytes_written;

	bytes_written = 0;
	if (!text)
		return (bytes_written);
	bytes_written = write(STDIN_FILENO, text, text_len);
	if (bytes_written >= 0)
		return (bytes_written);
	return (0);
}

int	main(void)
{
	ft_printf("Salut ", 55);
	return (0);
}
