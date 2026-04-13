/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josamba- <josamba-@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:47:37 by josamba-          #+#    #+#             */
/*   Updated: 2026/04/07 10:47:39 by josamba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char *str, char c)
{
	size_t	i;
	size_t	count;
	size_t	is_word;

	i = 0;
	count = 0;
	is_word = 0;
	while (str[i])
	{
		if (str[i] != c && !is_word)
		{
			count++;
			is_word = 1;
		}
		else
			if (str[i] == c)
				is_word = 0;
		i++;
	}
	return (count);
}

static size_t	word_length(char *s, size_t start, char c)
{
	size_t	i;

	i = 0;
	while (s[start] && s[start] != c)
	{
		start++;
		i++;
	}
	return (i);
}

static void	fill_tab(char *s, char **tab, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[k])
	{
		j = 0;
		while (s[k] && s[k] == c)
			k++;
		if (word_length(s, k, c) == 0)
			break ;
		tab[i] = malloc(sizeof(char) *(word_length(s, k, c) + 1));
		while (s[k] && s[k] != c)
		{
			tab[i][j] = s[k];
			j++;
			k++;
		}
		tab[i][j] = '\0';
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	count;

	if (!s)
		return (NULL);
	count = count_words((char *)s, c);
	tab = malloc(sizeof(char *) * (count + 1));
	if (!tab)
		return (NULL);
	tab[count] = 0;
	fill_tab((char *)s, tab, c);
	return (tab);
}
