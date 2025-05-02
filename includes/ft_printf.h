/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:19:59 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/02 17:06:53 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

# define FORMAT_START '%'
# define FORMATS ""
# define TYPES "cspdiuxX%"

typedef struct s_format
{
	unsigned int	length;
}					t_format;

int					ft_printf(const char *, ...);

#endif
