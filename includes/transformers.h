/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 20:42:11 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/04 22:51:06 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORMERS_H
# define TRANSFORMERS_H

# include "ft_printf.h"

t_status	apply_precision(char **p_nbr, long precision);
t_status	apply_sign(t_format *format, char **p_nbr, bool is_positive);

#endif
