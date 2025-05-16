/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:54:36 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/16 16:17:14 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

int	ft_printf(const char *str, ...);

/* =============== Definition =============== */

int	ft_printf(const char *str, ...)
{
	t_list	*list;
	va_list	args;
	int		bytes_written;

	va_start(args, str);
	if (!str)
		return (va_end(args), ERROR);
	list = NULL;
	if (parse_str((char *)str, &list) == ERROR)
		return (va_end(args), free_list_el(list), ERROR);
	if (!list)
		return (0);
	if (apply_formats(list, args) == ERROR)
		return (va_end(args), free_list_el(list), ERROR);
	bytes_written = print_contents(list);
	return (va_end(args), bytes_written);
}
