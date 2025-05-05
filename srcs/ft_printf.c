/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:54:36 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/05 13:21:34 by dcastor          ###   ########.fr       */
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
	if (parse_str((char *)str, &list) == ERROR)
		return (ERROR); // TODO: FREE EVERYTHING
	if (!list)
		return (0);
	written_bytes = print_contents(list, args);
	return (written_bytes);
}

int	main(void)
{
	// __builtin_printf("%0+6d", 53);
	// ft_printf("%5c", 'h');
	// ft_printf("Salut %-5c les gens", 'A');
	// __builtin_printf("%aswf", 42);
	// ft_printf("%+08.5d", 42); // "  +00042"✅
	ft_printf("% -10.3d", 7); // " 007      "
	// ft_printf("%0.0d", 0);    // ""✅
	// ft_printf("%5.0d", 0);    // "     "
	// ft_printf("%0+5d", 7);    // "+0007"
	// ft_printf("%-5d", -42);   // "-42  "
	// ft_printf("%i", 44);   // |44
	// ft_printf("% i", 44);  // | 44
	// ft_printf("% i", -44); // |-44
	// ft_printf("%+i", 44);  // |+44
	// ft_printf("%+i", -44); // |-44
	// ft_printf("Salut %d les gens ", 66, 77, 9, 12333);
	// ft_printf("Salut les gens ", 66, 77, 9, 12333);
	return (0);
}
