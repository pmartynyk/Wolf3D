/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 10:40:23 by pmartyny          #+#    #+#             */
/*   Updated: 2019/10/03 10:40:24 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	ft_init_texture_add(t_wolf3d *wolf3d)
{
	int			w;
	int			h;

	if (!(wolf3d->texture->texture[0] = mlx_xpm_file_to_image(wolf3d->mlx,
	"./texture/bluestone.xpm", &w, &h)))
		ERROR("Error. Load texture!\n");
	if (!(wolf3d->texture->texture[1] = mlx_xpm_file_to_image(wolf3d->mlx,
	"./texture/colorstone.xpm", &w, &h)))
		ERROR("Error. Load texture!\n");
	if (!(wolf3d->texture->texture[2] = mlx_xpm_file_to_image(wolf3d->mlx,
	"./texture/greystone.xpm", &w, &h)))
		ERROR("Error. Load texture!\n");
	if (!(wolf3d->texture->texture[3] = mlx_xpm_file_to_image(wolf3d->mlx,
	"./texture/redbrick.xpm", &w, &h)))
		ERROR("Error. Load texture!\n");
	if (!(wolf3d->texture->texture[4] = mlx_xpm_file_to_image(wolf3d->mlx,
	"./texture/wood.xpm", &w, &h)))
		ERROR("Error. Load texture!\n");
	if (!(wolf3d->texture->texture[5] = mlx_xpm_file_to_image(wolf3d->mlx,
	"./texture/greenlight.xpm", &w, &h)))
		ERROR("Error. Load texture!\n");
}

void		ft_init_texture(t_wolf3d *wolf3d)
{
	int			bpp;
	int			sl;
	int			end;
	int			w;

	w = 0;
	if (!(wolf3d->texture = (t_texture*)malloc(sizeof(t_texture))))
		exit(1);
	wolf3d->texture->texture = (void**)malloc(sizeof(void*) * 6);
	wolf3d->texture->ctexture = (char**)malloc(sizeof(char*) * 6);
	ft_init_texture_add(wolf3d);
	while (w < 6)
	{
		wolf3d->texture->ctexture[w] =
		mlx_get_data_addr(wolf3d->texture->texture[w], &bpp, &sl, &end);
		w++;
	}
}

void		ft_mlx_init(t_wolf3d *wolf3d)
{
	wolf3d->mlx = mlx_init();
	wolf3d->win = mlx_new_window(wolf3d->mlx, WIDTH, HEIGHT, "Wolf3d");
}

static void	ft_init_camera(t_wolf3d *wolf3d)
{
	wolf3d->camera = (t_camera*)malloc(sizeof(t_camera));
	wolf3d->camera->wall_height = 0;
	wolf3d->camera->move_speed = 0.05;
	wolf3d->camera->rotate_speed = 0.05;
}

void		ft_init_player(t_wolf3d *wolf3d)
{
	wolf3d->map_height = 0;
	wolf3d->map_length = 0;
	wolf3d->music = 0;
	wolf3d->player = (t_player*)malloc(sizeof(t_player));
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
	ft_init_camera(wolf3d);
}
