/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 02:24:34 by jholl             #+#    #+#             */
/*   Updated: 2021/10/04 20:22:00 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_ber(t_data *data, char *path_ber)
{
	int		fd;
	int		gnl;
	char	*line_read;

	gnl = -1;
	line_read = NULL;
	fd = open(path_ber, O_RDONLY);
	if (fd == -1)
		exit_error(data, "Attempt to open file .ber failed.");
	while (gnl != 0)
	{
		gnl = get_next_line(fd, &line_read);
		if (gnl == -1)
			exit_error(data, "Attempt to read file .ber failed.");
		data->i = 0;
		if (gnl > 0)
			parsing(data, line_read);
		if (gnl == 0)
			free_str(line_read);
	}
	parsing_is_map_valid(data);
}

void	is_ber_valid(t_data *data, char *path_ber)
{
	int	i;

	i = 0;
	if (ft_strlen(path_ber) < 4)
		exit_error(data, "File extension need to be: \".ber\".");
	while (path_ber[i] != '\0')
		i++;
	while (path_ber[i] != '.')
	{
		i--;
		if (i < 0)
			exit_error(data, "File extension need to be: \".ber\".");
	}
	if (ft_strlen(path_ber + i) == 4)
	{
		if (path_ber[i + 1] == 'b' && path_ber[i + 2] == 'e'
			&& path_ber[i + 3] == 'r')
			read_ber(data, path_ber);
		else
			exit_error(data, "File extension need to be: \".ber\".");
	}
	else
		exit_error(data, "File extension need to be: \".ber\".");
}

void	parsing(t_data *data, char *s)
{
	if (ft_isdigit(s[data->i]))
		parsing_map(data, s);
	else if (!s[data->i])
	{
		free_str(s);
		exit_error(data, "Empty line in .ber are forbidden.");
	}
	else
		exit_error(data, "Wrong .ber elements.");
}
