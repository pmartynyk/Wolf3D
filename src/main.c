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

static int	ft_check_button(int button, t_wolf3d *wolf3d)
{
	if (button == 53)
	{
		if (wolf3d->music == 1)
			system("killall afplay");
		mlx_destroy_window(wolf3d->mlx, wolf3d->win);
		exit(0);
	}
	if (button == MUSIC)
		ft_music(wolf3d);
	ft_check_move(button, wolf3d);
	return (0);
}

static int	ft_close(t_wolf3d *wolf3d)
{
	if (wolf3d->music == 1)
		system("killall afplay");
	mlx_destroy_window(wolf3d->mlx, wolf3d->win);
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
		ft_init_texture(wolf3d);
		mlx_do_key_autorepeatoff(wolf3d->mlx);
		mlx_loop_hook(wolf3d->mlx, ft_raycast, wolf3d);
		mlx_hook(wolf3d->win, 2, 0, ft_check_button, wolf3d);
		mlx_hook(wolf3d->win, 17, 0, ft_close, wolf3d);
		mlx_key_hook(wolf3d->win, ft_check_move, wolf3d);
		mlx_loop(wolf3d->mlx);
	}
	else
		ft_printf("Usage: ./wolf3d [map name]\n");
}
