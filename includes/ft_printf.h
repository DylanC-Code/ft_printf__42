/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:19:59 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/03 15:02:44 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

# define FORMAT_START '%'
# define FORMATS ""
# define TYPES "cspdiuxX"

# define ERROR -1
# define NOOP 0
# define SUCCESS 1

typedef int			t_status;

typedef enum e_element_type
{
	T_TEXT,
	T_FORMAT,
}					t_element_type;

typedef struct s_text_raw
{
	char			*text;
	size_t			len;
}					t_text_raw;

typedef struct s_format
{
	size_t			len;
	unsigned char	type;
}					t_format;

typedef union u_element_data
{
	t_text_raw		text_raw;
	t_format		format;
}					t_element_data;

typedef struct s_element
{
	t_element_type	type;
	t_element_data	data;
}					t_element;

int					ft_printf(const char *, ...);

/* Text Raw */

t_element			*create_text_raw(char *p_start, char *p_end);

/* Format */

t_format			*create_format(void);
t_status			parse_percent(t_format *format, char c);

/* Printers */

int					print_text_el(t_element *el);
int					print_format_el(t_element *el);

#endif
