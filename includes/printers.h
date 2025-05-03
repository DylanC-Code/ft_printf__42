/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 21:44:36 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/03 21:54:26 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTERS_H
# define PRINTERS_H

# include "ft_printf.h"

int	print_int_type(t_format *format, int n);

/* Utils */
int	print_padding(unsigned int number);
int	print_n(char *text, size_t n);

#endif
