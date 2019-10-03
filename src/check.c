/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 10:29:28 by pmartyny          #+#    #+#             */
/*   Updated: 2019/10/03 10:29:29 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		ft_check_start(t_wolf3d *wolf3d)
{
	if (wolf3d->player->start_x == 0 || wolf3d->player->start_x == 0)
		ERROR("Please put start point!\n");
}

int			ft_checkfile(char *file)
{
	int fd;

	fd = 0;
	if (!(ft_strstr(file, ".w3d")))
	{
		ft_printf("Invalid file\n");
		exit(0);
	}
	else if ((fd = open(file, O_DIRECTORY)) >= 0)
	{
		ft_printf("Invalid file\n");
		exit(0);
	}
	else if ((fd = open(file, O_RDONLY)) < 0)
	{
		ft_printf("Invalid file\n");
		exit(0);
	}
	return (fd);
}

static int	ft_check_values(char *line, int line_num, int i, t_wolf3d *wolf3d)
{
	int line_len;

	line_len = ft_strlen(line);
	if (line[i] == '2')
	{
		if (wolf3d->player->start_x == 0 || wolf3d->player->start_x == 0)
		{
			wolf3d->player->start_x = i + 0.5;
			wolf3d->player->start_y = line_num + 0.5;
		}
		else
			ERROR("Too many start points!\n");
	}
	if (i == 0 || i == line_len - 1)
	{
		if (line[i] != '1' && line[i] != ' ')
			return (0);
	}
	else if (line[i] != '0' && line[i] != '1' &&
	line[i] != '2' && line[i] != ' ')
		return (0);
	return (1);
}

int			ft_check_line(char *line, int line_num, t_wolf3d *wolf3d)
{
	INT1(i, 0);
	while (line[i])
	{
		if (line_num == 0 || line_num == wolf3d->map_height - 1)
		{
			if (line[i] != '1' && line[i] != ' ')
				return (0);
		}
		else
		{
			if (ft_check_values(line, line_num, i, wolf3d) == 0)
				return (0);
		}
		i++;
	}
	return (1);
}
