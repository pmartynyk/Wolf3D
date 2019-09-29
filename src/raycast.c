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

static void pixel_put(t_wolf3d *wolf3d, int y, int x, int color)
{
    if (x < WIDTH && x >= 0 && y < HEIGHT && y >= 0)
        wolf3d->image_buf[y * WIDTH + x] = color;
}

static void ft_draw(t_wolf3d *wolf3d, int map_x, int map_y)
{
    int y;
    int d;
    int texy;

    y = -1;
    y = wolf3d->camera->wall_x;
    while (++y <= wolf3d->camera->wall_x)
    {
        d = y * 256 - HEIGHT * 128 + wolf3d->camera->wall_height * 128;
        texy = ((d * 700) / wolf3d->camera->wall_height) / 256;
        if (texy < 0)
            texy = 0;
        wolf3d->camera->color = 8355711;
       if (wolf3d->side == 1)
            wolf3d->camera->color = (wolf3d->camera->color >> 1) & 8355711;
        pixel_put(wolf3d, map_y, map_x, wolf3d->camera->color);
    }
    y--;
}

static void ft_calc_wall(t_wolf3d *wolf3d, int map_x, int map_y)
{
    if (wolf3d->side == 0)
        wolf3d->camera->wall_dist = (map_x - wolf3d->player->start_x + (1.0 - wolf3d->player->step_x) / 2.0) / wolf3d->camera->ray_dir_x;
    else
        wolf3d->camera->wall_dist = (map_y - wolf3d->player->start_y +
                                     (1.0 - wolf3d->player->step_y) / 2.0) /
                                    wolf3d->camera->ray_dir_y;
    wolf3d->camera->wall_height = (int)(HEIGHT / wolf3d->camera->wall_dist);
    wolf3d->camera->wall_x = -wolf3d->camera->wall_height / 2.0 + HEIGHT / 2.0;
    if (wolf3d->camera->wall_x < 0)
        wolf3d->camera->wall_x = 0;
    wolf3d->camera->wall_y = wolf3d->camera->wall_height / 2.0 + HEIGHT / 2.0;
    if (wolf3d->camera->wall_y >= HEIGHT)
        wolf3d->camera->wall_y = HEIGHT - 1.0;
}

static void ft_dda(t_wolf3d *wolf3d, int map_x, int map_y)
{
    int wall;

    wall = 0;
    while (wall == 0)
    {
        // ft_printf("%d %d %d\n", map_x, map_y, wolf3d->map[map_y][map_x]);
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
}

static void ft_calculate_step(t_wolf3d *wolf3d, int map_x, int map_y)
{
    if (wolf3d->camera->ray_dir_x < 0)
    {
        wolf3d->player->step_x = -1;
        wolf3d->camera->sd_x = (wolf3d->player->start_x - map_x) * wolf3d->camera->dd_x;
    }
    else
    {
        wolf3d->player->step_x = 1;
        wolf3d->camera->sd_x = (map_x + 1 - wolf3d->player->start_x) * wolf3d->camera->dd_x;
    }
    if (wolf3d->camera->ray_dir_y < 0)
    {
        wolf3d->player->step_y = -1;
        wolf3d->camera->sd_y = (wolf3d->player->start_y - map_y) * wolf3d->camera->dd_y;
    }
    else
    {
        wolf3d->player->step_y = 1;
        wolf3d->camera->sd_y = (map_y + 1 - wolf3d->player->start_y) * wolf3d->camera->dd_y;
    }
}

static void ft_init_camera(t_wolf3d *wolf3d)
{
    wolf3d->camera->cam_x = 2 * wolf3d->x_pos / WIDTH - 1;
    wolf3d->camera->ray_dir_x = wolf3d->player->dir_x + wolf3d->player->plane_x * wolf3d->camera->cam_x;
    wolf3d->camera->ray_dir_y = wolf3d->player->dir_y + wolf3d->player->plane_y * wolf3d->camera->cam_x;
    wolf3d->camera->dd_x = fabs(1 / wolf3d->camera->ray_dir_x);
    wolf3d->camera->dd_y = fabs(1 / wolf3d->camera->ray_dir_y);
}

int ft_raycast(t_wolf3d *wolf3d)
{
    int map_x;
    int map_y;

    wolf3d->x_pos = 0;
    map_x = wolf3d->player->start_x;
    map_y = wolf3d->player->start_y;
    // ft_printf("%d %d \n", map_x, map_y);
    while (wolf3d->x_pos < WIDTH)
    {
        ft_init_camera(wolf3d);
        ft_calculate_step(wolf3d, map_x, map_y);
        ft_dda(wolf3d, map_x, map_y);
        ft_calc_wall(wolf3d, map_x, map_y);
        ft_draw(wolf3d, map_x, map_y);
    }
    mlx_put_image_to_window(wolf3d->mlx, wolf3d->win, wolf3d->image, 0, 0);
    return (0);
}