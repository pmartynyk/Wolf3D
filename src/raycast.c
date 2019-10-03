/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 11:20:02 by pmartyny          #+#    #+#             */
/*   Updated: 2019/09/29 11:20:04 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	ft_calc_wall(t_wolf3d *wolf3d, int map_x, int map_y)
{
	if (wolf3d->side == 0)
		wolf3d->camera->wall_dist = (map_x - wolf3d->player->start_x +
		(1.0 - wolf3d->player->step_x) / 2.0) /
		wolf3d->camera->ray_dir_x;
	else
		wolf3d->camera->wall_dist = (map_y - wolf3d->player->start_y +
		(1.0 - wolf3d->player->step_y) / 2.0) /
		wolf3d->camera->ray_dir_y;
	wolf3d->camera->wall_height = (int)(HEIGHT / wolf3d->camera->wall_dist);
	wolf3d->camera->wall_x = -wolf3d->camera->wall_height / 2 + HEIGHT / 2;
	if (wolf3d->camera->wall_x < 0)
		wolf3d->camera->wall_x = 0;
	wolf3d->camera->wall_y = wolf3d->camera->wall_height / 2 + HEIGHT / 2;
	if (wolf3d->camera->wall_y >= HEIGHT)
		wolf3d->camera->wall_y = HEIGHT - 1;
	ft_draw(wolf3d, map_x, map_y);
}

static void	ft_dda(t_wolf3d *wolf3d, int map_x, int map_y)
{
	int wall;

	wall = 0;
	while (wall == 0)
	{
		if (wolf3d->camera->sd_x < wolf3d->camera->sd_y)
		{
			wolf3d->camera->sd_x += wolf3d->camera->dd_x;
			map_x += wolf3d->player->step_x;
			wolf3d->side = 0;
		}
		else
		{
			wolf3d->camera->sd_y += wolf3d->camera->dd_y;
			map_y += wolf3d->player->step_y;
			wolf3d->side = 1;
		}
		if (wolf3d->map[map_y][map_x] == 1)
			wall = 1;
	}
	ft_calc_wall(wolf3d, map_x, map_y);
}

static void	ft_calculate_step(t_wolf3d *wolf3d, int map_x, int map_y)
{
	if (wolf3d->camera->ray_dir_x < 0)
	{
		wolf3d->player->step_x = -1;
		wolf3d->camera->sd_x = (wolf3d->player->start_x - map_x) *
		wolf3d->camera->dd_x;
	}
	else
	{
		wolf3d->player->step_x = 1;
		wolf3d->camera->sd_x = (map_x + 1.0 - wolf3d->player->start_x) *
		wolf3d->camera->dd_x;
	}
	if (wolf3d->camera->ray_dir_y < 0)
	{
		wolf3d->player->step_y = -1;
		wolf3d->camera->sd_y = (wolf3d->player->start_y - map_y) *
		wolf3d->camera->dd_y;
	}
	else
	{
		wolf3d->player->step_y = 1;
		wolf3d->camera->sd_y = (map_y + 1.0 - wolf3d->player->start_y) *
		wolf3d->camera->dd_y;
	}
}

static void	ft_init_camera(t_wolf3d *wolf3d)
{
	wolf3d->camera->cam_x = 2 * wolf3d->x_pos / (double)WIDTH - 1;
	wolf3d->camera->ray_dir_x = wolf3d->player->dir_x +
	wolf3d->player->plane_x * wolf3d->camera->cam_x;
	wolf3d->camera->ray_dir_y = wolf3d->player->dir_y +
	wolf3d->player->plane_y * wolf3d->camera->cam_x;
	wolf3d->camera->dd_x = fabs(1 / wolf3d->camera->ray_dir_x);
	wolf3d->camera->dd_y = fabs(1 / wolf3d->camera->ray_dir_y);
}

int			ft_raycast(t_wolf3d *wolf3d)
{
	int map_x;
	int map_y;

	wolf3d->x_pos = 0;
	wolf3d->image = mlx_new_image(wolf3d->mlx, WIDTH, HEIGHT);
	wolf3d->image_buf = (int *)mlx_get_data_addr(wolf3d->image,
	&wolf3d->bits_per_pixel, &wolf3d->size_line, &wolf3d->endian);
	ft_move(wolf3d);
	while (wolf3d->x_pos < WIDTH)
	{
		ft_init_camera(wolf3d);
		map_x = (int)wolf3d->player->start_x;
		map_y = (int)wolf3d->player->start_y;
		ft_calculate_step(wolf3d, map_x, map_y);
		ft_dda(wolf3d, map_x, map_y);
		wolf3d->x_pos++;
	}
	mlx_put_image_to_window(wolf3d->mlx, wolf3d->win, wolf3d->image, 0, 0);
	mlx_destroy_image(wolf3d->mlx, wolf3d->image);
	return (0);
}
