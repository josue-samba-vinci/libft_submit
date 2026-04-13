/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josamba- <josamba-@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:47:21 by josamba-          #+#    #+#             */
/*   Updated: 2026/04/07 10:47:23 by josamba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	tab[11];
	size_t	i;

	i = 0;
	if (n == INT_MIN || n == 0)
	{
		if (n == INT_MIN)
			write (fd, "-2147483648", 11);
		if (n == 0)
			write (fd, "0", 1);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		write (fd, "-", 1);
	}
	while (n > 0)
	{
		tab[i++] = n % 10 + 48;
		n = n / 10;
	}
	while (i > 0)
		write(fd, &tab[--i], 1);
}
