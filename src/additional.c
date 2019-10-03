/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 10:00:35 by pmartyny          #+#    #+#             */
/*   Updated: 2019/09/28 10:00:37 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		ft_check_move(int button, t_wolf3d *wolf3d)
{
	if (button == KEYUP)
		wolf3d->player->up = !wolf3d->player->up;
	if (button == KEYDOWN)
		wolf3d->player->down = !wolf3d->player->down;
	if (button == KEYLEFT)
		wolf3d->player->left = !wolf3d->player->left;
	if (button == KEYRIGHT)
		wolf3d->player->right = !wolf3d->player->right;
	if (button == RUN)
		wolf3d->player->run = !wolf3d->player->run;
	return (0);
}

void	ft_music(t_wolf3d *wolf3d)
{
	if (wolf3d->music == 1)
		wolf3d->music = 0;
	else if (wolf3d->music == 0)
		wolf3d->music = 1;
	if (wolf3d->music == 1)
		system("afplay ./texture/Wolf.mp3&");
	else if (wolf3d->music == 0)
		system("killall afplay");
}

void	ft_free(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int		ft_count_length(char *str)
{
	int i;
	int cnt;

	i = 0;
	cnt = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			cnt++;
		i++;
	}
	return (cnt);
}

int		ft_count_height(char *file)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = ft_checkfile(file);
	while (get_next_line(fd, &line) > 0)
	{
		free(line);
		i++;
	}
	close(fd);
	return (i);
}
