/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:50:04 by pmartyny          #+#    #+#             */
/*   Updated: 2019/10/01 10:50:06 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	ft_up(t_wolf3d *wolf3d)
{
	if (wolf3d->map[(int)(wolf3d->player->start_y)][(int)
	(wolf3d->player->start_x + wolf3d->player->dir_x *
	(wolf3d->camera->move_speed + 0.5))] != 1)
		wolf3d->player->start_x += wolf3d->player->dir_x
		* wolf3d->camera->move_speed;
	if (wolf3d->map[(int)(wolf3d->player->start_y + wolf3d->player->dir_y *
	(wolf3d->camera->move_speed + 0.5))][(int)(wolf3d->player->start_x)] != 1)
		wolf3d->player->start_y +=
		wolf3d->player->dir_y * wolf3d->camera->move_speed;
}

static void	ft_down(t_wolf3d *wolf3d)
{
	if (wolf3d->map[(int)(wolf3d->player->start_y)]
	[(int)(wolf3d->player->start_x - wolf3d->player->dir_x *
	(wolf3d->camera->move_speed + 0.5))] != 1)
		wolf3d->player->start_x -= wolf3d->player->dir_x *
		wolf3d->camera->move_speed;
	if (wolf3d->map[(int)(wolf3d->player->start_y - wolf3d->player->dir_y *
	(wolf3d->camera->move_speed + 0.5))][(int)(wolf3d->player->start_x)] != 1)
		wolf3d->player->start_y -= wolf3d->player->dir_y *
		wolf3d->camera->move_speed;
}

static void	ft_right(t_wolf3d *wolf3d)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = wolf3d->player->dir_x;
	wolf3d->player->dir_x = wolf3d->player->dir_x *
	cos(wolf3d->camera->rotate_speed) - wolf3d->player->dir_y *
	sin(wolf3d->camera->rotate_speed);
	wolf3d->player->dir_y = old_dir_x * sin(wolf3d->camera->rotate_speed) +
	wolf3d->player->dir_y * cos(wolf3d->camera->rotate_speed);
	old_plane_x = wolf3d->player->plane_x;
	wolf3d->player->plane_x = wolf3d->player->plane_x *
	cos(wolf3d->camera->rotate_speed) - wolf3d->player->plane_y *
	sin(wolf3d->camera->rotate_speed);
	wolf3d->player->plane_y = old_plane_x * sin(wolf3d->camera->rotate_speed) +
	wolf3d->player->plane_y * cos(wolf3d->camera->rotate_speed);
}

static void	ft_left(t_wolf3d *wolf3d)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = wolf3d->player->dir_x;
	wolf3d->player->dir_x = wolf3d->player->dir_x *
	cos(-wolf3d->camera->rotate_speed) - wolf3d->player->dir_y *
	sin(-wolf3d->camera->rotate_speed);
	wolf3d->player->dir_y = old_dir_x * sin(-wolf3d->camera->rotate_speed) +
	wolf3d->player->dir_y * cos(-wolf3d->camera->rotate_speed);
	old_plane_x = wolf3d->player->plane_x;
	wolf3d->player->plane_x = wolf3d->player->plane_x *
	cos(-wolf3d->camera->rotate_speed) - wolf3d->player->plane_y *
	sin(-wolf3d->camera->rotate_speed);
	wolf3d->player->plane_y = old_plane_x *
	sin(-wolf3d->camera->rotate_speed) + wolf3d->player->plane_y *
	cos(-wolf3d->camera->rotate_speed);
}

void		ft_move(t_wolf3d *wolf3d)
{
	if (wolf3d->player->up)
		ft_up(wolf3d);
	if (wolf3d->player->down)
		ft_down(wolf3d);
	if (wolf3d->player->left)
		ft_left(wolf3d);
	if (wolf3d->player->right)
		ft_right(wolf3d);
	if (wolf3d->player->run)
		wolf3d->camera->move_speed = 0.1;
	else
		wolf3d->camera->move_speed = 0.05;
}
