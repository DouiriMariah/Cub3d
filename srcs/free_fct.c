/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis <aperis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:32:53 by aperis            #+#    #+#             */
/*   Updated: 2022/10/16 20:01:37 by aperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	free_double_char(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str && str[i])
		{
			free(str[i]);
			str[i] = NULL;
			i++;
		}
		free(str);
		str = NULL;
	}
}

void	ft_destroy_image(t_data *data, int j)
{
	int	i;

	i = -1;
	while (++i < j)
		mlx_destroy_image(data->mlx_ptr, data->print[i].image);
	mlx_destroy_image(data->mlx_ptr, data->img);
}

void	free_path_text(t_data *data)
{
	free(data->north_path);
	free(data->south_path);
	free(data->east_path);
	free(data->west_path);
}

int	ft_destroy(t_data *data, int j)
{
	if (j == 4)
		ft_destroy_image(data, j);
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

void	free_map_and_text(t_data *data, int i)
{
	free_double_char(data->mapinfo);
	free_double_char(data->map);
	free_double_char(data->map_tmp);
	if (data->north_path)
		free(data->north_path);
	if (data->south_path)
		free(data->south_path);
	if (data->west_path)
		free(data->west_path);
	if (data->east_path)
		free(data->east_path);
	if (data->floor_info && i != 0)
		free(data->floor_info);
	if (data->ceiling_info && i != 0)
		free(data->ceiling_info);
	printf("error in the map\n");
	exit(1);
}
