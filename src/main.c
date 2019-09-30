/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 09:57:29 by pmartyny          #+#    #+#             */
/*   Updated: 2019/09/28 09:57:30 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/wolf3d.h"

static void	ft_mlx_init(t_wolf3d *wolf3d)
{
	wolf3d->mlx = mlx_init();
	wolf3d->image = mlx_new_image(wolf3d->mlx, WIDTH, HEIGHT);
	wolf3d->image_buf = (int *)mlx_get_data_addr(wolf3d->image,
	&wolf3d->bits_per_pixel, &wolf3d->size_line, &wolf3d->endian);
	wolf3d->win = mlx_new_window(wolf3d->mlx, WIDTH, HEIGHT, "Wolf3d");
}

static void ft_init_player(t_wolf3d *wolf3d)
{
	wolf3d->map_height = 0;
	wolf3d->map_length = 0;
	wolf3d->player = (t_player*)malloc(sizeof(t_player));
	wolf3d->camera = (t_camera*)malloc(sizeof(t_camera));
	wolf3d->player->dir_x = 1;
	wolf3d->player->dir_y = 0;
	wolf3d->player->plane_x = 0;
	wolf3d->player->plane_y = 0.66;
	// wolf3d->player->up = 0;
	// wolf3d->player->down = 0;
	// wolf3d->player->left = 0;
	// wolf3d->player->right = 0;
	wolf3d->player->start_x = 0;
	wolf3d->player->start_y = 0;
	wolf3d->time = 0;
	wolf3d->old_time = 0;
	wolf3d->side = 0;
	wolf3d->camera->wall_height = 0;
}

static int	ft_check_button(int button, t_wolf3d *wolf3d)
{
	(void)wolf3d;
	if (button == 53)
		exit(0);
	return (0);
}

static int	ft_close(t_wolf3d *wolf3d)
{
	(void)wolf3d;
	exit(0);
}

int			main(int argc, char **argv)
{
	t_wolf3d *wolf3d;

	if (argc == 2)
	{
		if (!(wolf3d = (t_wolf3d *)malloc(sizeof(t_wolf3d))))
			exit(0);
		ft_init_player(wolf3d);
		ft_read(argv[1], wolf3d);
		ft_mlx_init(wolf3d);
		mlx_loop_hook(wolf3d->mlx, ft_raycast, wolf3d);
		mlx_hook(wolf3d->win, 2, 0, ft_check_button, wolf3d);
		mlx_hook(wolf3d->win, 17, 0, ft_close, wolf3d);
		mlx_loop(wolf3d->mlx);
		ft_raycast(wolf3d);
	}
	else
		ft_printf("Usage: ./wolf3d [map name]\n");
}
