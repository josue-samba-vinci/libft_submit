/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josamba- <josamba-@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:48:06 by josamba-          #+#    #+#             */
/*   Updated: 2026/04/07 10:48:08 by josamba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	find_occurence(char *s1, char c)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_start_bigger_end(void)
{
	char	*trim;

	trim = malloc(sizeof(char));
	if (!trim)
		return (NULL);
	trim[0] = '\0';
	return (trim);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*trim;

	start = 0;
	end = 0;
	i = 0;
	while (find_occurence((char *)set, s1[i]))
		i++;
	start = i;
	end = ft_strlen((char *)s1);
	while (end > start && find_occurence((char *)set, s1[end - 1]))
		end--;
	if (start > end)
		return (ft_start_bigger_end());
	i = 0;
	trim = malloc(sizeof(char) * (end - start + 1));
	if (!trim)
		return (NULL);
	while (start < end)
		trim[i++] = s1[start++];
	trim[i] = '\0';
	return (trim);
}
