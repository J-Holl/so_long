/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:23:42 by jholl             #+#    #+#             */
/*   Updated: 2021/10/04 20:35:12 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	n_long;

	n_long = (long)n;
	if (n_long < 0)
	{
		ft_putchar_fd('-', fd);
		n_long *= -1;
	}
	if (n_long < 10)
	{
		ft_putchar_fd((char)(n_long + '0'), fd);
	}
	else
	{
		ft_putnbr_fd((int)(n_long / 10), fd);
		ft_putchar_fd((char)((n_long % 10) + '0'), fd);
	}
}
