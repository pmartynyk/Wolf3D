/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 15:52:55 by pmartyny          #+#    #+#             */
/*   Updated: 2018/10/31 17:40:54 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wrd_len(char *s, char c, int num)
{
	int i;
	int	cnt;
	int len;

	len = 0;
	cnt = 0;
	i = 0;
	while (s[i++])
	{
		if (s[i] != c)
		{
			if (cnt == num)
			{
				while (s[i] != c && s[i])
				{
					len++;
					i++;
				}
				return (len);
			}
			else if (s[i + 1] == c || s[i + 1] == '\0')
				cnt++;
		}
	}
	return (0);
}

static int	wrd_cnt(char const *s, char c)
{
	int i;
	int	cnt;

	cnt = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
				i++;
			cnt++;
		}
		i++;
	}
	return (cnt);
}

static char	*wrd_val(char *s, char c, int num, int len)
{
	int		i;
	int		j;
	int		cnt;
	char	*res;

	cnt = 0;
	i = -1;
	j = 0;
	while (s[++i])
	{
		if (s[i] != c)
		{
			if (cnt == num)
			{
				res = (char *)malloc(sizeof(char) * (len) + 1);
				while (s[i] != c && s[i])
					res[j++] = s[i++];
				res[j] = '\0';
				return (res);
			}
			else if (s[i + 1] == c || s[i + 1] == '\0')
				cnt++;
		}
	}
	return (0);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		len;
	int		cnt;
	char	**res;

	if (s == 0)
		return (0);
	i = 0;
	j = 0;
	cnt = wrd_cnt((char *)s, c);
	res = (char **)malloc(sizeof(char *) * (cnt) + 1);
	if (res == 0)
		return (NULL);
	while (i < cnt)
	{
		len = wrd_len((char *)s, c, i);
		res[i] = wrd_val((char *)s, c, i, len);
		i++;
	}
	res[i] = NULL;
	return (res);
}
