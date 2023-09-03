/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 15:23:02 by jholl             #+#    #+#             */
/*   Updated: 2021/10/04 12:53:12 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_color_from_texture(t_img *img, int x, int y)
{
	return (*(int *)(img->data + (y * img->size_line + x * (img->bpp / 8))));
}

int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}

void	print_pixel_at(int x, int y, int color, t_img *img)
{
	char	*pixel;

	pixel = img->data + (y * img->size_line + x * (img->bpp / 8));
	*(int *)pixel = color;
}
