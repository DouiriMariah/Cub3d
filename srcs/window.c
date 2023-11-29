/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis <aperis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:59:42 by aperis            #+#    #+#             */
/*   Updated: 2022/10/16 15:29:56 by aperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	new_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
	{
		free_path_text(data);
		free_double_char(data->mapinfo);
		free_double_char(data->map);
		free_double_char(data->map_tmp);
		printf("error : mlx_init\n");
		exit(1);
	}
	data->mlx_win = mlx_new_window(data->mlx_ptr,
			WIDTHSCREEN, HEIGHTSCREEN, "Cub3D");
	if (data->mlx_win == NULL)
	{
		free_path_text(data);
		free_double_char(data->mapinfo);
		free_double_char(data->map);
		free_double_char(data->map_tmp);
		printf("error : mlx_new_window\n");
		exit(1);
	}
	load_image(data, 30);
}

char	*name_texture(t_data *data, int i)
{
	if (i == 0)
		return (data->north_path);
	else if (i == 1)
		return (data->south_path);
	else if (i == 2)
		return (data->east_path);
	else if (i == 3)
		return (data->west_path);
	return ("");
}

void	load_image(t_data *win, int i)
{
	t_print	*img;

	i = 0;
	img = malloc(sizeof(t_print) * 4);
	while (i < 4)
	{
		img[i].image = mlx_xpm_file_to_image(win->mlx_ptr,
				name_texture(win, i), &img[i].img_width, &img[i].img_height);
		if (img[i].image == NULL)
		{
			win->print = img;
			write(2, "error\n", 6);
			while (--i >= 0)
				mlx_destroy_image(win->mlx_ptr, win->print[i].image);
			ft_destroy(win, i);
			exit(0);
		}
		img[i].addr = (int *)mlx_get_data_addr(img[i].image, &img[i].bpp,
				&img[i].line_len, &img[i].endian);
		i++;
	}
	win->print = img;
	win->texwidth = img[0].img_width;
	win->texheight = img[0].img_height;
}
