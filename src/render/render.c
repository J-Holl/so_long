/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:42:32 by jholl             #+#    #+#             */
/*   Updated: 2021/10/07 21:04:07 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_xpm_at(int x, int y, t_img *img, t_data *data)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	x *= data->size_xpm;
	y *= data->size_xpm;
	while (i < data->size_xpm)
	{
		j = 0;
		while (j < data->size_xpm)
		{
			color = get_color_from_texture(img, j, i);
			if (color != encode_rgb(255, 255, 255))
				print_pixel_at(j + x, i + y, color, data->img);
			j++;
		}
		i++;
	}
}

void	parsing_sprite(int x, int y, t_data *data)
{
	if (data->map[y][x] == 'E')
		print_xpm_at(x, y, data->exit, data);
	if (data->map[y][x] == 'E' && y == data->player_y && x == data->player_x)
		print_xpm_at(x, y, data->player, data);
	if (data->map[y][x] == 'C')
		print_xpm_at(x, y, data->coll, data);
	if (data->map[y][x] == 'P')
		print_xpm_at(x, y, data->player, data);
}

void	render_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
				print_xpm_at(j, i, data->wall, data);
			else
				print_xpm_at(j, i, data->ground, data);
			parsing_sprite(j, i, data);
			j++;
		}
		i++;
	}
}

int	render(t_data *data)
{
	if (!data->win_ptr)
		return (1);
	else
	{
		render_map(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	}
	return (0);
}
