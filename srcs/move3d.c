/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis <aperis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:00:00 by aperis            #+#    #+#             */
/*   Updated: 2022/10/16 14:45:00 by aperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	view_left(t_data *data, double olddirx)
{
	double	oldplanex;

	if ((data)->rotate_left == 1)
	{
		olddirx = (data)->dirx;
		oldplanex = (data)->planex;
		(data)->dirx = (data)->dirx * cos((data)->rotspeed / 2)
			- (data)->diry * sin((data)->rotspeed / 2);
		(data)->diry = olddirx * sin((data)->rotspeed / 2)
			+ (data)->diry * cos((data)->rotspeed / 2);
		(data)->planex = (data)->planex * cos((data)->rotspeed / 2)
			- (data)->planey * sin((data)->rotspeed / 2);
		(data)->planey = oldplanex * sin((data)->rotspeed / 2)
			+ (data)->planey * cos((data)->rotspeed / 2);
	}
}

void	camera_rotation(t_data *data)
{
	double	oldplanx;
	double	olddirx;

	oldplanx = (data)->planex;
	olddirx = (data)->dirx;
	if ((data)->rotate_right == 1)
	{
		(data)->dirx = (data)->dirx * cos(-(data)->rotspeed / 2)
			- (data)->diry * sin(-(data)->rotspeed / 2);
		(data)->diry = olddirx * sin(-(data)->rotspeed / 2)
			+ (data)->diry * cos(-(data)->rotspeed / 2);
		(data)->planex = (data)->planex * cos(-(data)->rotspeed / 2)
			- (data)->planey * sin(-(data)->rotspeed / 2);
		(data)->planey = oldplanx * sin(-(data)->rotspeed / 2)
			+ (data)->planey * cos(-(data)->rotspeed / 2);
	}
	view_left(data, olddirx);
}

void	move_left_right(t_data *data)
{
	if (data->right == 1)
	{
		if (data->map[(int)(data->posx + data->diry
				* (data->movespeed * 2))][(int)data->posy] == '0')
			data->posx += data->diry * data->movespeed;
		if (data->map[(int)data->posx][(int)(data->posy
			- data->dirx * (data->movespeed * 2))] == '0')
			data->posy -= data->dirx * data->movespeed;
	}
	if (data->left == 1)
	{
		if (data->map[(int)(data->posx - data->diry
				* (data->movespeed * 2))][(int)data->posy] == '0')
			data->posx -= data->diry * data->movespeed;
		if (data->map[(int)data->posx][(int)(data->posy
			+ data->dirx * (data->movespeed * 2))] == '0')
			data->posy += data->dirx * data->movespeed;
	}
}

void	back_and_forth(t_data *data)
{
	if (data->front == 1)
	{
		if (data->map[(int)(data->posx
				+ (data->dirx * data->movespeed * 2))][(int)data->posy] == '0')
			data->posx += data->dirx * data->movespeed;
		if (data->map[(int)(data->posx)][(int)(data->posy +
				(data->diry * data->movespeed * 2))] == '0')
			data->posy += data->diry * data->movespeed;
	}
	if (data->back == 1)
	{
		if (data->map[(int)(data->posx
				- (data->dirx * data->movespeed * 2))]
				[(int)(data->posy)] == '0')
			data->posx -= data->dirx * data->movespeed;
		if (data->map[(int)(data->posx)][(int)(data->posy -
					(data->diry * data->movespeed * 2))] == '0')
			data->posy -= data->diry * data->movespeed;
	}
}
