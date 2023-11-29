/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 20:20:17 by mdouiri           #+#    #+#             */
/*   Updated: 2022/10/16 20:20:20 by mdouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	space_color(t_data *data, char *str)
{
	int		i;
	int		space;

	i = 0;
	space = 0;
	while (str[i])
	{
		i++;
		while (str[i] && str[i] == ' ')
			i++;
		while (str[i] && str[i] >= '0' && str[i] <= '9')
			i++;
		while (str[i] && str[i] != ',')
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				free(str);
				free(data->ceiling_info);
				free(data->floor_info);
				free_map_and_text(data, 1);
			}
			i++;
		}
	}
}

void	nb_coma(t_data *data, char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
	{
		free(str);
		free_map_and_text(data, 1);
		exit(1);
	}
}

void	check_atoi(t_data *data, int i, char *rgb)
{
	if (i == -1 || i > 256)
	{
		printf("error with the color\n");
		free(data->floor_info);
		free(data->ceiling_info);
		free_double_char(data->map);
		free_double_char(data->mapinfo);
		free_double_char(data->map_tmp);
		free(rgb);
		exit(1);
	}
}

void	continue_2(t_data *data, int tmp, char **map, char **newmap)
{
	if (tmp == 0)
	{
		while (map[data->i])
		{
			data->j = 0;
			while (map[data->i][data->j] && (map[data->i][data->j]
				== ' ' || map[data->i][data->j] == '\t'))
				data->j++;
			if (!map[data->i][data->j])
				data->i++;
			else
				break ;
		}
	}
	else
	{
		free_double_char(map);
		ft_order(newmap);
	}
}
