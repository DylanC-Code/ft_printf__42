/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:54:36 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/08 22:06:25 by dcastor          ###   ########.fr       */
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

	va_start(args, str);
	if (!str)
		return (ERROR);
	list = NULL;
	if (parse_str((char *)str, &list) == ERROR)
		return (free_list_el(list), ERROR);
	if (!list)
		return (0);
	if (apply_formats(list, args) == ERROR)
		return (free_list_el(list), ERROR);
	return (print_contents(list));
}

int main(void)
{
    int ret1, ret2;

    // Test %d avec +, width et precision
    ret1 = ft_printf("ft : |%+08.5d|\n", 42);
    ret2 = __builtin_printf("lib: |%+08.5d|\n", 42);
    printf("Return values: ft = %d, libc = %d\n\n", ret1, ret2);

    // Test %s avec precision
    ret1 = ft_printf("ft : |%.3s|\n", "Hello");
    ret2 = __builtin_printf("lib: |%.3s|\n", "Hello");
    printf("Return values: ft = %d, libc = %d\n\n", ret1, ret2);

    // Test %p
    void *ptr = (void *)0x42;
    ret1 = ft_printf("ft : |%p|\n", ptr);
    ret2 = __builtin_printf("lib: |%p|\n", ptr);
    printf("Return values: ft = %d, libc = %d\n\n", ret1, ret2);

    // Test %x avec #
    ret1 = ft_printf("ft : |%#08x|\n", 255);
    ret2 = __builtin_printf("lib: |%#08x|\n", 255);
    printf("Return values: ft = %d, libc = %d\n\n", ret1, ret2);

    // Test %c avec width et char nul
    ret1 = ft_printf("ft : |%5c|\n", '\0');
    ret2 = __builtin_printf("lib: |%5c|\n", '\0');
    printf("Return values: ft = %d, libc = %d\n\n", ret1, ret2);

    return 0;
}
