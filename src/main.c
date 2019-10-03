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

static void ft_init_texture(t_wolf3d *wolf3d)
{
	int			bpp;
	int			sl;
	int			end;
	int			w;
	int			h;

	if (!(wolf3d->texture = (t_texture*)malloc(sizeof(t_texture))))
		exit(1);
	wolf3d->texture->texture = (void**)malloc(sizeof(void*) * 6);
	wolf3d->texture->ctexture = (char**)malloc(sizeof(char*) * 6);
	if (!(wolf3d->texture->texture[0] = mlx_xpm_file_to_image(wolf3d->mlx, "./texture/bluestone.xpm", &w, &h)))
		ERROR("Error. Load texture!\n");
	if (!(wolf3d->texture->texture[1] = mlx_xpm_file_to_image(wolf3d->mlx, "./texture/colorstone.xpm", &w, &h)))
		ERROR("Error. Load texture!\n");
	if (!(wolf3d->texture->texture[2] = mlx_xpm_file_to_image(wolf3d->mlx, "./texture/greystone.xpm", &w, &h)))
		ERROR("Error. Load texture!\n");
	if (!(wolf3d->texture->texture[3] = mlx_xpm_file_to_image(wolf3d->mlx, "./texture/redbrick.xpm", &w, &h)))
		ERROR("Error. Load texture!\n");
	if (!(wolf3d->texture->texture[4] = mlx_xpm_file_to_image(wolf3d->mlx, "./texture/wood.xpm", &w, &h)))
		ERROR("Error. Load texture!\n");
	if (!(wolf3d->texture->texture[5] = mlx_xpm_file_to_image(wolf3d->mlx, "./texture/greenlight.xpm", &w, &h)))
		ERROR("Error. Load texture!\n");
	w = 0;
	while (w < 6)
	{
		wolf3d->texture->ctexture[w] = mlx_get_data_addr(wolf3d->texture->texture[w], &bpp, &sl, &end);
		w++;
	}
}

static void	ft_mlx_init(t_wolf3d *wolf3d)
{
	wolf3d->mlx = mlx_init();
	wolf3d->win = mlx_new_window(wolf3d->mlx, WIDTH, HEIGHT, "Wolf3d");
}

static void ft_init_player(t_wolf3d *wolf3d)
{
	wolf3d->map_height = 0;
	wolf3d->map_length = 0;
	wolf3d->music = 0;
	wolf3d->player = (t_player*)malloc(sizeof(t_player));
	wolf3d->camera = (t_camera*)malloc(sizeof(t_camera));
	wolf3d->player->dir_x = 1;
	wolf3d->player->dir_y = 0;
	wolf3d->player->plane_x = 0;
	wolf3d->player->plane_y = 0.66;
	wolf3d->player->up = 0;
	wolf3d->player->down = 0;
	wolf3d->player->left = 0;
	wolf3d->player->right = 0;
	wolf3d->player->run = 0;
	wolf3d->player->start_x = 0;
	wolf3d->player->start_y = 0;
	wolf3d->time = 0;
	wolf3d->old_time = 0;
	wolf3d->side = 0;
	wolf3d->camera->wall_height = 0;
	wolf3d->camera->move_speed = 0.05;
	wolf3d->camera->rotate_speed = 0.05;

}

static int	ft_check_move(int button, t_wolf3d *wolf3d)
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
		wolf3d->player->run =!wolf3d->player->run;
	return (0);
}


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
		// wolf3d->mlx = mlx_init();
		ft_mlx_init(wolf3d);
		ft_init_texture(wolf3d);
		// wolf3d->win = mlx_new_window(wolf3d->mlx, WIDTH, HEIGHT, "Wolf3d");
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
