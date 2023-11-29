/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:18:08 by aperis            #+#    #+#             */
/*   Updated: 2022/10/13 18:18:11 by aperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	error_tex(t_data *data, char *str, int i)
{
	if (*str == 'N')
	{
		free_map_and_text(data, i);
	}
	if (*str == 'W')
	{
		free_map_and_text(data, i);
	}
	if (*str == 'S')
	{
		free_map_and_text(data, i);
	}
	if (*str == 'E')
	{
		free_map_and_text(data, i);
	}
}
