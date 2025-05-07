/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 22:53:05 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/07 22:43:59 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSERS_H
# define PARSERS_H

# include "ft_printf.h"

t_status	parse_str(char *str, t_list **head);
t_status	parse_flags(t_format *format, char **p_str);

/* Flags */
t_status	parse_hash(t_format *format, char **p_str);
t_status	parse_minus(t_format *format, char **p_str);
t_status	parse_plus(t_format *format, char **p_str);
t_status	parse_space(t_format *format, char **p_str);
t_status	parse_zero(t_format *format, char **p_str);

/* Types */
t_status	parse_type(t_format *format, char c);
t_status	parse_int_type(t_format *format);
t_status	parse_pchar_type(t_format *format);
t_status	parse_pvoid_type(t_format *format);
t_status	parse_unsigned_int_type(t_format *format);
t_status	parse_percent(t_format *format);

/* Others */
t_status	parse_width(t_format *format, char **p_str);
t_status	parse_precision(t_format *format, char **p_str);

#endif
