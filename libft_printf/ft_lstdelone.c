/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 11:06:04 by pmartyny          #+#    #+#             */
/*   Updated: 2018/10/31 18:04:24 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list *t;

	if (alst && *alst)
	{
		t = *alst;
		del(t->content, t->content_size);
		*alst = NULL;
		free(t);
		t->next = NULL;
	}
}
