/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:59:16 by jholl             #+#    #+#             */
/*   Updated: 2021/10/04 19:57:39 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_error(t_data *data, char *to_print)
{
	free_double_str(data->map);
	ft_putstr("Error.\n");
	ft_putstr(to_print);
	exit(1);
}
