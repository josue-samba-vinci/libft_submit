/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josamba- <josamba-@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:53:37 by josamba-          #+#    #+#             */
/*   Updated: 2026/04/07 10:53:39 by josamba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*temp;

	if (!lst || !*lst)
		return ;
	current = *lst;
	while (current->next != NULL)
	{
		temp = current->next;
		del(current->content);
		free(current);
		current = temp;
	}
	del(current->content);
	free(current);
	*lst = NULL;
}
