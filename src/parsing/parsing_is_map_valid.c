/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_is_map_valid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 20:41:16 by jholl             #+#    #+#             */
/*   Updated: 2021/10/07 20:56:38 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_nearby_fissure_next(t_data *data, char *s, int x_max)
{
	if (s[data->i] != '1')
	{
		if (data->x == x_max)
			return (1);
		if ((s[data->i + 1]) == '\0')
			return (1);
	}
	return (0);
}

void	at_least_one_element(t_data *data)
{
	if (!(data->coll_count && data->pos_player && data->pos_exit))
		exit_error(data, "One collectible, player, exit are needed.");
}

void	parsing_is_map_valid(t_data *data)
{
	int	x_max;

	at_least_one_element(data);
	data->x--;
	x_max = data->x;
	data->x = 0;
	while (data->x <= x_max)
	{
		data->i = 0;
		while (data->map[data->x][data->i])
		{
			if (is_nearby_fissure_next(data, data->map[data->x], x_max))
				exit_error(data, "Invalid map or no \\n at the end last line.");
			data->i++;
		}
		data->x++;
	}
}
