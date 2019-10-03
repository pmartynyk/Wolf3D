/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 10:50:38 by pmartyny          #+#    #+#             */
/*   Updated: 2019/10/03 10:50:39 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	ft_draw_floor(t_wolf3d *wolf3d)
{
	int y;

	y = wolf3d->camera->wall_y;
	while (y < HEIGHT)
	{
		wolf3d->camera->current_dist = HEIGHT / (2.0 * y - HEIGHT);
		wolf3d->camera->weight = wolf3d->camera->current_dist /
		wolf3d->camera->wall_dist;
		wolf3d->camera->curfx = wolf3d->camera->weight *
		wolf3d->camera->floor_x_wall + (1.0 - wolf3d->camera->weight) *
		wolf3d->player->start_x;
		wolf3d->camera->curfy = wolf3d->camera->weight *
		wolf3d->camera->floor_y_wall + (1.0 - wolf3d->camera->weight) *
		wolf3d->player->start_y;
		wolf3d->camera->ftx = (int)(wolf3d->camera->curfx * 64) % 64;
		wolf3d->camera->fty = (int)(wolf3d->camera->curfy * 64) % 64;
		pixel_put(wolf3d, y, ((int *)wolf3d->texture->ctexture[4])[64 *
		wolf3d->camera->fty + wolf3d->camera->ftx]);
		y++;
	}
}

void	ft_draw_celing(t_wolf3d *wolf3d)
{
	int y;

	y = 0;
	while (y < wolf3d->camera->wall_x)
	{
		wolf3d->camera->current_dist = HEIGHT / (2.0 * y - HEIGHT);
		wolf3d->camera->weight = -wolf3d->camera->current_dist /
		wolf3d->camera->wall_dist;
		wolf3d->camera->curfx = wolf3d->camera->weight *
		wolf3d->camera->floor_x_wall + (1.0 - wolf3d->camera->weight) *
		wolf3d->player->start_x;
		wolf3d->camera->curfy = wolf3d->camera->weight *
		wolf3d->camera->floor_y_wall + (1.0 - wolf3d->camera->weight) *
		wolf3d->player->start_y;
		wolf3d->camera->ftx = (int)(wolf3d->camera->curfx * 64) % 64;
		wolf3d->camera->fty = (int)(wolf3d->camera->curfy * 64) % 64;
		pixel_put(wolf3d, y, ((int *)wolf3d->texture->ctexture[5])[64 *
		wolf3d->camera->fty + wolf3d->camera->ftx]);
		y++;
	}
}

void	ft_init_floor_ceeling(t_wolf3d *wolf3d, int map_x, int map_y)
{
	if (wolf3d->side == 0 && wolf3d->camera->ray_dir_x > 0)
	{
		wolf3d->camera->floor_x_wall = map_x;
		wolf3d->camera->floor_y_wall = map_y + wolf3d->texture->wallx;
	}
	else if (wolf3d->side == 0 && wolf3d->camera->ray_dir_x < 0)
	{
		wolf3d->camera->floor_x_wall = map_x + 1.0;
		wolf3d->camera->floor_y_wall = map_y + wolf3d->texture->wallx;
		;
	}
	else if (wolf3d->side == 1 && wolf3d->camera->ray_dir_y > 0)
	{
		wolf3d->camera->floor_x_wall = map_x + wolf3d->texture->wallx;
		wolf3d->camera->floor_y_wall = map_y;
	}
	else
	{
		wolf3d->camera->floor_x_wall = map_x + wolf3d->texture->wallx;
		wolf3d->camera->floor_y_wall = map_y + 1.0;
	}
}
