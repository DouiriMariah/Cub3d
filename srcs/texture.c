/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis <aperis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:41:43 by aperis            #+#    #+#             */
/*   Updated: 2022/10/16 13:57:06 by aperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	which_texture(t_data *data, int *side)
{
	if (data->side == 0)
	{
		if (data->raydirx > 0)
			*side = 0;
		else
			*side = 1;
	}
	else
	{
		if (data->raydiry > 0)
			*side = 2;
		else
			*side = 3;
	}
}

void	calculate_texture(t_data *data)
{
	if (data->side == 0)
		data->wallx = data->posy + data->perpwalldist * data->raydiry;
	else
		data->wallx = data->posx + data->perpwalldist * data->raydirx;
	data->wallx -= floor((data->wallx));
	data->texx = (int)(data->wallx * (double)data->texwidth);
	if ((data->side == 0 && data->raydirx > 0)
		|| (data->side == 1 && data->raydiry < 0))
		data->texx = data->texwidth - data->texx - 1;
	data->step = 1.0 * data->texheight / data->lineheight;
	data->texpos = (data->drawstart - HEIGHTSCREEN / 2
			+ data->lineheight / 2) * data->step;
}

void	display_texture(t_data *data, int y, int x, int i)
{
	data->addr[y * data->line_length / 4 + x]
		= data->print[i].addr[data->texy
		* data->print[i].line_len / 4 + data->texx];
}

void	draw_texture(t_data *data)
{
	int	i;
	int	i_tex;

	i = data->drawstart - 1;
	data->drawend = HEIGHTSCREEN - data->drawstart;
	calculate_texture(data);
	i_tex = 0;
	which_texture(data, &i_tex);
	while (++i <= data->drawend)
	{
		data->texy = (int)data->texpos & (data->texheight - 1);
		data->texpos += data->step;
		display_texture(data, i, data->x, i_tex);
	}
}

void	pass_to_3d(t_data *ray)
{
	int	j;
	int	i;

	j = -1;
	ray->drawend = HEIGHTSCREEN - ray->drawstart;
	i = ray->drawend;
	while (++j < ray->drawstart)
		ray->addr[j * ray->line_length / 4 + ray->x] = ray->ceiling_color;
	if (j <= ray->drawend)
		draw_texture(ray);
	j = i;
	while (++j < HEIGHTSCREEN)
		ray->addr[j * ray->line_length / 4 + ray->x] = ray->floor_color;
}
