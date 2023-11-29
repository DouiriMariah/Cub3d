/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mapinfo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis <aperis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:58:51 by aperis            #+#    #+#             */
/*   Updated: 2022/10/14 01:11:47 by aperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	condition_info(t_data *data, int i, int *count)
{
	if ((data->map_tmp[i][0] == 'N' && data->map_tmp[i][1] == 'O')
			|| (data->map_tmp[i][0] == 'S' && data->map_tmp[i][1] == 'O')
			|| (data->map_tmp[i][0] == 'E' && data->map_tmp[i][1] == 'A')
			|| (data->map_tmp[i][0] == 'W' && data->map_tmp[i][1] == 'E')
			|| data->map_tmp[i][0] == 'F' || data->map_tmp[i][0] == 'C')
		(*count)++;
	else
	{
		free_double_char(data->map_tmp);
		printf("error with the map\n");
		exit(1);
	}
}

void	get_map_info(t_data *data)
{
	int	i;
	int	count;
	int	j;

	i = -1;
	j = 0;
	count = 0;
	nb_text(data->map_tmp);
	while (data->map_tmp[++i] && count < 6)
		condition_info(data, i, &count);
	data->mapinfo = malloc(sizeof(char *) * (i + 1));
	count = 0;
	i = -1;
	while (data->map_tmp[++i] && count < 6)
	{
		data->mapinfo[i] = ft_strdup(data->map_tmp[i]);
		condition_info(data, i, &count);
	}
	data->mapinfo[i] = NULL;
	data->map = malloc(sizeof(char *) * (count_line(data->map_tmp) - i + 1));
	while (data->map_tmp[i])
		data->map[j++] = ft_strdup(data->map_tmp[i++]);
	data->map[j] = NULL;
}

char	*path_text(char *str, t_data *data)
{
	int		i;
	int		j;
	int		count;
	char	*path;

	i = 2;
	count = 2;
	j = 0;
	while (str[i])
		i++;
	path = malloc(sizeof(char) * (i + 1));
	i = 2;
	while (str[i] && str[i] != '.')
		i++;
	while (str[i] && !end_space(str, i))
	{
		if (str[i] == ' ' || str[i] == '\t')
		{
			free(path);
			error_tex(data, str, 0);
		}
		path[j++] = str[i++];
	}
	path[j] = '\0';
	return (path);
}

void	get_path_text(t_data *data)
{
	int	i;

	i = 0;
	init_path_text(data);
	get_color_info(data);
	while (data->mapinfo[i])
	{
		if (data->mapinfo[i][0] == 'N' && data->mapinfo[i][1] == 'O')
			data->north_path = path_text(data->mapinfo[i], data);
		if (data->mapinfo[i][0] == 'S' && data->mapinfo[i][1] == 'O')
			data->south_path = path_text(data->mapinfo[i], data);
		if (data->mapinfo[i][0] == 'E' && data->mapinfo[i][1] == 'A')
			data->east_path = path_text(data->mapinfo[i], data);
		if (data->mapinfo[i][0] == 'W' && data->mapinfo[i][1] == 'E')
			data->west_path = path_text(data->mapinfo[i], data);
		i++;
	}
}
