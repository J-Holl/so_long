/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:20:59 by jholl             #+#    #+#             */
/*   Updated: 2021/10/03 15:31:19 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_data(t_data *data)
{
	data->i = 0;
	data->x = 0;
	data->parsing_finish = 0;
	data->pos_player = 0;
	data->player_x = 0;
	data->player_y = 0;
	data->pos_exit = 0;
	data->coll_count = 0;
	data->map = NULL;
}
