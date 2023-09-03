/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 02:23:52 by jholl             #+#    #+#             */
/*   Updated: 2021/10/04 19:56:29 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	realloc_map(t_data *data, char *s)
{
	int		i;
	char	**new_map;

	new_map = malloc(sizeof(char **) * (data->x + 2));
	if (!new_map)
		exit_error(data, "malloc");
	i = 0;
	if (data->x > 0)
		if (ft_strlen(data->map[data->x - 1]) != ft_strlen(s))
			exit_error(data, "not rectangular");
	while (i < data->x)
	{
		new_map[i] = data->map[i];
		i++;
	}
	new_map[i] = s;
	new_map[i + 1] = NULL;
	if (data->map)
		free(data->map);
	data->map = new_map;
	return (0);
}

int	is_valid_char(t_data *data, char *s)
{
	if (s[data->i] == 'P' && data->pos_player)
		return (0);
	if (s[data->i] == 'E' || s[data->i] == '0' || s[data->i] == '1'
		|| s[data->i] == 'C' || s[data->i] == 'P')
	{
		if (s[data->i] == 'P')
		{
			data->pos_player = 1;
			data->player_x = data->i;
			data->player_y = data->x;
		}
		if (s[data->i] == 'E')
			data->pos_exit = 1;
		if (s[data->i] == 'C')
			data->coll_count++;
		return (1);
	}
	return (0);
}

int	is_nearby_fissure(t_data *data, char *s)
{
	if (s[data->i] != '1')
	{
		if ((data->x - 1) < 0)
			return (1);
		if ((data->i - 1) < 0)
			return (1);
		if ((s[data->i + 1]) == '\0')
			return (1);
	}
	return (0);
}

void	parsing_map(t_data *data, char *s)
{
	int	len_prev_str;
	int	len_str;

	if (data->x > 0)
	{
		len_prev_str = ft_strlen(data->map[data->x - 1]);
		len_str = ft_strlen(s);
		if (len_prev_str != len_str)
		{
			free(s);
			exit_error(data, "not rectangular");
		}
	}
	realloc_map(data, s);
	while (s[data->i])
	{
		if (!is_valid_char(data, s))
			exit_error(data, "not a valid map.");
		if (is_nearby_fissure(data, s))
			exit_error(data, "map must be surronded by walls.");
		data->i++;
	}
	data->x++;
}
