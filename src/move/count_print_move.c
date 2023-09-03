/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_print_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:57:43 by jholl             #+#    #+#             */
/*   Updated: 2021/10/04 19:24:44 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_print_move(t_data *data)
{
	data->count_move++;
	ft_putnbr_fd(data->count_move, 1);
	ft_putchar_fd('\n', 1);
}
