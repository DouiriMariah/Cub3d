/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis <aperis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:59:06 by aperis            #+#    #+#             */
/*   Updated: 2022/10/16 20:02:34 by aperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	ft_key_press(int keycode, t_data *win)
{
	if (keycode == 100)
		win->right = 1;
	else if (keycode == 97)
		win->left = 1;
	else if (keycode == 119)
		win->front = 1;
	else if (keycode == 115)
		win->back = 1;
	else if (keycode == 65361)
		win->rotate_left = 1;
	else if (keycode == 65363)
		win->rotate_right = 1;
	else if (keycode == 65307)
		ft_destroy(win, 4);
	return (1);
}

int	ft_key_release(int keycode, t_data *win)
{
	if (keycode == 100)
		win->right = 0;
	else if (keycode == 97)
		win->left = 0;
	else if (keycode == 119)
		win->front = 0;
	else if (keycode == 115)
		win->back = 0;
	else if (keycode == 65361)
		win->rotate_left = 0;
	else if (keycode == 65363)
		win->rotate_right = 0;
	else if (keycode == 65307)
		ft_destroy(win, 4);
	return (1);
}

int	mouse_close(t_data *data)
{
	ft_destroy_image(data, 4);
	free_path_text(data);
	free_double_char(data->mapinfo);
	free_double_char(data->map);
	free_double_char(data->map_tmp);
	free(data->print);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}
