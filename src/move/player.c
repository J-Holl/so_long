/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 17:59:35 by jholl             #+#    #+#             */
/*   Updated: 2021/10/04 19:21:59 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_new_pos(int x, int y, t_data *data)
{
	char	to_check;

	to_check = data->map[y][x];
	if (to_check == 'C')
	{
		data->coll_count--;
	}
	if (to_check == 'E')
	{
		if (!data->coll_count)
			exit_no_error(data);
		data->there_was_exit = 1;
	}
	else
	{
		data->map[y][x] = 'P';
		data->there_was_exit = 0;
	}
}

void	player_up(t_data *data)
{
	if (data->player_y > 0)
	{
		if (data->map[data->player_y - 1][data->player_x] != '1')
		{
			count_print_move(data);
			if (data->there_was_exit)
				data->map[data->player_y][data->player_x] = 'E';
			else
				data->map[data->player_y][data->player_x] = '0';
			data->player_y--;
			check_new_pos(data->player_x, data->player_y, data);
		}
	}
}

void	player_down(t_data *data)
{
	if (data->player_y < data->y_max)
	{
		if (data->map[data->player_y + 1][data->player_x] != '1')
		{
			count_print_move(data);
			if (data->there_was_exit)
				data->map[data->player_y][data->player_x] = 'E';
			else
				data->map[data->player_y][data->player_x] = '0';
			data->player_y++;
			check_new_pos(data->player_x, data->player_y, data);
		}
	}
}

void	player_right(t_data *data)
{
	if (data->player_x < data->x_max)
	{
		if (data->map[data->player_y][data->player_x + 1] != '1')
		{
			count_print_move(data);
			if (data->there_was_exit)
				data->map[data->player_y][data->player_x] = 'E';
			else
				data->map[data->player_y][data->player_x] = '0';
			data->player_x++;
			check_new_pos(data->player_x, data->player_y, data);
		}
	}
}

void	player_left(t_data *data)
{
	if (data->player_x > 0)
	{
		if (data->map[data->player_y][data->player_x - 1] != '1')
		{
			count_print_move(data);
			if (data->there_was_exit)
				data->map[data->player_y][data->player_x] = 'E';
			else
				data->map[data->player_y][data->player_x] = '0';
			data->player_x--;
			check_new_pos(data->player_x, data->player_y, data);
		}
	}
}
