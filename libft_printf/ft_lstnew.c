/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 10:25:43 by pmartyny          #+#    #+#             */
/*   Updated: 2018/10/31 18:11:39 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*t;

	t = (t_list *)malloc(sizeof(t_list) * content_size);
	if (t == 0)
		return (0);
	if (content == 0)
	{
		t->content = NULL;
		t->content_size = 0;
		t->next = NULL;
	}
	else
	{
		if ((t->content = malloc(content_size)) == 0)
			return (0);
		t->content = ft_memcpy(t->content, (void *)content, content_size);
		t->content_size = content_size;
		t->next = NULL;
	}
	return (t);
}
