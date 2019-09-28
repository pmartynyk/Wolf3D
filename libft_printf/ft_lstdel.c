/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 11:37:45 by pmartyny          #+#    #+#             */
/*   Updated: 2018/11/05 10:22:11 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *t;

	if (alst && *alst)
	{
		t = *alst;
		while (t != NULL)
		{
			del(t->content, t->content_size);
			*alst = NULL;
			free(t);
			t = t->next;
		}
	}
}
