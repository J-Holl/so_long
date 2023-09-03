/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 15:08:22 by jholl             #+#    #+#             */
/*   Updated: 2021/10/04 19:56:00 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	setup_hooks(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, render, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, handle_keypress, data);
	mlx_hook(data->win_ptr, ClientMessage, StructureNotifyMask, exit_red_cross,
		   	data);
	mlx_loop(data->mlx_ptr);
}

void	start(t_data *data)
{
	init_data_after_parsing(data);
	setup_hooks(data);
	mlx_destroy_image(data->mlx_ptr, data->img);
	mlx_destroy_image(data->mlx_ptr, data->exit);
	mlx_destroy_image(data->mlx_ptr, data->coll);
	mlx_destroy_image(data->mlx_ptr, data->player);
	mlx_destroy_image(data->mlx_ptr, data->wall);
	mlx_destroy_image(data->mlx_ptr, data->ground);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}

int	main(int ac, char **av)
{
	t_data	data;

	init_data(&data);
	if (ac == 2)
	{
		is_ber_valid(&data, av[1]);
		start(&data);
	}
	else
		exit_error(&data, "Need only 2 args.");
	return (0);
}
