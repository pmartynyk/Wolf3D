/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 09:57:35 by pmartyny          #+#    #+#             */
/*   Updated: 2019/09/28 09:57:36 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void ft_fill_map(char *line, t_wolf3d *wolf3d, int i)
{
	int		num;
	int		k;
	char	**tmp_map;

	if (wolf3d->map_length == 0)
		wolf3d->map_length = ft_count_length(line);
	if (wolf3d->map_length == ft_count_length(line))
	{
		wolf3d->map[i] = (int *)malloc(sizeof(int) * wolf3d->map_length + 1);
		k = 0;
		tmp_map = ft_strsplit(line, 32);
		while (k < wolf3d->map_length)
		{
			num = ft_atoi(tmp_map[k]);
			wolf3d->map[i][k] = i;
			k++;
		}
		ft_free(tmp_map);
	}
	else
		ERROR("Error. Wrong line length.");
}

void ft_read(char *file, t_wolf3d *wolf3d)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	wolf3d->map_height = ft_count_height(file);
	if (wolf3d->map_height < 3 || wolf3d->map_height > 500)
		ERROR("Error map size\n");
	wolf3d->map = (int **)malloc(sizeof(int *) * wolf3d->map_height + 1);
	fd = ft_checkfile(file);
	while (get_next_line(fd, &line) > 0)
	{
		ft_fill_map(line, wolf3d, i);
		free(line);
		i++;
	}
}
