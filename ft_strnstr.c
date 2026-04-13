/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josamba- <josamba-@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:20:09 by josamba-          #+#    #+#             */
/*   Updated: 2026/04/07 10:20:43 by josamba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t			i;
	size_t			j;
	size_t			save;
	const char		*first_occ;

	i = 0;
	j = 0;
	save = 0;
	if (little[0] == '\0')
		return ((char *)(big));
	while (big[i] && i < len)
	{
		if (little[j] == big[i])
		{
			first_occ = &big[i];
			save = i;
			while (big[i] && i < len && little[j++] == big[i++])
				if (little[j] == '\0')
					return ((char *)(first_occ));
			i = save;
		}
		i++;
		j = 0;
	}
	return (NULL);
}
