/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis <aperis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:58:24 by aperis            #+#    #+#             */
/*   Updated: 2022/10/16 14:50:17 by aperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	draw(t_data *data)
{
	data->x = -1;
	while (++data->x < WIDTHSCREEN)
	{
		init_data(data);
		data->camerax = 2 * data->x / (double)WIDTHSCREEN - 1;
		data->raydirx = data->dirx + data->planex * data->camerax;
		data->raydiry = data->diry + data->planey * data->camerax;
		ft_init_raycast(&data);
		init_step_and_sidedist(&data);
		data->rayposx = data->posx;
		data->rayposy = data->posy;
		data->side = 0;
		find_wall(&data);
		data->hit = 0;
		pass_to_3d(data);
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, 0, 0);
	camera_rotation(data);
	back_and_forth(data);
	move_left_right(data);
	return (0);
}

void	write_to_image(t_data *data)
{
	mlx_hook(data->mlx_win, 2, 1L << 0, ft_key_press, data);
	mlx_loop_hook(data->mlx_ptr, draw, data);
	mlx_hook(data->mlx_win, 3, 1L << 1, ft_key_release, data);
	mlx_hook(data->mlx_win, 17, 0, mouse_close, data);
	mlx_loop(data->mlx_ptr);
}
