/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:54:36 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/04 11:09:39 by dcastor          ###   ########.fr       */
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
	int		written_bytes;

	va_start(args, str);
	if (!str)
		return (ERROR);
	list = NULL;
	parse_str((char *)str, &list);
	if (!list)
		return (0);
	written_bytes = print_contents(list, args);
	return (written_bytes);
}

int	main(void)
{
	// __builtin_printf("%2c", '5');
	// ft_printf("%5c", 'h');
	ft_printf("%-5c", 'h');
	// __builtin_printf("%-5c", 'i');
	// ft_printf("% i", -44);
	// ft_printf("%i", 44);   // |44
	// ft_printf("% i", 44);  // | 44
	// ft_printf("% i", -44); // |-44
	// ft_printf("%+i", 44);  // |+44
	// ft_printf("%+i", -44); // |-44
	// ft_printf("Salut %d les gens ", 66, 77, 9, 12333);
	// ft_printf("Salut les gens ", 66, 77, 9, 12333);
	return (0);
}
