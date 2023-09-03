/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 13:17:46 by jholl             #+#    #+#             */
/*   Updated: 2021/10/04 12:51:30 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_str(char *s)
{
	if (s)
	{
		free(s);
		s = NULL;
	}
}

void	free_double_str(char **s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			if (s[i])
			{
				free(s[i]);
				s[i] = NULL;
			}
			i++;
		}
		free(s);
		s = NULL;
	}
}
