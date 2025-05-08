/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:56:16 by dcastor           #+#    #+#             */
/*   Updated: 2025/04/28 13:49:11 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const size_t	len = ft_strlen(s);
	char			*src;
	size_t			i;

	src = (char *)s;
	i = len;
	if ((char)c == 0)
		return (src + len);
	while (--i < len)
	{
		if (src[i] == (char)c)
			return (src + i);
	}
	return (NULL);
}
