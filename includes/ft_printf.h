/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:37:22 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/07 22:17:11 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include "types.h"
# include "parsers.h"
# include "printers.h"
# include "transformers.h"
# include <stdint.h>
# include <stdio.h>

# define FORMAT_START '%'
# define FORMATS ""
# define FLAGS "# +-0"
# define TYPES "cspdiuxX%"

# define INT_TYPES "cdi"
# define UNSIGNED_INT_TYPES "uxX"

# define ERROR -1
# define NOOP 0
# define SUCCESS 1

int			ft_printf(const char *str, ...) __attribute__((format(printf, 1,
						2)));

void		free_list_el(t_list *head);
void		free_el(t_element *el);

/* Text Raw */

t_element	*create_text_raw(char *p_start, size_t len);

/* Format */

t_element	*create_format(void);

/* Printers */

int			print_contents(t_list *head);

#endif
