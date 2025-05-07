/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 20:42:11 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/07 16:04:32 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORMERS_H
# define TRANSFORMERS_H

# include "ft_printf.h"
# include <stdarg.h>

t_status	apply_formats(t_list *head, va_list args);
t_status	apply_precision(t_format *format);
t_status	apply_sign(t_format *format, bool is_positive);
t_status	apply_width(t_format *format);

/* Types */
t_status	transform_int(t_format *format, int n);
t_status	transform_pchar(t_format *format, char *str);
t_status	transform_pvoid(t_format *format, void *addr);

#endif
