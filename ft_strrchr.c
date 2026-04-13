/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josamba- <josamba-@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:08:58 by josamba-          #+#    #+#             */
/*   Updated: 2026/04/07 10:09:07 by josamba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	*found;
	unsigned char	*cast;

	cast = (unsigned char *)s;
	i = 0;
	found = NULL;
	if (c == '\0')
	{
		while (cast[i])
			i++;
		return ((char *)&cast[i]);
	}
	i = 0;
	while (cast[i])
	{
		if (cast[i] == (unsigned char)c)
			found = &cast[i];
		i++;
	}
	return ((char *)found);
}
