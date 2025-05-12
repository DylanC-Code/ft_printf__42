/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:17:34 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/10 16:02:01 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "libft.h"

int		ft_atoi(const char *nptr);
char	*ft_uitoa(unsigned int n);
char	*ft_uitoa_base(unsigned int nbr, char *base);
size_t	ft_strset(char *str, char c, size_t n);
char	*ft_itoa(int n);
char	*ft_itoa_base(ssize_t nbr, char *base);
char	**ft_split(char const *s, char c);
void	quick_sort(int *tab, size_t size);

#endif
