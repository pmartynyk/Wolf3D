/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:10:17 by pmartyny          #+#    #+#             */
/*   Updated: 2018/10/31 12:26:33 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *t;

	if (!lst || !f)
		return (NULL);
	if ((t = malloc(sizeof(t_list))))
	{
		t = f(lst);
		t->next = ft_lstmap(lst->next, f);
	}
	else
		t->next = NULL;
	return (t);
}
