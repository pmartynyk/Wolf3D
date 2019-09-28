/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 10:31:43 by pmartyny          #+#    #+#             */
/*   Updated: 2019/09/24 10:31:45 by pmartyny         ###   ########.fr       */
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
	(void)argv;
	t_wolf3d *wolf3d;

	if (argc == 2)
	{
		if (!(wolf3d = (t_wolf3d *)malloc(sizeof(t_wolf3d))))
			exit(0);
		ft_mlx_init(wolf3d);
		mlx_hook(wolf3d->win, 2, 0, ft_check_button, wolf3d);
		mlx_hook(wolf3d->win, 17, 0, ft_close, wolf3d);
		mlx_loop(wolf3d->mlx);
	}
	else
		ft_printf("Usage: ./fractol [fractol name]\n");
}
