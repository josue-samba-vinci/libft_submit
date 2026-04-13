/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josamba- <josamba-@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:54:06 by josamba-          #+#    #+#             */
/*   Updated: 2026/04/07 10:54:08 by josamba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*current;
	t_list	*start;

	current = lst;
	start = NULL;
	if (!lst)
		return (NULL);
	while (current != NULL)
	{
		new_node = ft_lstnew(current->content);
		if (new_node == NULL)
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		new_node->content = f(current->content);
		ft_lstadd_back(&start, new_node);
		current = current->next;
	}
	return (start);
}
