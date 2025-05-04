/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 22:53:05 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/04 16:24:33 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSERS_H
# define PARSERS_H

# include "ft_printf.h"

t_status	parse_flags(t_format *format, char **p_str);
t_status	parse_type(t_format *format, char c);
t_status	parse_int_type(t_format *format);
t_status	parse_width(t_format *format, char **p_str);

#endif
