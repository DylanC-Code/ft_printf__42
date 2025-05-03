/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 23:55:10 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/03 23:57:22 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

bool	is_valid_flag(char c);
bool	is_valid_type(char c);

/* =============== Definition =============== */

bool	is_valid_flag(char c)
{
	return (ft_strchr(FLAGS, c));
}

bool	is_valid_type(char c)
{
	return (ft_strchr(TYPES, c));
}
