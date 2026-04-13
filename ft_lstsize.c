/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josamba- <josamba-@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:54:19 by josamba-          #+#    #+#             */
/*   Updated: 2026/04/07 10:54:22 by josamba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		length;
	t_list	*current;

	current = lst;
	length = 0;
	if (current == NULL)
		return (0);
	while (current->next != NULL)
	{
		length++;
		current = current->next;
	}
	length++;
	return (length);
}
