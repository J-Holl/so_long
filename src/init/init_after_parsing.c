/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_after_parsing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 17:51:10 by jholl             #+#    #+#             */
/*   Updated: 2021/10/07 21:05:05 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	textures_in_t_img(t_data *data, t_img **img, char *path)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	*img = mlx_xpm_file_to_image(data->mlx_ptr, path, &width, &height);
	if (!(*img))
		exit_error(data, "Mlx_xpm_file_to_image didn't work.");
	(*img)->width = width;
	(*img)->height = height;
}

void	init_textures(t_data *data)
{
	textures_in_t_img(data, &data->player, "./img/player.xpm");
	textures_in_t_img(data, &data->exit, "./img/exit.xpm");
	textures_in_t_img(data, &data->wall, "./img/wall.xpm");
	textures_in_t_img(data, &data->ground, "./img/ground.xpm");
	textures_in_t_img(data, &data->coll, "./img/coll.xpm");
}

void	init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		exit_error(data, "Mlx_init didn't work.");
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->width, data->height,
			"so_long");
	if (!data->win_ptr)
		exit_error(data, "Mlx_new_window didn't work.");
	data->img = mlx_new_image(data->mlx_ptr, data->width, data->height);
	if (!data->img)
		exit_error(data, "Mlx_new_image didn't work.");
	init_textures(data);
}

void	init_data_after_parsing(t_data *data)
{
	data->size_xpm = 70;
	data->y_max = data->x;
	data->x_max = ft_strlen(data->map[0]);
	data->width = data->x_max * data->size_xpm;
	data->height = data->y_max * data->size_xpm;
	data->count_move = 0;
	data->there_was_exit = 0;
	data->exit = 0;
	data->player = 0;
	data->coll = 0;
	data->wall = 0;
	data->ground = 0;
	data->img = 0;
	data->mlx_ptr = 0;
	data->win_ptr = 0;
	init_mlx(data);
}
