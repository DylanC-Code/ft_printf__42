/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 21:44:36 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/04 11:17:37 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATORS_H
# define VALIDATORS_H

# include "ft_printf.h"

# define MINUS (1 << 1)
# define PLUS (1 << 2)
# define HASH (1 << 3)
# define ZERO (1 << 4)
# define SPACE (1 << 5)
# define WIDTH (1 << 6)
# define PRECISION (1 << 7)

bool	is_flag_set(unsigned int bitmask, char c);
bool	is_valid_type(char c, unsigned int flags);

/* Types Validators */

bool	is_valid_type_c(unsigned int flags);
bool	is_valid_type_di(unsigned int flags);

#endif
