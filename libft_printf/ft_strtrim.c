/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 13:49:41 by pmartyny          #+#    #+#             */
/*   Updated: 2018/10/31 13:43:38 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_start(char *s)
{
	int i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	{
		i++;
	}
	return (i);
}

static int	find_finish(char *s)
{
	int i;

	i = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	{
		i--;
	}
	return (i);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		start;
	int		finish;
	char	*res;

	if (s == NULL)
		return (NULL);
	i = 0;
	start = find_start((char *)s);
	finish = find_finish((char *)s);
	res = (char *)malloc(sizeof(char) *
			(finish - start < 0 ? 1 : finish - start + 2));
	if (res == 0)
		return (0);
	while (start <= finish)
	{
		res[i] = s[start];
		i++;
		start++;
	}
	res[i] = '\0';
	return (res);
}
