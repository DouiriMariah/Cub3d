/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis <aperis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 22:17:59 by aperis            #+#    #+#             */
/*   Updated: 2022/10/20 17:19:24 by aperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "Libft/libft.h"
# include "mlx/mlx.h"
# include <math.h>
# include <X11/keysym.h>

# define WIDTHSCREEN 2560	
# define HEIGHTSCREEN 1440

typedef struct s_print
{
	void	*image;
	int		*addr;
	int		img_width;
	int		img_height;
	int		bpp;
	int		line_len;
	int		endian;
}	t_print;

typedef struct s_data
{
	char			**map_tmp;
	char			**map;
	char			**mapinfo;
	char			pos;
	double			pos_x;
	double			pos_y;
	int				psx;
	int				psy;
	void			*mlx_ptr;
	void			*mlx_win;
	char			*north_path;
	char			*south_path;
	char			*west_path;
	char			*east_path;
	char			*floor_info;
	char			*ceiling_info;
	int				floor_color;
	int				ceiling_color;
	int				rgb[3];
	double			rotspeed;
	double			movespeed;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			camerax;
	double			rayposx;
	double			rayposy;
	double			olddirx;
	double			olddiry;
	double			oldplanex;
	double			oldplaney;
	double			raydirx;
	double			raydiry;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	double			sidedistx;
	double			sidedisty;
	double			step;
	double			wallx;
	double			texpos;
	int				mapx;
	int				mapy;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				rotate_right;
	int				rotate_left;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				left;
	int				right;
	int				front;
	int				back;
	int				texx;
	int				texy;
	int				texwidth;
	int				texheight;
	int				x;
	int				i;
	int				j;
	int				b;
	int				y;
	int				len;
	int				fd;
	char			*line;
	char			*str;

	void			*img;
	int				*addr;
	int				line_length;
	int				endian;
	int				bits_per_pixel;
	struct s_print	*print;
}	t_data;

void	get_color_info(t_data *data);
char	*get_color(t_data *data, char *str);
void	mix_color(t_data *data);
int		get_int_color(t_data *data);
int		get_int_color2(t_data *data);

void	draw_texture(t_data *win);
void	write_to_image(t_data *win);

int		ft_destroy(t_data *data, int j);
void	ft_destroy_image(t_data *data, int j);
void	free_path_text(t_data *data);
void	free_double_char(char **str);
void	free_map_and_text(t_data *data, int i);

void	pass_to_3d(t_data *ray);
int		check_valid_map(char **map);
int		mouse_close(t_data *data);

void	error_tex(t_data *data, char *str, int i);
int		check_directory(char **av);

int		check_char(char c, int *pos);
int		check_pos(char c, int *pos);
int		only_wall(char *map);
int		close_line(char *map);
int		check_zero(t_data *data, char **map, int i, int j);
int		end_space(char *str, int i);

void	get_map_info(t_data *data);
void	get_path_text(t_data *data);
char	*path_text(char *str, t_data *data);
void	init_path_text(t_data *data);

int		count_line(char **str);
int		close_map(t_data *data, char **map);
int		check_map(char **map);
int		parsing(t_data *data);
void	ft_check_arg(int ac, char **av);
char	**read_map(t_data *data, char **av);

void	new_window(t_data *data);
void	load_mini_image(t_data *data, int s);
void	load_image(t_data *data, int s);

void	ft_init_raycast(t_data **win);
void	init_step_and_sidedist(t_data **win);
void	init_data(t_data *win);
void	touch_wall(t_data **win);
void	find_wall(t_data **win);

void	view_left(t_data *win, double olddirx);
void	camera_rotation(t_data *win);
void	move_left_right(t_data *win);
void	back_and_forth(t_data *win);

void	init_game(t_data *g);
void	init_game2(t_data *g);
void	init_win(t_data *win);
void	init_dir(t_data *data);

void	create_image(t_data *win);
int		draw(t_data *win);

int		ft_key_press(int keycode, t_data *win);
int		ft_key_release(int keycode, t_data *win);

int		ft_strlen2(char *str);
char	*ft_strchr3(char *s, int c);
char	*ft_strjoin2(char *s1, char *s2);

char	*get_next_line(int fd);
char	*ft_get_line(char *save);
char	*ft_save(char *save);
char	*ft_read_and_save(int fd, char *save);

void	nb_text(char **map);

int		check(char *str, char *next_str);
int		only_empty(char *str, int i);
void	putstr2(char *str, int i);
int		check2(char *str, char *next_str);
int		double_check(char *str, char *next_str);
int		verif_next(char *str);
char	**skip_space(char **map);
void	read_error(int j, int fd, char *line);
char	**ft_space_info(t_data *data, char **map);
int		verif_error_line(t_data *data, char *str, int index);
int		check_line(char *str);
int		element(char c);
void	nb_coma(t_data *data, char *str);
void	check_atoi(t_data *data, int i, char *rgb);
void	space_color(t_data *data, char *str);
void	check_atoi(t_data *data, int i, char *rgb);
void	continue_2(t_data *data, int tmp, char **map, char **newmap);
int		ft_order(char **map);
void	empty_map(void);
int		open_fd(char **av);
#endif 
