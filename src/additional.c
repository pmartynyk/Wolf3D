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

int		ft_checkfile(char *file)
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

int ft_check_line(char *line, int line_num, t_wolf3d *wolf3d)
{
	int line_len;
	INT1(i, 0);
	line_len = ft_strlen(line);
	while (line[i])
	{
		if (line_num == 0 || line_num == wolf3d->map_height - 1)
		{
			if (line[i] != '1' && line[i] != ' ')
			{
				ft_printf("%c %d %d\n", line[i], line_num, i);
				return (0);
			}
		}
		else
		{
			if (line[i] == '2')
			{
				wolf3d->player->start_x = i;
				wolf3d->player->start_y = line_num;
			}
			if (i == 0 || i == line_len - 1)
			{
				if (line[i] != '1' && line[i] != ' ')
					return (0);
			}
			else if (line[i] != '0' && line[i] != '1' && line[i] != '2' && line[i] != ' ')
				return (0);			
		}
		i++;
	}
	return (1);
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
