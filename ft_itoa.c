/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josamba- <josamba-@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:48:22 by josamba-          #+#    #+#             */
/*   Updated: 2026/04/07 10:48:24 by josamba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_numbers(int n)
{
	size_t	count;

	count = 0;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char	*ft_strrev(char *tab)
{
	size_t	index;
	size_t	i;
	size_t	len;
	char	temp;

	i = 0;
	len = 0;
	while (tab[len])
		len++;
	index = len;
	while (i < len / 2)
	{
		temp = tab[index - 1];
		tab[index - 1] = tab[i];
		tab[i] = temp;
		i++;
		index--;
	}
	return (tab);
}

static char	*min_null(int n)
{
	char	*tab;

	if (n == 0)
	{
		tab = malloc(sizeof(char) * 2);
		if (!tab)
			return (NULL);
		ft_strlcpy(tab, "0", 2);
		return (tab);
	}
	tab = malloc(sizeof(char) * 12);
	if (!tab)
		return (NULL);
	ft_strlcpy(tab, "-2147483648", 12);
	return (tab);
}

char	*ft_itoa(int n)
{
	char	*tab;
	size_t	i;
	size_t	count;

	i = 0;
	if (n == INT_MIN || n == 0)
		return (min_null(n));
	count = count_numbers(n);
	tab = malloc(sizeof(char) * (count + 1));
	if (!tab)
		return (NULL);
	if (n < 0)
	{
		tab[count - 1] = '-';
		n = -n;
	}
	while (n > 0)
	{
		tab[i] = n % 10 + 48;
		n = n / 10;
		i++;
	}
	tab[count] = '\0';
	tab = ft_strrev(tab);
	return (tab);
}
