/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:37:22 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/05 17:59:35 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

# define FORMAT_START '%'
# define FORMATS ""
# define FLAGS "# +-0"
# define TYPES "cspdiuxX%"

# define INT_TYPES "cdi"
# define UNSIGNED_INT_TYPES "uxX"

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
	bool			minus;
	bool			zero;
	long			precision;
	bool			hash;
	bool			space;
	bool			plus;
	unsigned int	width;
	unsigned char	type;
	char			*text;
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

# include "parsers.h"
# include "printers.h"
# include "transformers.h"
# include "validators.h"

int					ft_printf(const char *, ...);

/* Text Raw */

t_element			*create_text_raw(char *p_start, size_t len);

/* Format */

t_element			*create_format(void);

/* Printers */

int					print_contents(t_list *head);

/* Validators */

bool				is_valid_format(char *format);
bool				is_int_type(char c);
bool				is_unsigned_int_type(char c);

#endif
