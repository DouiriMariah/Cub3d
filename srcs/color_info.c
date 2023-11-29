/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis <aperis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:58:05 by aperis            #+#    #+#             */
/*   Updated: 2022/10/16 20:13:25 by mdouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	get_color_info(t_data *data)
{
	int	i;

	i = 0;
	while (data->mapinfo[i])
	{
		if (data->mapinfo[i][0] == 'F')
			data->floor_info = get_color(data, data->mapinfo[i]);
		if (data->mapinfo[i][0] == 'C')
			data->ceiling_info = get_color(data, data->mapinfo[i]);
		i++;
	}
	mix_color(data);
}

int	get_int_color(t_data *data)
{
	int				i;
	static int		x;
	char			*rgb;

	data->len = 0;
	data->j = 0;
	i = x;
	while (data->floor_info[i] && data->floor_info[i] != ',')
	{
		if (data->floor_info[i] >= '0' && data->floor_info[i] <= '9')
			data->len++;
		i++;
	}
	rgb = malloc(sizeof(char) * (data->len + 1));
	while (data->floor_info[x] && data->floor_info[x] != ',')
	{
		if (data->floor_info[x] >= '0' && data->floor_info[x] <= '9')
			rgb[data->j++] = data->floor_info[x];
		x++;
	}
	x++;
	rgb[data->j] = '\0';
	i = ft_atoi(rgb);
	check_atoi(data, i, rgb);
	return (free(rgb), i);
}

void	mix_color(t_data *data)
{
	char	*tmp;
	char	*temp;

	tmp = data->ceiling_info;
	temp = data->floor_info;
	data->rgb[0] = get_int_color(data);
	data->rgb[1] = get_int_color(data);
	data->rgb[2] = get_int_color(data);
	data->floor_color = data->rgb[0];
	data->floor_color = (data->floor_color << 8) + data->rgb[1];
	data->floor_color = (data->floor_color << 8) + data->rgb[2];
	data->rgb[0] = get_int_color2(data);
	data->rgb[1] = get_int_color2(data);
	data->rgb[2] = get_int_color2(data);
	data->ceiling_color = data->rgb[0];
	data->ceiling_color = (data->ceiling_color << 8) + data->rgb[1];
	data->ceiling_color = (data->ceiling_color << 8) + data->rgb[2];
	free(data->ceiling_info);
	free(data->floor_info);
}

char	*get_color(t_data *data, char *str)
{
	int		i;
	char	*floor;

	i = 1;
	data->j = 0;
	while (str[i])
		i++;
	floor = malloc(sizeof(char) * (i + 1));
	i = 1;
	while (str[i] < '0' || str[i] > '9')
		i++;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9')
			&& str[i] != ' ' && str[i] != ',' && !end_space(str, i))
		{
			free(floor);
			free_map_and_text(data, 1);
		}
		floor[data->j++] = str[i++];
	}
	floor[data->j] = '\0';
	nb_coma(data, floor);
	space_color(data, floor);
	return (floor);
}

int	get_int_color2(t_data *data)
{
	int			i;
	static int	x;
	char		*rgb;

	i = x;
	data->len = 0;
	data->j = 0;
	while (data->ceiling_info[i] && data->ceiling_info[i] != ',')
	{
		if (data->ceiling_info[i] >= '0' && data->ceiling_info[i] <= '9')
			data->len++;
		i++;
	}
	rgb = malloc(sizeof(char) * (data->len + 1));
	while (data->ceiling_info[x] && data->ceiling_info[x] != ',')
	{
		if (data->ceiling_info[x] >= '0' && data->ceiling_info[x] <= '9')
			rgb[data->j++] = data->ceiling_info[x];
		x++;
	}
	x++;
	rgb[data->j] = '\0';
	i = ft_atoi(rgb);
	check_atoi(data, i, rgb);
	return (free(rgb), i);
}
