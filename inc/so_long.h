/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:20:35 by jholl             #+#    #+#             */
/*   Updated: 2021/10/07 21:04:36 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 250
# include "../minilibx_linux/mlx.h"
# include "../minilibx_linux/mlx_int.h"
# include <math.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdint.h>

typedef struct s_data
{
	int		i;
	int		x;
	char	**map;
	int		parsing_finish;
	int		count_move;
	int		pos_player;
	int		player_x;
	int		player_y;
	int		pos_exit;
	int		y_max;
	int		x_max;
	int		width;
	int		height;
	int		size_xpm;
	int		there_was_exit;
	int		coll_count;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	*img;
	t_img	*exit;
	t_img	*player;
	t_img	*coll;
	t_img	*wall;
	t_img	*ground;
}				t_data;

// exit
void	exit_no_error(t_data *data);
int		exit_red_cross(t_data *data);
void	exit_error(t_data *data, char *to_print);
void	free_double_str(char **s);
void	free_str(char *s);

// init
void	init_data(t_data *data);
void	init_data_after_parsing(t_data *data);
void	init_mlx(t_data *data);
void	init_textures(t_data *data);
void	textures_in_t_img(t_data *data, t_img **img, char *path);

// global-utils
void	ft_putstr(char *s);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);

//gnl
size_t	ft_strlen(const char *s);
int		str_free(char *s);
int		get_next_line(int fd, char **line);
char	*ft_strjoin_free(char *s1, char *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *s);

//parsing
void	parsing(t_data *data, char *s);
void	parsing_map(t_data *data, char *s);
void	parsing_is_map_valid(t_data *data);
void	is_ber_valid(t_data *data, char *path_cub);
void	read_ber(t_data *data, char *path_cub);

//move
void	player_right(t_data *data);
void	player_left(t_data *data);
void	player_down(t_data *data);
void	player_up(t_data *data);
void	check_new_pos(int x, int y, t_data *data);
int		handle_keypress(int keysim, t_data *data);
void	update(t_data *data);
void	count_print_move(t_data *data);

//render
int		render(t_data *data);
int		get_color_from_texture(t_img *img, int x, int y);
int		encode_rgb(uint8_t red, uint8_t green, uint8_t blue);
void	print_pixel_at(int x, int y, int color, t_img *img);

#endif
