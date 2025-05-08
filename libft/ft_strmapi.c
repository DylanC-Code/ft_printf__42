/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:49:57 by dcastor           #+#    #+#             */
/*   Updated: 2025/04/27 17:16:10 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	const size_t	len = ft_strlen(s);
	size_t			i;
	char			*result;

	i = -1;
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	while (++i < len)
		result[i] = f(i, s[i]);
	result[i] = '\0';
	return (result);
}
