/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josamba- <josamba-@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:10:14 by josamba-          #+#    #+#             */
/*   Updated: 2026/04/07 10:10:17 by josamba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(char c)
{
	unsigned char	cast;

	cast = c;
	if ((cast >= 'a' && cast <= 'z')
		|| (cast >= 'A' && cast <= 'Z'))
		return (1);
	return (0);
}
