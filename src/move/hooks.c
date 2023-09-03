/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:09:41 by jholl             #+#    #+#             */
/*   Updated: 2021/10/07 21:04:25 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keysim, t_data *data)
{
	if (keysim == XK_w || keysim == XK_W)
		player_up(data);
	if (keysim == XK_s || keysim == XK_S)
		player_down(data);
	if (keysim == XK_a || keysim == XK_A)
		player_left(data);
	if (keysim == XK_d || keysim == XK_D)
		player_right(data);
	if (keysim == XK_Escape)
		exit_no_error(data);
	return (0);
}
