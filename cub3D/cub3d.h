/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:47:26 by aoner             #+#    #+#             */
/*   Updated: 2023/01/04 11:38:59 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define  CUB3D_H
# define BUFFER_SIZE 100
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "mlx/mlx.h"
# include "libft/libft.h"

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

typedef struct s_map
{
	double	move_speed;
	double	rotate_speed;
	int		x;
	int		y;
	float	ang;
	char	orientation;
	double	camx;
	double	viewx;
	double	viewy;
	double	dirx;
	double	diry;
	double	px;
	double	py;
	int		mx;
	int		my;
	double	deltadist_x;
	double	deltadist_y;
	double	raydirx;
	double	raydiry;
	int		step_x;
	int		step_y;
	int		mapx;
	int		mapy;
	double	sidedist_x;
	double	sidedist_y;
	int		hit;
	int		side;
	double	wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wallx;
	double	pixel_cal;
	double	pixel_nbr;
	int		colour;
	int		key;
	int		key_w;
	int		key_a;
	int		key_s;
	int		key_d;
	int		key_r;
	int		key_b;
	int		m;
	int		key_camr;
	int		key_caml;
	double	old;
	double	old2;
	void	*ea;
	void	*no;
	void	*we;
	void	*so;
	int		*ea_data;
	int		*no_data;
	int		*we_data;
	int		*so_data;
	int		w_sixtyfour;
	int		h_sixtyfour;
}	t_map;

typedef struct s_pixel
{
	int	r;
	int	g;
	int	b;
	int	f;
}	t_pixel;

typedef struct s_image
{
	int		width;
	int		height;
	void	*img;
	int		*addr;
	int		bbp;
	int		line_len;
	int		endian;
}	t_image;

typedef struct s_data
{
	int			fd;
	char		**collect_lines;
	char		**map;
	int			last_element_line;
	int			game_start_line;
	int			game_last_line;
	int			game_line_count;
	int			tot_line_count;
	int			*column_length;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			ncount;
	int			scount;
	int			ecount;
	int			wcount;
	void		*mlx;
	void		*mlx_win;
	int			floor_color;
	int			ceil_color;
	int			floor;
	int			ceilling;
	int			x_size;
	int			y_size;
	float		look;
	t_image		screen;
	t_image		imgs[4];
	t_pixel		f;
	t_pixel		c;
	t_map		*t_map;
}	t_data;

int		main(int argc, char **argv);
void	save_cub_file(char *path, t_data *data);

//cleaner
int		clear_data(t_data *data);

//start_game
void	cam_right(t_map *map);
void	cam_left(t_map *map);

//controller;
void	exist_file_ctrl(char *path, t_data *data);
void	argc_ctrl(int argc);
void	map_name_ctrl(char **argv);
int		map_linecount_ctrl(t_data *data);

//Utils
int		is_space(int c);

//classify_the_elements
int		classify_the_elements(t_data *data);
int		classify_the_elements_inner(t_data *data, int i);

//mlx_image_setup
void	ft_image_setup(t_data *data, t_map *map);

//GNL
char	*get_next_line(int fd);
char	*ft_read_and_save(int fd, char *save);
char	*ft_save(char *save);
char	*ft_get_line(char *save);
int		has_return(char *str);
char	*ft_strjoingnl(char *s1, char const *s2);
size_t	ft_strlengnl(const char *s);

//BURAK
void	change_space_to_wall(t_data *data);
int		strlenline(char **s);
int		between_value_and_map(t_data *data);
void	column_counter(t_data *data);
int		check_map(t_data *game);
int		find_bottom_line(t_data *data);
void	delete_enter_from_map(t_data *data);
int		check_maps_column(t_data *data);
int		check_maps_inside(t_data *data);
int		check_maps_inside_utils1(t_data *data, int gap, int i, int y);
int		check_maps_inside_utils2(t_data *data, int gap, int i, int y);
int		check_maps_elements(t_data *data);
void	check_maps_elements_utils(t_data *data, int a, int b, char **map);
int		is_it_one(t_data *data);
void	setupgame(t_map *map);
void	get_pos(t_data *data, t_map *map);
void	set_values(t_map *map);
int		xbutton(t_data *data);
int		clear_arg(char **arg);
int		main_loop(t_data *data);
void	take_color_code(t_data *data);
void	print_roof(t_data *data);
void	print_ground(t_data *data);
void	print_img(t_data *data, t_map *map);
void	wallcheck(t_map *map);
void	hitcheck(t_map *map, t_data *data);
void	only_map(t_data *data);
void	get_dist(t_map *map);
void	set_image_values(t_map *map);
void	draw_image(t_map *map, t_data *data, int i);
int		move_norm(t_data *data, t_map *map);
void	move_forward_backward(t_data *data, t_map *map);
void	utils_move_forward(t_map *map, t_data *data);
int		move2(int key, t_data *data);
int		move(int key, t_data *data);
void	move_right(t_data *data, t_map *map);
void	move_left(t_data *data, t_map *map);
int		part_two(t_data *data);
int		malloc_error(t_data *data);
void	close_window(t_data *data);
int		is_it_messy_map(t_data *data);
int		cme_control(char c);

#endif