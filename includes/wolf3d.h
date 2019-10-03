/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 09:57:42 by pmartyny          #+#    #+#             */
/*   Updated: 2019/09/28 09:57:43 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft_printf/includes/ft_printf.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>

# define KEYUP 126
# define KEYDOWN 125
# define KEYLEFT 123
# define KEYRIGHT 124
# define MOVEUP 13
# define MOVEDOOWN 1
# define MOVELEFT 0
# define MOVERIGHT 2
# define RUN 257
# define MUSIC 46
# define WIDTH 1000
# define HEIGHT 600
# define ERROR(x) { ft_printf(x); exit(0); }
# define INT1(a,av) int a=av

typedef struct	s_texture
{
	void		**texture;
	char		**ctexture;
	int			texture_x;
	int			texture_n;
	double		wallx;
}				t_texture;

typedef struct	s_camera
{
	double		cam_x;
	double		ray_dir_x;
	double		ray_dir_y;
	double		sd_x;
	double		sd_y;
	double		dd_x;
	double		dd_y;
	double		wall_dist;
	int			wall_height;
	int			wall_x;
	int			wall_y;
	int			color;
	double		move_speed;
	double		rotate_speed;
	double		floor_x_wall;
	double		floor_y_wall;
	double		current_dist;
	double		weight;
	double		curfx;
	double		curfy;
	int			ftx;
	int			fty;
}				t_camera;

typedef struct	s_player
{
	double		start_x;
	double		start_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	int			step_x;
	int			step_y;
	char		up;
	char		down;
	char		left;
	char		right;
	char		run;
}				t_player;

typedef struct	s_wolf3d
{
	void		*mlx;
	void		*win;
	void		*image;
	int			*image_buf;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			time;
	int			old_time;
	int			**map;
	int			map_height;
	int			map_length;
	t_player	*player;
	t_camera	*camera;
	t_texture	*texture;
	int			x_pos;
	int			side;
	int			music;

}				t_wolf3d;

int				ft_check_move(int button, t_wolf3d *wolf3d);
void			ft_music(t_wolf3d *wolf3d);
void			ft_check_start(t_wolf3d *wolf3d);
int				ft_checkfile(char *file);
int				ft_check_line(char *line, int line_num, t_wolf3d *wolf3d);
int				ft_count_length(char *str);
int				ft_count_height(char *file);
void			ft_free(char **map);
void			ft_init_player(t_wolf3d *wolf3d);
void			ft_mlx_init(t_wolf3d *wolf3d);
void			ft_init_texture(t_wolf3d *wolf3d);
void			ft_init_floor_ceeling(t_wolf3d *wolf3d, int map_x, int map_y);
void			ft_draw_floor(t_wolf3d *wolf3d);
void			ft_draw_celing(t_wolf3d *wolf3d);
void			ft_draw(t_wolf3d *wolf3d, int map_x, int map_y);
void			pixel_put(t_wolf3d *wolf3d, int y, int color);
void			ft_read(char *file, t_wolf3d *wolf3d);
int				ft_loop_hook(t_wolf3d *wolf3d);
int				ft_raycast(t_wolf3d *wolf3d);
void			ft_move(t_wolf3d *wolf3d);

#endif
