/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 10:55:53 by pmartyny          #+#    #+#             */
/*   Updated: 2019/10/03 10:55:55 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	pixel_put(t_wolf3d *wolf3d, int y, int color)
{
	if (wolf3d->x_pos < WIDTH && wolf3d->x_pos >= 0 && y < HEIGHT && y >= 0)
		wolf3d->image_buf[y * WIDTH + (int)wolf3d->x_pos] = color;
}

void	ft_chose_texture(t_wolf3d *wolf3d)
{
	if (wolf3d->player->step_x < 0)
		wolf3d->texture->texture_n = 0;
	else if (wolf3d->player->step_x > 0)
		wolf3d->texture->texture_n = 1;
	if (wolf3d->side == 1)
	{
		if (wolf3d->player->step_y < 0)
			wolf3d->texture->texture_n = 2;
		else if (wolf3d->player->step_y > 0)
			wolf3d->texture->texture_n = 3;
	}
}

void	ft_calc_texture(t_wolf3d *wolf3d)
{
	if (wolf3d->side == 0)
		wolf3d->texture->wallx = wolf3d->player->start_y +
		wolf3d->camera->wall_dist * wolf3d->camera->ray_dir_y;
	else
		wolf3d->texture->wallx = wolf3d->player->start_x +
		wolf3d->camera->wall_dist * wolf3d->camera->ray_dir_x;
	wolf3d->texture->wallx -= floor((wolf3d->texture->wallx));
	wolf3d->texture->texture_x = (int)(wolf3d->texture->wallx * (double)64);
	if (wolf3d->side == 0 && wolf3d->camera->ray_dir_x > 0)
		wolf3d->texture->texture_x = 64 - wolf3d->texture->texture_x - 1;
	if (wolf3d->side == 1 && wolf3d->camera->ray_dir_y < 0)
		wolf3d->texture->texture_x = 64 - wolf3d->texture->texture_x - 1;
}

void	ft_draw(t_wolf3d *wolf3d, int map_x, int map_y)
{
	int y;
	int d;
	int texy;

	ft_chose_texture(wolf3d);
	ft_calc_texture(wolf3d);
	ft_init_floor_ceeling(wolf3d, map_x, map_y);
	ft_draw_celing(wolf3d);
	y = wolf3d->camera->wall_x - 1;
	while (++y <= wolf3d->camera->wall_y)
	{
		d = y * 256 - HEIGHT * 128 + wolf3d->camera->wall_height * 128;
		texy = ((d * 64) / wolf3d->camera->wall_height) / 256;
		if (texy < 0)
			texy = 0;
		wolf3d->camera->color = ((int *)wolf3d->texture->
		ctexture[wolf3d->texture->texture_n])
			[64 * texy + wolf3d->texture->texture_x];
		if (wolf3d->side == 1)
			wolf3d->camera->color = (wolf3d->camera->color >> 1) & 8355711;
		pixel_put(wolf3d, y, wolf3d->camera->color);
	}
	ft_init_floor_ceeling(wolf3d, map_x, map_y);
	ft_draw_floor(wolf3d);
}
