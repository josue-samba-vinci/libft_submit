/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josamba- <josamba-@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:05:15 by josamba-          #+#    #+#             */
/*   Updated: 2026/04/07 10:05:18 by josamba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*cast;

	cast = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (cast[i] == (unsigned char)c)
			return (&cast[i]);
		i++;
	}
	return (NULL);
}
