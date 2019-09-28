/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 11:16:18 by pmartyny          #+#    #+#             */
/*   Updated: 2019/09/28 11:16:19 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int ft_loop_hook(t_wolf3d *wolf3d)
{
    (void)wolf3d;
    mlx_put_image_to_window(wolf3d->mlx, wolf3d->win, wolf3d->image, 0, 0);
    return (0);
}
